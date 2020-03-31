#include "ImageDetail.h"
#include "system.h"

using namespace render;


ImageDetail::ImageDetail()
:_width(0)
,_height(0)
,_format(PixelFormat::RGBA)
, _internalFormat(TextureParameter::THREE)
,_pixels(nullptr)
{

}

ImageDetail::~ImageDetail()
{
	SAFE_FREE(_pixels);
}

void ImageDetail::setPixels(uint8_t * val)
{
	SAFE_FREE(_pixels);
	_pixels = val;
}

void ImageDetail::setInternalFormat(TextureParameter val)
{
	_internalFormat = val;
}

void ImageDetail::setFormat(PixelFormat val)
{
	_format = val;
}

void ImageDetail::setHeight(uint32_t val)
{
	_height = val;
}

void ImageDetail::setWidth(uint32_t val)
{
	_width = val;
}

uint8_t * ImageDetail::getPixels() const
{
	return _pixels;
}

TextureParameter ImageDetail::getInternalFormat() const
{
	return _internalFormat;
}

PixelFormat ImageDetail::getFormat() const
{
	return _format;
}

uint32_t ImageDetail::getHeight() const
{
	return _height;
}

uint32_t ImageDetail::getWidth() const
{
	return _width;
}
