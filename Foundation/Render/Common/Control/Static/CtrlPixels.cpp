#include "CtrlPixels.h"
#include "system.h"
using namespace render;

static CtrlPixels* s_CtrlPixels = nullptr;

CtrlPixels::CtrlPixels()
{
	ASSERT(s_CtrlPixels == nullptr);
	s_CtrlPixels = this;

	_width = Tool::getGLViewSize().width;
	_height = Tool::getGLViewSize().height;

	_pixelsData = (uchar*)malloc(_width * _height * 4);
	memset(_pixelsData, 0, sizeof(_width * _height * 4));
}

CtrlPixels::~CtrlPixels()
{
	SAFE_FREE(_pixelsData);
}

CtrlPixels* CtrlPixels::getInstance()
{
	if (s_CtrlPixels == nullptr)
	{
		return nullptr;
	}
	return s_CtrlPixels;
}

void CtrlPixels::draw()
{
	glDrawPixels(_width, _height, GL_RGBA, GL_UNSIGNED_BYTE, _pixelsData);
}

void CtrlPixels::setPixels(int x, int y, int width, int height, uchar* data)
{
	if (data == nullptr)
	{
		return;
	}

	if (x < 0 || y < 0 || x + width > _width || y + height > _height )
	{
		return;
	}

	for (int i = y; i < y + height; i++ )
	{
		memcpy(_pixelsData + i * _width * 4 + x * 4, data + (i - y) * width * 4, width * 4);
	}
}
