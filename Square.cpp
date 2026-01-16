#include "Square.h"

#include "Circle.h"
#include "Triangle.h"

Square::Square()
{
	drawPoint_size = 4;
	drawPoint = new VECTOR_D[drawPoint_size];

	vertex = new VECTOR_D[drawPoint_size];
	for (int i = 0; i < drawPoint_size; ++i) {
		vertex[i] = vertexArray[i];
	}
}

bool Square::HitJudge(shared_ptr<GameObject> target)
{
	vector<shared_ptr<GameObject>> targets;
	targets.push_back(target);
	target->Summarize(&targets);//‚±‚±‚ª“ü‚Á‚Ä‚È‚¢

	for (int i = 0; i < targets.size(); ++i) {
		shared_ptr<Circle> c = dynamic_pointer_cast<Circle>(targets[i]);
		if (c != nullptr) {
			if (HitCheck_Sphere_TriangleD(c->Get_drawPoint(0), c->Get_draw_radius(), drawPoint[0], drawPoint[1], drawPoint[2])) return true;
			if (HitCheck_Sphere_TriangleD(c->Get_drawPoint(0), c->Get_draw_radius(), drawPoint[0], drawPoint[3], drawPoint[2])) return true;
		}
		shared_ptr<Triangle> t = dynamic_pointer_cast<Triangle>(targets[i]);
		if (t != nullptr) {
			if (HitCheck_Triangle_TriangleD_2D(drawPoint[0], drawPoint[1], drawPoint[2], t->Get_drawPoint(0), t->Get_drawPoint(1), t->Get_drawPoint(2))) return true;
			if (HitCheck_Triangle_TriangleD_2D(drawPoint[0], drawPoint[3], drawPoint[2], t->Get_drawPoint(0), t->Get_drawPoint(1), t->Get_drawPoint(2))) return true;
		}
		shared_ptr<Square> s = dynamic_pointer_cast<Square>(targets[i]);
		if (s != nullptr) {
			if (HitCheck_Triangle_TriangleD_2D(drawPoint[0], drawPoint[1], drawPoint[2], s->Get_drawPoint(0), s->Get_drawPoint(1), s->Get_drawPoint(2))) return true;
			if (HitCheck_Triangle_TriangleD_2D(drawPoint[0], drawPoint[1], drawPoint[2], s->Get_drawPoint(0), s->Get_drawPoint(3), s->Get_drawPoint(2))) return true;
			if (HitCheck_Triangle_TriangleD_2D(drawPoint[0], drawPoint[3], drawPoint[2], s->Get_drawPoint(0), s->Get_drawPoint(1), s->Get_drawPoint(2))) return true;
			if (HitCheck_Triangle_TriangleD_2D(drawPoint[0], drawPoint[3], drawPoint[2], s->Get_drawPoint(0), s->Get_drawPoint(3), s->Get_drawPoint(2))) return true;
		}
	}

	for (int i = 0; i < children.size(); ++i) {
		if (children[i]->HitJudge(target)) {//‰½‚©‚P‚Â‚Å‚à“–‚½‚ê‚ÎŽc‚è‚Í”»’è‚µ‚È‚¢
			return true;
		}
	}

	return false;
}