#pragma once
#include "Primitive.h"

//’¸“_‚ğ‚Â‚¾‚¯
class Triangle final : public Primitive
{
public:
	Triangle();
	virtual ~Triangle() {};

	virtual bool HitJudge(shared_ptr<GameObject> target) override;

private:
	const VECTOR_D vertexArray[3] = { {0, -0.58}, {0.5, 0.29}, {-0.5, 0.29} };//’¸“_
};

