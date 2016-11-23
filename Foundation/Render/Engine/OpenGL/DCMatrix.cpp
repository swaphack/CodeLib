#include "macros.h"

using namespace render;

DCMatrix::DCMatrix()
{

}

DCMatrix::~DCMatrix()
{

}

void DCMatrix::draw()
{
	if (this->Push)
	{
		glPushMatrix();
	}
	else
	{
		glPopMatrix();
	}
}

DCMatrix* DCMatrix::create(bool push)
{
	DCMatrix* pMatrix = sys::Instance<DCMatrix>::getInstance();
	pMatrix->Push = push;
	return pMatrix;
}

