#pragma once

class SceneBase;

class Transition
{
public:
	Transition();
	virtual ~Transition();

	virtual void Transition_Start(SceneBase* prevScene);//仲介役はこれをオーバーライド

	void Transition_Update();
	void Transition_Draw() const;

	bool Get_inTransition() const {
		return inTransition;
	}

private:
	int maskScreen;//マスク画面
	int maskHandle;//マスク画
	bool inTransition;
	unsigned char MaskData[16][16];

	const float TransitionTime = 1.0f;
	float transitionTimer;
	int transitionCount;
};

