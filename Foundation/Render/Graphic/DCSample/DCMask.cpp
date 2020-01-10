#include "DCMask.h"
using namespace render;

DCMask::DCMask()
{

}

DCMask::~DCMask()
{

}

void DCMask::draw()
{
	glEnable(GL_BLEND);
	glBlendFunc(Blend.src, Blend.dest);

	glColor4f(Color.red, Color.green, Color.blue, Color.alpha);

	glBegin(GL_QUADS);

	for (int i = 0; i < 4; i++)
	{
		glVertex3f(Position[i].getX(), Position[i].getY(), Position[i].getZ());
	}

	glEnd();

	glDisable(GL_BLEND);
}

DCMask* DCMask::create(const RectVertex* rectVertex, const sys::Color4B& color, uint8_t opacity, const BlendParam& blend)
{
	DCMask* pMask = sys::Instance<DCMask>::getInstance();
	pMask->Blend = blend;

	convertColor4BTo4F(color, pMask->Color);
	pMask->Color.red *= opacity / COLOR_FLOAT_VALUE;
	pMask->Color.green *= opacity / COLOR_FLOAT_VALUE;
	pMask->Color.blue *= opacity / COLOR_FLOAT_VALUE;
	pMask->Color.alpha *= opacity / COLOR_FLOAT_VALUE;

	pMask->Position[0] = rectVertex->leftDown;
	pMask->Position[1] = rectVertex->rightDown;
	pMask->Position[2] = rectVertex->rightUp;
	pMask->Position[3] = rectVertex->leftUp;

	return pMask;
}

