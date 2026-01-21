#include "Transition.h"
#include "FrameRateManager.h"
#include "DxLib.h"
#include "SceneBase.h"

Transition::Transition()
{
	maskScreen = 0;
	maskHandle = 0;
	inTransition = false;

	transitionTimer = 0;
	transitionCount = 0;

	maskScreen = MakeScreen(640, 480, FALSE);//グラフィックを作成
	maskHandle = MakeMask(16, 16);
}

Transition::~Transition()
{
	if (maskScreen != 0) DeleteGraph(maskScreen);
}

void Transition::Transition_Start(SceneBase* prevScene)
{
	SetDrawScreen(maskScreen);//作ったグラフィックを描画先にする
	ClearDrawScreen();
	prevScene->Draw();//遷移前の画面を描画
	SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に戻す
	inTransition = true;

	// マスクデータを黒で埋める
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 16; j++)
			MaskData[i][j] = 0;//0(黒):描画される 0xff(白):描画されない

	transitionTimer = 0;
	transitionCount = 0;
}

void Transition::Transition_Update()
{
	if (!inTransition) return;

	transitionTimer += FrameRateManager::getInstance()->Get_Deltatime();
	if (transitionTimer >= TransitionTime / 48.0f * transitionCount) {
		if (transitionCount >= 47) {
			inTransition = false;
			return;
		}

		if (transitionCount % 3 == 0) {
			for (int i = transitionCount / 3; i < (transitionCount / 3) + 1; i++) {
				for (int j = 0; j < 16; j++) {
					MaskData[i][j] = 0xff;//0(黒):描画される 0xff(白):描画されない
				}
			}
		}

		++transitionCount;
	}

	// マスクにデータをセット
	SetDataToMask(16, 16, MaskData, maskHandle);
	// マスク画面にマスクデータをセット
	DrawFillMask(0, 0, 640, 480, maskHandle);
}

void Transition::Transition_Draw() const {
	if (!inTransition) return;

	SetUseMaskScreenFlag(TRUE);//マスク有効
	DrawGraph(0, 0, maskScreen, FALSE);
	SetUseMaskScreenFlag(FALSE);//マスク無効
}