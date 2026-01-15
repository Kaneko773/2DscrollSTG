#include "Triangle.h"

Triangle::Triangle()
{
	drawPoint_size = 3;
	drawPoint = new VECTOR_D[drawPoint_size];

	vertex = new VECTOR_D[drawPoint_size];
	for (int i = 0; i < drawPoint_size; ++i) {
		vertex[i] = vertexArray[i];
	}
}