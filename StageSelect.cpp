#include "StageSelect.h"
#include "DxLib.h"
#include "InputManager.h"
//遷移先
#include "Title.h"
#include "Stage1.h"

NextScene* StageSelect::Update()
{
	if (InputManager::getInstance()->input_keyDown[KEY_INPUT_B]) {
		NextScene* nextScene = new Title();
		nextScene->Transition_Start(this);
		return nextScene;
	}
	if (InputManager::getInstance()->input_keyDown[KEY_INPUT_1]) {
		NextScene* nextScene = new Stage1();
		nextScene->Transition_Start(this);
		return nextScene;
	}

	return this;
}
void StageSelect::Draw()
{
	DrawString(250, 240 - 32, "StageSelect", GetColor(255, 255, 255));
	DrawString(250, 240 - 32 + 20, "  B   : Title", GetColor(255, 255, 255));
	DrawString(250, 240 - 32 + 40, "1キー : ステージ１ ", GetColor(255, 255, 255));
}

void StageSelect::AAA() {
	printfDx("StageSelect");
}