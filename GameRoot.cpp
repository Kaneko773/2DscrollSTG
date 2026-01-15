#include "GameRoot.h"
#include "DxLib.h"

#include "GameScene.h"//ŠK‘w”»’è‚ÉŽg‚¤

#include "StageSelect.h"//Å‰‚É“Ç‚Ýž‚ÞƒV[ƒ“
//ƒfƒoƒbƒO
#include "Stage1.h"

GameRoot::GameRoot()
{
	currentScene = new Stage1();
}
GameRoot::~GameRoot()
{
	if (currentScene) {
		delete currentScene;
		currentScene = nullptr;
	}
}

void GameRoot::Start()
{

}
void GameRoot::End()
{

}
NextScene* GameRoot::Update()
{
	NextScene* nextScene = currentScene->Update();
	currentScene->Draw();

	//‚±‚ÌŠK‘w‚Ìƒgƒ‰ƒ“ƒWƒVƒ‡ƒ“ˆ—
	currentScene->Transition_Update();
	currentScene->Transition_Draw();

	if (nextScene != currentScene) {

		GameScene* hierarchyJudgment = dynamic_cast<GameScene*>(nextScene);

		//ˆá‚¤ŠK‘w‚È‚çã‚Åˆ—‚µ‚Ä‚à‚ç‚¤
		if (hierarchyJudgment == nullptr) {
			return nextScene;
		}

		//“¯‚¶ŠK‘w‚È‚ç‚±‚Á‚¿‚Åˆ—
		currentScene->End();
		delete currentScene;

		currentScene = nextScene;
		nextScene->Start();
	}

	return this;
}
void GameRoot::Draw()
{
	//•`‰æ–³‚µ
}

void GameRoot::Transition_Start(SceneBase* prevScene)
{
	//GameRoot‚ªƒgƒ‰ƒ“ƒWƒVƒ‡ƒ“‚µ‚È‚¢‚æ‚¤‚É‚·‚é
	currentScene->Transition_Start(prevScene);
}

void GameRoot::AAA() {
	printfDx("GameRoot");
}