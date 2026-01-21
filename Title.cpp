#include "Title.h"
#include "DxLib.h"
#include "InputManager.h"
//‘JˆÚæ
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
	DrawString(250, 240 - 32, "Title", GetColor(255, 255, 255));
	DrawString(250, 240 - 32 + 20, "Enter : Load", GetColor(255, 255, 255));
}