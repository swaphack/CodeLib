#include "Pixel.h"

#include "../Tool/import.h"
#include "../Control/import.h"

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

void Pixel::setPixel(float x, float y, int width, int height, const sys::Color4B& color)
{
	if (CtrlPixels::getInstance() == nullptr)
	{
		return;
	}
	uchar* data = (uchar*)malloc(width * height * 4);
	memset(data, 0, width * height * 4);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			 memcpy(data + j * 4 + i * width * 4, &color, sizeof(color));
		}
	}
	CtrlPixels::getInstance()->setPixels(x, y, width, height, data);
	SAFE_FREE(data);
}
