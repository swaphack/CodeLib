#include "Pixel.h"
#include "Graphic/import.h"

render::Pixel::Pixel()
{
}

render::Pixel::~Pixel()
{
}

void render::Pixel::loadPointPixel(float x, float y)
{
	this->loadRectPixel(x, y, 1, 1);
}

void render::Pixel::loadRectPixel(float x, float y, float width, float height)
{
	_blockData.resize(width * height * 4);
	char* ptr = _blockData.getPtr();
	render::GLRender::readPixels(x, y, width, height, ReadPixelDataFormat::RGBA, ReadPixelDataType::UNSIGNED_BYTE, ptr);
}

sys::Color4B render::Pixel::readPixelColor(float x, float y)
{
	Pixel pixel;
	pixel.loadPointPixel(x, y);
	const sys::MemoryData& data = pixel.getPixelData();
	return sys::Color4B(data.getValue(0), data.getValue(1), data.getValue(2), data.getValue(3));
}

const sys::MemoryData& render::Pixel::getPixelData() const
{
	return _blockData;
}
