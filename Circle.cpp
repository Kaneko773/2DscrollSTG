#include "Circle.h"
#include <math.h>

#include "Triangle.h"
#include "Square.h"

Circle::Circle()
{
	radius = 0.5;
	draw_radius = 0;

	drawPoint_size = 2;
	drawPoint = new VECTOR_D[drawPoint_size];

	vertex = new VECTOR_D[drawPoint_size];
	vertex[0] = { 0, 0 };//中心を頂点として扱う
	vertex[1] = { radius, 0 };//円上の1点
}

bool Circle::HitJudge(shared_ptr<GameObject> target)
{
	shared_ptr<Circle> c = dynamic_pointer_cast<Circle>(target);
	if (c != nullptr) {
		if (HitCheck_Sphere_SphereD(drawPoint[0], draw_radius, c->Get_drawPoint(0), c->Get_draw_radius())) return true;
	}
	shared_ptr<Triangle> t = dynamic_pointer_cast<Triangle>(target);
	if (t != nullptr) {
		if (HitCheck_Sphere_TriangleD(drawPoint[0], draw_radius, t->Get_drawPoint(0), t->Get_drawPoint(1), t->Get_drawPoint(2))) return true;
	}
	shared_ptr<Square> s = dynamic_pointer_cast<Square>(target);
	if (s != nullptr) {
		if (HitCheck_Sphere_TriangleD(drawPoint[0], draw_radius, s->Get_drawPoint(0), s->Get_drawPoint(1), s->Get_drawPoint(2))) return true;
		if (HitCheck_Sphere_TriangleD(drawPoint[0], draw_radius, s->Get_drawPoint(0), s->Get_drawPoint(3), s->Get_drawPoint(2))) return true;
	}

	for (int i = 0; i < children.size(); ++i) {
		if (children[i]->HitJudge(target)) {//何か１つでも当たれば残りは判定しない
			return true;
		}
	}

	return false;
}

void Circle::Update()
{
	Update_drawPoint();

	draw_radius = sqrt(pow(drawPoint[0].x - drawPoint[1].x, 2) + pow(drawPoint[0].y - drawPoint[1].y, 2));

	for (int i = 0; i < children.size(); ++i) {
		children[i]->Update();
	}
}

void Circle::Show() const
{
	//自身
	DrawCircle((int)drawPoint->x, (int)drawPoint->y, (int)draw_radius, GetColor(255, 255, 255), TRUE);
	//子供
	for (int i = 0; i < children.size(); ++i) {
		children[i]->Show();
	}
}