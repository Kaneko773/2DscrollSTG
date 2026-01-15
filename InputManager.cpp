#include "InputManager.h"
#include "DxLib.h"

InputManager::InputManager() {
	for (int i = 0; i < KEY_CNT; ++i)
	{
		keybuf[i] = 0;
		keybuf_old[i] = 0;
		input_keyDown[i] = 0;
		input_keyUp[i] = 0;
		input_key[i] = 0;
		input_keyFewSec[i] = 0;
		input_keyFewSec_time[i] = 1.0f;

		nowTime[i] = GetNowHiPerformanceCount();
		prevTime[i] = nowTime[i];
	}
}

InputManager* InputManager::pInstance = nullptr;// 唯一のインスタンス
InputManager* InputManager::getInstance()
{
	if (pInstance == nullptr)
	{
		pInstance = new InputManager();
	}
	return pInstance;
}
void InputManager::create()
{
	if (pInstance == nullptr)
	{
		pInstance = new InputManager();
	}
}
void InputManager::destroy()
{
	if (pInstance != nullptr)
	{
		delete pInstance;
		pInstance = nullptr;
	}
}


void InputManager::Update_Key()
{
	//現フレームの状態を取得
	GetHitKeyStateAll(keybuf);

	for (int i = 0; i < KEY_CNT; ++i)
	{
		char key_xor = keybuf[i] ^ keybuf_old[i];//前後入力無し、前後入力有 → 0 , 前後どちらかだけ入力 → 1
		//押した瞬間
		input_keyDown[i] = key_xor & keybuf[i];// key_xor が 1 の時 true
		//離した瞬間
		input_keyUp[i] = key_xor & keybuf_old[i];//key_xor が 1 の時 true
		//押し続けているか
		input_key[i] = keybuf[i] & keybuf_old[i];//前後が 1 なら true

		nowTime[i] = GetNowHiPerformanceCount();
		if (input_keyDown[i]) prevTime[i] = nowTime[i];//入力された瞬間に prevTime リセット
		if (input_key[i] && (nowTime[i] - prevTime[i]) / 1000000.0f > input_keyFewSec_time[i]/*指定秒*/) {//連続入力されてる && 指定秒経過してたら true
			input_keyFewSec[i] = 1;
			prevTime[i] = nowTime[i];
		}
		else {
			input_keyFewSec[i] = 0;
		}
	}

	//現フレームのバッファを前フレームのバッファへ
	for (int i = 0; i < KEY_CNT; ++i)
	{
		keybuf_old[i] = keybuf[i];
	}
}

void InputManager::Set_input_keyFewSec_time(int key_code, float time)
{
	if (key_code < 0 || KEY_CNT <= key_code) return; //アウト
	if (time <= 0) return; //アウト

	input_keyFewSec_time[key_code] = time;
}
