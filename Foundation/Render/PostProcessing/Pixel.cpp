#include "Pixel.h"
#include "Graphic/import.h"
#include "Common/Tool/Tool.h"

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
	loadRectPixel(x, y, width, height, ReadPixelDataFormat::RGBA, ReadPixelDataType::UNSIGNED_BYTE, ptr);
}

void render::Pixel::loadRectPixel(float x, float y, float width, float height, ReadPixelDataFormat pixelFormat, ReadPixelDataType pixelType, void* ptr)
{
	render::GLRender::readPixels(x, y, width, height, pixelFormat, pixelType, ptr);
}

phy::Color4B render::Pixel::readPixelColor(float x, float y)
{
	sys::MemoryData data;
	data.resize(4);
	loadRectPixel(x, y, 1, 1, ReadPixelDataFormat::RGBA, ReadPixelDataType::UNSIGNED_BYTE, data.getPtr());
	return phy::Color4B(data.getValue(0), data.getValue(1), data.getValue(2), data.getValue(3));
}

void render::Pixel::dumpStencil()
{
	const math::Size& volume = Tool::getViewSize();
	sys::MemoryData data;
	data.resize(volume.getWidth() * volume.getHeight(), sizeof(float));
	loadRectPixel(0, 0, volume.getWidth(), volume.getHeight(), ReadPixelDataFormat::STENCIL_INDEX, ReadPixelDataType::FLOAT, data.getPtr());
	GLDebug::showError();
	static int dump = 0;
	std::thread th([data]() {
		std::string filepath = getCString("dump/pixel/stencil_dump%d.txt", dump);
		sys::File::write(filepath, data.getValue(), data.getSize());
	});
	th.detach();

	dump++;
}

const sys::MemoryData& render::Pixel::getPixelData() const
{
	return _blockData;
}
