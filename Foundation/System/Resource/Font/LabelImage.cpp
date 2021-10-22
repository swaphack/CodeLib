#include "LabelImage.h"
#include "LabelLibrary.h"
#include "Base/macros.h"
#include "physicslib.h"
#include <map>
#include <cstdint>
#include "LabelStream.h"

#define RGBA_PIXEL_UNIT 4

using namespace sys;
//////////////////////////////////////////////////////////////////////////
LabelImage::LabelImage()
{
	_stream = new LabelStream();
}

LabelImage::~LabelImage()
{
	SAFE_DELETE(_stream);
}

bool LabelImage::load(const TextDefine& textDefine)
{
	uint32_t fixedWidth = (uint32_t)textDefine.size.getWidth() * RGBA_PIXEL_UNIT;
	if (fixedWidth > 0)
	{
		_stream->setFixedWidth(fixedWidth);
	}
	uint32_t fixedHeight = (uint32_t)textDefine.size.getHeight();
	if (fixedHeight > 0)
	{
		_stream->setFixedHeight(fixedHeight);
	}
	if (!G_FONT_LIB->load(textDefine, _stream))
	{
		return false;
	}

	if (_stream->isFixedWidth())
	{
		_stream->format(textDefine.horizontalAlignment);
	}

	this->setPixels((uint8_t*)_stream->getData(), _stream->getWidth() / RGBA_PIXEL_UNIT, _stream->getHeigth(), RGBA_PIXEL_UNIT);
	this->setDataFormat(ImageDataFormat::RGBA);

	_stream->clear();

	return true;
}


