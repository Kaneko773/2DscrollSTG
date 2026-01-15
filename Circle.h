#pragma once
#include "Primitive.h"

//”¼Œa‚ğ‚Â‚¾‚¯
class Circle : public Primitive
{
public:
	Circle();
	virtual ~Circle() {};

	virtual void Show() const override;

private:
	double radius;
};

