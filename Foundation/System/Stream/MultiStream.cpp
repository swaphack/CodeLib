#include "MultiStream.h"

using namespace sys;


MultiStream::MultiStream()
:_data(nullptr)
, _width(0)
, _heigth(0)
, _deep(0)
{

}

MultiStream::~MultiStream()
{
	StreamHelper::freeStream(_data);
}

void MultiStream::initStream(ss_t width, ss_t height, ss_t deep /*= 1*/)
{
	char* data = StreamHelper::mallocStream(width * height * deep);
	if (data == nullptr)
	{
		return;
	}

	if (_data)
	{
		ss_t cpyW = _width > width ? width : _width;
		ss_t cpyH = _heigth > height ? height : _heigth;
		ss_t cpyD = _deep > deep ? deep : _deep;

		int i, j;
		for (i = 0; i < cpyD; i ++)
		{
			for (j = 0; j < cpyH; j++)
			{
				memcpy(data + i * (width * height) + j * width, _data + i * (_width * _heigth) + j * _width, _width);
			}
		}

		StreamHelper::freeStream(_data);
	}

	_data = data;
	_width = width;
	_heigth = height;
	_deep = deep;
}

void MultiStream::readBlock(ss_t x, ss_t y, ss_t width, ss_t height, char* outData, ss_t z /*= 0*/)
{
	char* newData = StreamHelper::mallocStream(width * height);
	if (newData == nullptr)
	{
		return;
	}
	
	char* faceData = _data + _width * _heigth * z;
	for (int i = 0; i < height; i++)
	{
		memcpy(newData + i * width, faceData + (y + i) * _width + x, width);
	}

	outData = newData;
}

void MultiStream::writeBlock(ss_t x, ss_t y, ss_t width, ss_t height, const char* inData, ss_t z /*= 0*/)
{
	char* faceData = _data + _width * _heigth * z;
	for (int i = 0; i < height; i++)
	{
		memcpy(faceData + (i + y) * _width + x, inData + i * width, width);
	}
}

void MultiStream::moveBlock(ss_t srcX, ss_t srcY, ss_t width, ss_t height, ss_t destX, ss_t destY, ss_t z /*= 0*/)
{
	char* faceData = _data + _width * _heigth * z;
	for (int i = 0; i < height; i++)
	{
		memmove(faceData + (i + destY) * _width + destX, faceData + (i + srcY) * _width + srcX, width);
	}
}


//////////////////////////////////////////////////////////////////////////
void MultiStream::readBlock(ss_t x, ss_t y, ss_t z, ss_t width, ss_t height, ss_t deep, char* outData)
{
	char* newData = StreamHelper::mallocStream(width * height * deep);
	if (newData == nullptr)
	{
		return;
	}

	int i, j;

	for (i = 0; i < deep; i ++)
	{
		char* faceData = _data + _width * _heigth * (z + i);
		for (j = 0; j < height; j ++)
		{
			memcpy(newData + i * width * height + j * width, faceData + (y + i) * _width + x, width);
		}
	}

	outData = newData;
}


void MultiStream::writeBlock(ss_t x, ss_t y, ss_t z, ss_t width, ss_t height, ss_t deep, const char* inData)
{
	int i, j;

	for (i = 0; i < deep; i++)
	{
		char* faceData = _data + _width * _heigth * (z + i);
		for (j = 0; j < height; j++)
		{
			memcpy(faceData + (j + y) * _width + x, inData + i * width * height + j * width, width);
		}
	}
}

void MultiStream::moveBlock(ss_t x, ss_t y, ss_t z, ss_t width, ss_t height, ss_t deep, ss_t offsetX, ss_t offsetY, ss_t offsetZ)
{

}
