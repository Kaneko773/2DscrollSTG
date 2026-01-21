#include "Title.h"
#include "DxLib.h"
#include "InputManager.h"
//遷移先
#include "GameRoot.h"

NextScene* Title::Update()
{
	if (InputManager::getInstance()->input_keyDown[KEY_INPUT_RETURN]) {
		NextScene* nextScene = new GameRoot();
		nextScene->Transition_Start(this);
		return nextScene;
	}

	return this;

}
void Title::Draw()
{
	DrawString(10, 10, "Escapeでゲーム終了", GetColor(255, 255, 255));

	DrawString(250, 240 - 32, "タイトル画面", GetColor(255, 255, 255));
	DrawString(250, 240 - 32 + 20, "Enter : ステージ選択", GetColor(255, 255, 255));
}