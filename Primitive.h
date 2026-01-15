#pragma once
#include "GameObject.h"

class Primitive : public GameObject
{
public:
	Primitive();
	virtual ~Primitive();

	void Update() override;
	virtual void Show() const override;

	void Set_local_vec(VECTOR_D tr, VECTOR_D rt, VECTOR_D sc);

	void Test_Original_Update();

protected:
	void Update_drawPoint();

protected:
	VECTOR_D* vertex;
	VECTOR_D* drawPoint;
	int drawPoint_size;
};

