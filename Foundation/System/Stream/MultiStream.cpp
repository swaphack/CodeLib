#include "MultiStream.h"
#include "StreamHelper.h"
#include <cstdlib>
#include <cstring>

using namespace sys;


MultiStream::MultiStream()
:_width(0)
, _heigth(0)
, _deep(0)
{

}

MultiStream::~MultiStream()
{
}

void MultiStream::initSteam(uint32_t width, uint32_t height, uint32_t depth /*= 1*/)
{
	_data.resize(width * height * depth);
	_width = width;
	_heigth = height;
	_deep = depth;
}


void MultiStream::expendStream(uint32_t width, uint32_t height, uint32_t depth /*= 1*/, bool bBottom/* = false*/)
{
	if (width < _width || height < _heigth || depth < depth)
	{
		return;
	}

	char* data = StreamHelper::mallocStream(width * height * depth);
	if (data == nullptr)
	{
		return;
	}

	if (_data.getPtr())
	{
		uint32_t cpyW = 0;
		uint32_t cpyH = 0;
		uint32_t cpyD = 0;

		uint32_t i, j;
		if (bBottom == false)
		{
			cpyW = _width > width ? width : _width;
			cpyH = _heigth > height ? height : _heigth;
			cpyD = _deep > depth ? depth : _deep;

			for (i = 0; i < cpyD; i++)
			{
				for (j = 0; j < cpyH; j++)
				{
					memcpy(data + i * (width * height) + j * width, _data.getPtr(i * (_width * _heigth) + j * _width), _width);
				}
			}
		}
		else
		{
			cpyW = width > _width ? width : _width;
			cpyH = height > _heigth ? height : _heigth;
			cpyD = depth > _deep ? depth : _deep;

			for (i = 0; i < _deep; i++)
			{
				for (j = 0; j < _heigth; j++)
				{
					memcpy(data + (cpyD - _deep + i) * (width * height) + (cpyH - _heigth + j) * width/* + cpyD - _width*/, _data.getPtr(i * (_width * _heigth) + j * _width), _width);
				}
			}
		}
	}
	_data.init(width * height * depth, data);
	_width = width;
	_heigth = height;
	_deep = depth;
}

void MultiStream::readBlock(uint32_t x, uint32_t y, uint32_t width, uint32_t height, MemoryData& outData, uint32_t z /*= 0*/)
{
	outData.resize(width * height);
	
	char* faceData = _data.getPtr(_width * _heigth * z);
	for (uint32_t i = 0; i < height; i++)
	{
		memcpy(outData.getPtr(i * width) , faceData + (y + i) * _width + x, width);
	}
}

void MultiStream::writeBlock(uint32_t x, uint32_t y, uint32_t width, uint32_t height, const char* inData, uint32_t z /*= 0*/)
{
	char* faceData = _data.getPtr(_width * _heigth * z);
	for (uint32_t i = 0; i < height; i++)
	{
		memcpy(faceData + (i + y) * _width + x, inData + i * width, width);
	}
}

void MultiStream::moveBlock(uint32_t srcX, uint32_t srcY, uint32_t width, uint32_t height, uint32_t destX, uint32_t destY, uint32_t z /*= 0*/)
{
	char* newData = (char*)malloc(width);

	char* faceData = _data.getPtr(_width * _heigth * z);
	for (uint32_t i = 0; i < height; i++)
	{
		//memset(newData, 0, width);
		memcpy(newData, faceData + (i + srcY) * _width + srcX, width);
		memset(faceData + (i + srcY) * _width + srcX, 0, width);
		memmove(faceData + (i + destY) * _width + destX, newData, width);
	}

	free(newData);
}

void MultiStream::resetBlock(uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint32_t z /*= 0*/)
{
	char* faceData = _data.getPtr(_width * _heigth * z) ;
	for (uint32_t i = 0; i < height; i++)
	{
		memset(faceData + (i + y) * _width + x,  0, width);
	}
}


//////////////////////////////////////////////////////////////////////////
void MultiStream::readBlock(uint32_t x, uint32_t y, uint32_t z, uint32_t width, uint32_t height, uint32_t depth, char* outData)
{
	char* newData = StreamHelper::mallocStream(width * height * depth);
	if (newData == nullptr)
	{
		return;
	}

	uint32_t i, j;

	for (i = 0; i < depth; i ++)
	{
		char* faceData = _data.getPtr(_width * _heigth * (z + i));
		for (j = 0; j < height; j ++)
		{
			memcpy(newData + i * width * height + j * width, faceData + (y + i) * _width + x, width);
		}
	}

	outData = newData;
}


void MultiStream::writeBlock(uint32_t x, uint32_t y, uint32_t z, uint32_t width, uint32_t height, uint32_t depth, const char* inData)
{
	uint32_t i, j;

	for (i = 0; i < depth; i++)
	{
		char* faceData = _data.getPtr(_width * _heigth * (z + i));
		for (j = 0; j < height; j++)
		{
			memcpy(faceData + (j + y) * _width + x, inData + i * width * height + j * width, width);
		}
	}
}

void MultiStream::moveBlock(uint32_t x, uint32_t y, uint32_t z, uint32_t width, uint32_t height, uint32_t depth, uint32_t offsetX, uint32_t offsetY, uint32_t offsetZ)
{

}

void MultiStream::clear()
{
	_data.resize(0);
	_width = 0;
	_heigth = 0;
	_deep = 0;
}

