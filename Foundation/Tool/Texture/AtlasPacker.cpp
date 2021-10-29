#include "AtlasPacker.h"

tool::AtlasPacker::AtlasPacker()
{
}

tool::AtlasPacker::~AtlasPacker()
{
}

void tool::AtlasPacker::setSize(int width, int height)
{
	_size.setWidth(width);
	_size.setHeight(height);
}

int tool::AtlasPacker::getWidth() const
{
	return _size.getWidth();
}

int tool::AtlasPacker::getHeight() const
{
	return _size.getHeight();
}

void tool::AtlasPacker::setReverseY(bool reverse)
{
	_reverseY = reverse;
}

bool tool::AtlasPacker::isReverseY() const
{
	return _reverseY;
}

void tool::AtlasPacker::saveImage(const std::string& imgFilePath, uint8_t* data, sys::ImageDataFormat format)
{
	if (imgFilePath.empty() || data == nullptr
		|| _size.getWidth() == 0 || _size.getHeight() == 0) return;

	int unitSize = sys::ImageDetail::getUnitSize(format);
	sys::ImageDetail detail;
	detail.setDataFormat(format);
	detail.setPixels((uint8_t*)data, _size.getWidth(), _size.getHeight(), unitSize);
	sys::ImageHelper::saveToPNG(detail, imgFilePath);
}