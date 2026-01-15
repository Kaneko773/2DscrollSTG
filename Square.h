#pragma once
#include "Primitive.h"

//’¸“_‚ğ‚Â‚¾‚¯
class Square final : public Primitive
{
public:
	Square();
	virtual ~Square() {};

	virtual bool HitJudge(shared_ptr<GameObject> target) override;

private:
	const VECTOR_D vertexArray[4] = { {-0.5, -0.5}, {0.5, -0.5}, {0.5, 0.5}, {-0.5, 0.5} };//’¸“_
};

