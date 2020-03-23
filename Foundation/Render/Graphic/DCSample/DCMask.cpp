#include "DCMask.h"
using namespace render;

DCMask::DCMask()
{

}

DCMask::~DCMask()
{

}

void DCMask::drawDC()
{
	glBegin(GL_QUADS);

	for (int i = 0; i < 4; i++)
	{
		glVertex3f(Position[i].getX(), Position[i].getY(), Position[i].getZ());
	}

	glEnd();
}

DCMask* DCMask::create(const RectVertex* rectVertex, const sys::Color4B& color, uint8_t opacity, const BlendParam& blend)
{
	DCMask* pMask = sys::Instance<DCMask>::getInstance();
	pMask->initColor(color, opacity, blend);

	pMask->Position[0] = rectVertex->leftDown;
	pMask->Position[1] = rectVertex->rightDown;
	pMask->Position[2] = rectVertex->rightUp;
	pMask->Position[3] = rectVertex->leftUp;

	return pMask;
}

