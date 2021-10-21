#include "LabelStream.h"
#define RGBA_PIXEL_UNIT 4

using namespace sys;

LabelStream::LabelStream()
	:_offsetX(0)
	, _offsetY(0)
	, _lineHeight(0)
	, _fixedWidth(0)
{

}

LabelStream::~LabelStream()
{

}

void LabelStream::resetOffset()
{
	_offsetX = 0;
	_offsetY = getHeigth() - getLineHeight();
}

void LabelStream::writeOneLineBlock(int width, int height, const char* buffer, int deltaY)
{
	// 实际大小
	int realWidth = width * RGBA_PIXEL_UNIT;
	int realHeight = getLineHeight();

	char* faceData = _data.getPtr();
	for (int i = 0; i < height; i++)
	{
		_data.set((i + _offsetY + deltaY) * _width + _offsetX, realWidth, buffer + i * realWidth);
	}

	_offsetX += realWidth;
}

void LabelStream::writeMultiLineBlock(int width, int height, const char* buffer, int deltaY)
{
	// 实际大小
	int realWidth = width * RGBA_PIXEL_UNIT;
	int realHeight = getLineHeight();

	if (_offsetX + realWidth > getFixedWidth())
	{
		this->writeSpaceLine();
	}

	char* faceData = _data.getPtr();
	for (int i = 0; i < height; i++)
	{
		_data.set((i + _offsetY + deltaY) * _width + _offsetX, realWidth, buffer + i * realWidth);
	}

	_offsetX += realWidth;
}

void LabelStream::writeEndLine()
{
	if (isFixedWidth() == false)
	{
		return;
	}

	_lineWidthStack.push(_offsetX);

	_offsetX = 0;
	_offsetY -= getLineHeight();
}

void LabelStream::writeSpaceLine()
{
	if (isFixedWidth() == false)
	{
		return;
	}
	_lineWidthStack.push(_offsetX);

	_offsetX = 0;
	_offsetY -= getLineHeight();
}

void LabelStream::endStream()
{
	_lineWidthStack.push(_offsetX);
}

void LabelStream::format(HorizontalAlignment ha)
{
	if (_lineWidthStack.empty() || isFixedWidth() == false)
	{
		return;
	}

	int count = _heigth / getLineHeight();
	int width = 0;
	int offsetX = 0;

	if (ha == HorizontalAlignment::LEFT)
	{// 默认左对齐
		while (!_lineWidthStack.empty())
		{
			_lineWidthStack.pop();
		}
	}
	else if (ha == HorizontalAlignment::CENTER)
	{// 居中对齐
		for (int i = 0; i < count; i++)
		{
			width = _lineWidthStack.top();
			offsetX = (getFixedWidth() - width) * 0.5f;
			offsetX -= offsetX % 4;
			if (offsetX < 0)
			{
				offsetX = 0;
			}
			moveBlock(0, i * getLineHeight(), width, getLineHeight(), offsetX, i * getLineHeight());
			_lineWidthStack.pop();
		}
	}
	else if (ha == HorizontalAlignment::RIGHT)
	{// 右对齐
		for (int i = 0; i < count; i++)
		{
			width = _lineWidthStack.top();
			offsetX = getFixedWidth() - width;
			moveBlock(0, i * getLineHeight(), width, getLineHeight(), offsetX, i * getLineHeight());
			_lineWidthStack.pop();
		}
	}
}

void LabelStream::setLineHeight(uint32_t val)
{
	_lineHeight = val;
}

uint32_t LabelStream::getLineHeight() const
{
	return _lineHeight;
}

bool LabelStream::isFixedWidth()
{
	return _fixedWidth != 0;
}

bool sys::LabelStream::isFixedHeight()
{
	return _fixedHeight != 0;
}

uint32_t LabelStream::getFixedWidth()
{
	return _fixedWidth;
}

void sys::LabelStream::setFixedHeight(uint32_t height)
{
	_fixedHeight = height;
}

uint32_t sys::LabelStream::getFixedHeight()
{
	return _fixedHeight;
}

void LabelStream::setFixedWidth(uint32_t width)
{
	_fixedWidth = width;
}