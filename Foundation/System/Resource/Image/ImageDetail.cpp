#include "ImageDetail.h"
#include "system.h"

using namespace sys;


ImageDetail::ImageDetail()
:_width(0)
,_height(0)
,_format(ImageDataFormat::RGB)
{

}

ImageDetail::~ImageDetail()
{
}
void ImageDetail::setPixels(uint8_t * val, uint32_t width, uint32_t height, int nUnitSize)
{
	int len = width * height * nUnitSize;
	_data.init(len, val);
	_width = width;
	_height = height;
}

void ImageDetail::setDataFormat(ImageDataFormat val)
{
	_format = val;
}
uint8_t* ImageDetail::getPixels() const
{
	return (uint8_t*)_data.getPtr();
}

ImageDataFormat ImageDetail::getDataFormat() const
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
