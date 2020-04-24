#include "ImageDetail.h"
#include "system.h"

using namespace render;


ImageDetail::ImageDetail()
:_width(0)
,_height(0)
,_format(TexImageDataFormat::RGB)
, _internalFormat(TexImageInternalFormat::RGB)
,_pixels(nullptr)
{

}

ImageDetail::~ImageDetail()
{
	SAFE_FREE(_pixels);
}
void ImageDetail::setPixels(uint8_t * val, uint32_t width, uint32_t height, int nUnitSize)
{
	int len = width * height * nUnitSize;
	SAFE_FREE(_pixels);
	_pixels = (uint8_t *)malloc(len);
	memcpy(_pixels, val, len);
	_width = width;
	_height = height;
}

void ImageDetail::setInternalFormat(TexImageInternalFormat val)
{
	_internalFormat = val;
}

void ImageDetail::setFormat(TexImageDataFormat val)
{
	_format = val;
}
uint8_t * ImageDetail::getPixels() const
{
	return _pixels;
}

TexImageInternalFormat ImageDetail::getInternalFormat() const
{
	return _internalFormat;
}

TexImageDataFormat ImageDetail::getFormat() const
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
