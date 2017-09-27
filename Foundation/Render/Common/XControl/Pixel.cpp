#include "Pixel.h"
#include "ext-config.h"
#include "../Tool/import.h"

using namespace render;


Pixel::Pixel()
{

}

Pixel::~Pixel()
{

}

sys::Color4B Pixel::getPixel(float x, float y)
{
	uchar data[4] = { 0 };
	glReadPixels((int)x, (int)y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, data);

	return sys::Color4B(data[0], data[1], data[2], data[3]);
}
