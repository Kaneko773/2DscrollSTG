#pragma once
#include "Circle.h"

#include <memory>//shared_ptr

class Bullet : public Circle
{
public:
	Bullet();
	virtual ~Bullet() {};

	void Update(vector<shared_ptr<GameObject>>* gameObjects) override;

	void Set_dir(double _dir) {
		dir = _dir;
	}

private:
	double dir;
};

