#include "Image.h"

using namespace render;


Image::Image()
:_width(0)
,_height(0)
,_format(0)
,_internalFormat(0)
,_pixels(nullptr)
{

}

Image::~Image()
{
	SAFE_FREE(_pixels);
}

void Image::setPixels(uint8_t * val)
{
	SAFE_FREE(_pixels);
	_pixels = val;
}

void Image::setInternalFormat(int val)
{
	_internalFormat = val;
}

void Image::setFormat(int val)
{
	_format = val;
}

void Image::setHeight(uint32_t val)
{
	_height = val;
}

void Image::setWidth(uint32_t val)
{
	_width = val;
}

uint8_t * Image::getPixels() const
{
	return _pixels;
}

int Image::getInternalFormat() const
{
	return _internalFormat;
}

int Image::getFormat() const
{
	return _format;
}

uint32_t Image::getHeight() const
{
	return _height;
}

uint32_t Image::getWidth() const
{
	return _width;
}
