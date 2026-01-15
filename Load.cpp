#include "Load.h"
#include "DxLib.h"
#include "InputManager.h"
//‘JˆÚæ
#include "Title.h"
#include "Stage1.h"

NextScene* Load::Update()
{
	if (InputManager::getInstance()->input_keyDown[KEY_INPUT_B]) {
		NextScene* nextScene = new Title();
		nextScene->Transition_Start(this);
		return nextScene;
	}
	if (InputManager::getInstance()->input_keyDown[KEY_INPUT_RETURN]) {
		NextScene* nextScene = new Stage1();
		nextScene->Transition_Start(this);
		return nextScene;
	}

	return this;
}
void Load::Draw()
{
	DrawString(250, 240 - 32, "Loading", GetColor(255, 255, 255));
	DrawString(250, 240 - 32 + 20, "  B   : Title", GetColor(255, 255, 255));
}

void Load::AAA() {
	printfDx("Load");
}