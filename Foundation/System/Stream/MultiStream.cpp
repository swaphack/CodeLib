#include "MultiStream.h"
#include "StreamHelper.h"
#include <cstdlib>
#include <cstring>

using namespace sys;


MultiStream::MultiStream()
:_width(0)
, _heigth(0)
, _depth(0)
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
	_depth = depth;
}

void MultiStream::expendStream(uint32_t width, uint32_t height, uint32_t depth /*= 1*/, bool bBottom/* = false*/)
{
	if (width == 0 || height == 0 || depth == 0)
	{
		return;
	}

	uint32_t newW = _width > width ? _width : width;
	uint32_t newH = _heigth > height ? _heigth : height;
	uint32_t newD = _depth > depth ? _depth : depth;

	MemoryData data;
	data.init(newW * newH * newD);
	if (_data.getPtr())
	{
		uint32_t i, j;
		if (bBottom == false)
		{
			for (i = 0; i < newD; i++)
			{
				for (j = 0; j < newH; j++)
				{
					data.set(i * (newW * newH) + j * newW, _width, _data.getPtr(i * (_width * _heigth) + j * _width));
				}
			}
		}
		else
		{
			for (i = 0; i < newD; i++)
			{
				for (j = 0; j < newH; j++)
				{
					data.set((newD - _depth + i) * (newW * newH) + (newH - _heigth + j) * newW, _width, _data.getPtr(i * (_width * _heigth) + j * _width));
				}
			}
		}
	}

	_data = data;
	_width = newW;
	_heigth = newH;
	_depth = newD;
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

void sys::MultiStream::writeBlockWithReverseY(uint32_t x, uint32_t y, uint32_t width, uint32_t height, const char* inData, uint32_t z)
{
	char* faceData = _data.getPtr(_width * _heigth * z);
	for (uint32_t i = 0; i < height; i++)
	{
		uint32_t yy = height - i - 1;
		memcpy(faceData + (i + y) * _width + x, inData + yy * width, width);
	}
}

void MultiStream::moveBlock(uint32_t srcX, uint32_t srcY, uint32_t width, uint32_t height, uint32_t destX, uint32_t destY, uint32_t z /*= 0*/)
{
	if (width == 0 || height == 0)
	{
		return;
	}
	if (srcX + width > _width || srcY + height > _heigth
		|| destX + width > _width || destY + height > _heigth)
	{
		return;
	}

	char* newData = (char*)malloc(width);
	if (newData == nullptr)
	{
		return;
	}

	uint32_t nFaceLayer = _width * _heigth * z;

	char* faceData = _data.getPtr(nFaceLayer);
	for (uint32_t i = 0; i < height; i++)
	{
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
	_depth = 0;
}

