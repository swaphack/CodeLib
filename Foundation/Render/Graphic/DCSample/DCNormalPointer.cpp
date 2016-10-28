#include "DCNormalPointer.h"

using namespace render;

DCNormalPointer::DCNormalPointer()
:Pointer(nullptr)
, Count(0)
{

}

DCNormalPointer::~DCNormalPointer()
{

}

void DCNormalPointer::draw()
{
	if (Pointer)
	{
		glNormalPointer(3, GL_FLOAT, Pointer);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, Count);
	}
}
