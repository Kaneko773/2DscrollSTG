#pragma once
#include "GameObject.h"

class Primitive : public GameObject
{
public:
	Primitive();
	virtual ~Primitive();

	virtual void Update() override;
	virtual void Show() const override;

	void Set_local_vec(VECTOR_D tr, VECTOR_D rt, VECTOR_D sc);

	void Test_Original_Update();

	virtual bool HitJudge(shared_ptr<GameObject> target) = 0;

	VECTOR_D Get_drawPoint(int i) {
		return drawPoint[i];
	}

protected:
	void Update_drawPoint();

protected:
	VECTOR_D* vertex;
	VECTOR_D* drawPoint;
	int drawPoint_size;
};

