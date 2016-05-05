#include "CtrlPixel.h"

#include "../Tool/import.h"

using namespace render;


CtrlPixel::CtrlPixel()
{

}

CtrlPixel::~CtrlPixel()
{

}

void CtrlPixel::draw()
{

}

sys::Color4B CtrlPixel::getPixel(float x, float y)
{
	uchar data[4] = { 0 };
	glReadPixels(x, y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, data);

	return sys::Color4B(data[0], data[1], data[2], data[3]);
}

void CtrlPixel::getPixelBlock(sys::Point point, sys::Color4B color)
{

}

void CtrlPixel::initSelf()
{

}
