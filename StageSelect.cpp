#include "StageSelect.h"
#include "DxLib.h"
#include "InputManager.h"
//‘JˆÚæ
#include "Title.h"
#include "Load.h"

NextScene* StageSelect::Update()
{
	if (InputManager::getInstance()->input_keyDown[KEY_INPUT_B]) {
		NextScene* nextScene = new Title();
		nextScene->Transition_Start(this);
		return nextScene;
	}
	if (InputManager::getInstance()->input_keyDown[KEY_INPUT_RETURN]) {
		NextScene* nextScene = new Load();
		nextScene->Transition_Start(this);
		return nextScene;
	}

	return this;
}
void StageSelect::Draw()
{
	DrawString(250, 240 - 32, "StageSelect", GetColor(255, 255, 255));
	DrawString(250, 240 - 32 + 20, "  B   : Title", GetColor(255, 255, 255));
	DrawString(250, 240 - 32 + 40, "Enter : Load ", GetColor(255, 255, 255));
}

void StageSelect::AAA() {
	printfDx("StageSelect");
}