#include "macros.h"
using namespace render;


DCColorPointer::DCColorPointer()
:Pointer(nullptr)
, Count(0)
{

}

DCColorPointer::~DCColorPointer()
{

}

void DCColorPointer::draw()
{
	if (Pointer)
	{
		glColorPointer(4, GL_BYTE, 0, Pointer);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, Count);
	}
}
