#include "Circle.h"
#include <math.h>

Circle::Circle()
{
	radius = 0.5;

	drawPoint_size = 2;
	drawPoint = new VECTOR_D[drawPoint_size];

	vertex = new VECTOR_D[drawPoint_size];
	vertex[0] = { 0, 0 };//中心を頂点として扱う
	vertex[1] = { radius, 0 };//円上の1点
}

void Circle::Show() const
{
	//自身
	double draw_radius = sqrt(pow(drawPoint[0].x - drawPoint[1].x, 2) + pow(drawPoint[0].y - drawPoint[1].y, 2));
	DrawCircle((int)drawPoint->x, (int)drawPoint->y, (int)draw_radius, GetColor(255, 255, 255), TRUE);
	//子供
	for (int i = 0; i < children.size(); ++i) {
		children[i]->Show();
	}
}