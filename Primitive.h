#pragma once
#include "GameObject.h"

class Primitive : public GameObject
{
public:
	Primitive();
	virtual ~Primitive();

	virtual void Update(vector<shared_ptr<GameObject>>* gameObjects) override;
	virtual void Show() const override;

	void Set_local_vec(VECTOR_D tr, VECTOR_D rt, VECTOR_D sc);//デバッグ用

	void Test_Check_VEC_Update();//デバッグ用　体のパーツを動かすため

	virtual bool HitJudge(shared_ptr<GameObject> target) = 0;

	VECTOR_D Get_drawPoint(int i) const {
		if (i < 0 || drawPoint_size <= i)return drawPoint[0];//エラー処理したい
		return drawPoint[i];
	}

protected:
	void Update_drawPoint();

protected:
	VECTOR_D* vertex;
	VECTOR_D* drawPoint;
	int drawPoint_size;
};

