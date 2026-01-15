#pragma once

#define KEY_CNT 256

typedef long long LONGLONG;

class InputManager
{
public:
	void Update_Key();

	char input_keyDown[KEY_CNT];		//押された瞬間
	char input_keyUp[KEY_CNT];			//離された瞬間
	char input_key[KEY_CNT];			//押し続けているか
	char input_keyFewSec[KEY_CNT];		//押し続けているとき、指定秒が経過するごとに発火
	
	void Set_input_keyFewSec_time(int key_code, float time);//各キー連続入力の指定秒を設定

private:
	static InputManager* pInstance;

	char keybuf[KEY_CNT];		//キーバッファ (現フレーム)
	char keybuf_old[KEY_CNT];   //1つ前のキーバッファ(前フレーム) 

	float input_keyFewSec_time[KEY_CNT];//各キー連続入力の指定秒　デフォルトは１秒
	LONGLONG nowTime[KEY_CNT];
	LONGLONG prevTime[KEY_CNT];



private:
	InputManager();
	virtual ~InputManager() {};

	InputManager(const InputManager&) = delete;
	void operator=(const InputManager&) = delete;

public:
	static InputManager* getInstance();
	static void create();
	static void destroy();
};