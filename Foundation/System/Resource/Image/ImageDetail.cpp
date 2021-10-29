#include "ImageDetail.h"
#include "system.h"

using namespace sys;


ImageDetail::ImageDetail()
:_width(0)
,_height(0)
,_format(ImageDataFormat::RGB)
{

}

uint8_t sys::ImageDetail::getUnitSize() const
{
	return getUnitSize(_format);
}

uint8_t* sys::ImageDetail::getPtr(uint32_t offset) const
{
	return (uint8_t*)_data.getPtr(offset);
}

uint8_t sys::ImageDetail::getValue(uint32_t offset) const
{
	return *_data.getPtr(offset);
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

void ImageDetail::setPixels(const MemoryData& data, uint32_t width, uint32_t height, int nUnitSize)
{
	_data = data;
	_width = width;
	_height = height;
}

uint8_t sys::ImageDetail::getUnitSize(ImageDataFormat val)
{
	uint8_t size = 0;
	switch (val)
	{
	case sys::ImageDataFormat::RED:
		size = 1;
		break;
	case sys::ImageDataFormat::RG:
		size = 2;
		break;
	case sys::ImageDataFormat::RGB:
		size = 3;
		break;
	case sys::ImageDataFormat::RGBA:
		size = 4;
		break;
	case sys::ImageDataFormat::BGR:
		size = 3;
		break;
	case sys::ImageDataFormat::BGRA:
		size = 4;
		break;
	default:
		break;
	}

	return size;
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

void sys::ImageDetail::flipX()
{
	if (_data.getSize() == 0)
	{
		return;
	}

	int width = _width * getUnitSize();
	int w = getUnitSize();
	int half = _width / 2;
	sys::MemoryData data(width);
	for (int j = 0; j < _height; j++)
	{
		for (int i = 0; i < half; i++)
		{
			int offset = _width - i - 1;
			data.set(0, w, _data.getPtr(i * w + j * width));

			_data.set(i * w + j * width, w, _data.getPtr(offset * w + j * width));
			_data.set(offset * w + j * width, w, data.getValue());
		}
	}
}

void sys::ImageDetail::flipY()
{
	if (_data.getSize() == 0)
	{
		return;
	}

	int width = _width * getUnitSize();
	int half = _height / 2;
	sys::MemoryData data(width);
	for (int i = 0; i < half; i++)
	{
		int offset = _height - i - 1;
		data.set(0, width, _data.getPtr(i * width));

		_data.set(i * width, width, _data.getPtr(offset * width));
		_data.set(offset * width, width, data.getValue());
	}
}

void sys::ImageDetail::rotate90()
{
	if (_data.getSize() == 0)
	{
		return;
	}

	uint32_t width = _height;
	uint32_t height = _width;

	uint8_t unitSize = getUnitSize();

	sys::MemoryData data(height * width * unitSize);
	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			data.set(unitSize * (j * _height + i), unitSize, _data.getPtr(unitSize * ((_height - i -1) * _width  + j)));
		}
	}

	_width = width;
	_height = height;
	_data = data;
}

void sys::ImageDetail::rotate270()
{
	if (_data.getSize() == 0)
	{
		return;
	}

	uint32_t width = _height;
	uint32_t height = _width;

	uint8_t unitSize = getUnitSize();

	sys::MemoryData data(height * width * unitSize);
	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			data.set(unitSize * (j * _height + i), unitSize, _data.getPtr(unitSize * (i * _width + j)));
		}
	}

	_width = width;
	_height = height;
	_data = data;
}

void sys::ImageDetail::expandFormat()
{
	if (_format == ImageDataFormat::RGBA
		|| _format == ImageDataFormat::BGRA)
	{
		return;
	}

	uint8_t oldUnitSize = sys::ImageDetail::getUnitSize(_format);
	uint8_t newUnitSize = sys::ImageDetail::getUnitSize(ImageDataFormat::RGBA);
	uint8_t one = 255;
	uint8_t zero = 0;

	sys::MemoryData data(_width * _height * newUnitSize);
	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			char* ptr = _data.getPtr(oldUnitSize * (i * _width + j));
			if (_format == ImageDataFormat::RED)
			{
				uint8_t temp = (*ptr);
				uint8_t value = temp == zero ? zero : one;
				data.set(newUnitSize * (i * _width + j), oldUnitSize, (char*)&value);
				data.set(newUnitSize * (i * _width + j) + 1, 1, (char*)&value);
				data.set(newUnitSize * (i * _width + j) + 2, 1, (char*)&value);
				data.set(newUnitSize * (i * _width + j) + 3, 1, (char*)&temp);
			}
			else if (_format == ImageDataFormat::RG)
			{
				data.set(newUnitSize * (i * _width + j), oldUnitSize, ptr);
				data.set(newUnitSize * (i * _width + j) + 2, 1, (char*)&one);
				data.set(newUnitSize * (i * _width + j) + 3, 1, (char*)&one);
			}
			else if (_format == ImageDataFormat::RGB || _format == ImageDataFormat::BGR)
			{
				data.set(newUnitSize * (i * _width + j), oldUnitSize, ptr);
				data.set(newUnitSize * (i * _width + j) + 3, 1, (char*)&one);
			}
		}
	}

	_data = data;
	_format = ImageDataFormat::RGBA;
}
