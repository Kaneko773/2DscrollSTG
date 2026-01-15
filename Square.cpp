#include "Square.h"

Square::Square()
{
	drawPoint_size = 4;
	drawPoint = new VECTOR_D[drawPoint_size];

	vertex = new VECTOR_D[drawPoint_size];
	for (int i = 0; i < drawPoint_size; ++i) {
		vertex[i] = vertexArray[i];
	}
}