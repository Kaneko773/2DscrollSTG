#include "DxLib.h"
#include "InputManager.h"
#include "FrameRateManager.h"

#include "Title.h"//最初に呼ぶシーン
#include "GameRoot.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(640, 480, 32);
	ChangeWindowMode(TRUE);
	SetWaitVSyncFlag(FALSE);
	if (DxLib_Init() == -1) return -1;

	CreateMaskScreen();//マスクスクリーンを作る
	SetDrawScreen(DX_SCREEN_BACK);//裏画面に描画

	InputManager::create();
	FrameRateManager::create();

	//SceneBase* currentScene = new Title();
	SceneBase* currentScene = new GameRoot();
	currentScene->Start();

	while (ProcessMessage() == 0)
	{
		clsDx();//文字列クリア
		ClearDrawScreen();//描画画面クリア
		InputManager::getInstance()->Update_Key();
		FrameRateManager::getInstance()->FrameRateUpdate();
		
		SceneBase* nextScene = currentScene->Update();
		currentScene->Draw();

		//この階層のトランジション処理
		currentScene->Transition_Update();
		currentScene->Transition_Draw();

		if (nextScene != currentScene) {
			currentScene->End();
			delete currentScene;

			currentScene = nextScene;
			currentScene->Start();
		}

		ScreenFlip();//表示

		//ゲーム終了(デバッグ)
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;
	}

	if (currentScene) {
		delete currentScene;
		currentScene = nullptr;
	}

	InputManager::destroy();
	FrameRateManager::destroy();
	DeleteMaskScreen();//マスクスクリーンの片付け
	DxLib_End();

	return 0;				// ソフトの終了 
}