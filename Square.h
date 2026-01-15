#pragma once
#include "Primitive.h"

//’¸“_‚ğ‚Â‚¾‚¯
class Square final : public Primitive
{
public:
	Square();
	virtual ~Square() {};

private:
	const VECTOR_D vertexArray[4] = { {-0.5, -0.5}, {0.5, -0.5}, {0.5, 0.5}, {-0.5, 0.5} };//’¸“_
};

