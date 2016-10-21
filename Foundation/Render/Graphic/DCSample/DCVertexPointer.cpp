#include "DCVertexPointer.h"

using namespace render;


DCVertexPointer::DCVertexPointer()
:Pointer(nullptr)
, Count(0)
{

}

DCVertexPointer::~DCVertexPointer()
{

}

void DCVertexPointer::draw()
{
	if (Pointer)
	{
		glVertexPointer(3, GL_FLOAT, 0, Pointer);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, Count);
	}
}
