#pragma once
#include "DxLib.h"

class Explosion_Animation
{
public:
	Explosion_Animation();
	virtual ~Explosion_Animation();

	void Explosion_Start(float _size);
	bool Explosion_Update();//falseÇ™ï‘Ç¡ÇΩÇÁèIóπ
	void Show(VECTOR_D drawPos) const;

	bool Get_Exploding() const {
		return exploding;
	}

private:
	int ExplosionGraph;
	int explosion_handle[9];

	float size;

	bool exploding;
	double timer;
	double prevTime;
	const double interval = 0.05;
	int nowExplosionHandleNum;
};

