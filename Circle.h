#pragma once
#include "Primitive.h"

//”¼Œa‚ğ‚Â‚¾‚¯
class Circle : public Primitive
{
public:
	Circle();
	virtual ~Circle() {};

	virtual bool HitJudge(shared_ptr<GameObject> target) override;

	virtual void Update() override;
	virtual void Show() const override;

	double Get_draw_radius() const {
		return draw_radius;
	}

private:
	double radius;

	double draw_radius;//•`‰æ‚·‚é‰~‚Ì”¼Œai“–‚½‚è”»’è‚Å‚àg‚¤j
};

