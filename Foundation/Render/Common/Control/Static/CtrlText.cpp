#include "CtrlText.h"

using namespace render;

CtrlText::CtrlText()
{
}

CtrlText::~CtrlText()
{
}

bool CtrlText::init()
{
	CtrlFrame::init();

	_notify->removeListens(ENP_TEXTURE_FRAME);

	_notify->addListen(ENP_TEXTURE_FRAME, [&](){
		const Texture* texture = _texFrame->getTexture();
		if (texture == nullptr)
		{
			return;
		}

		sys::Size size = sys::Size(static_cast<float>(texture->getWidth()), static_cast<float>(texture->getHeight()));

		if (isCounter())TextureTool::setTexture2DCounterCoords(&_texRect, size, _texFrame->getRect());
		else TextureTool::setTexture2DCoords(&_texRect, size, _texFrame->getRect());

		sys::Vector orgin = sys::Vector::Zero;
		sys::Volume volume = sys::Volume(static_cast<float>(texture->getWidth()), static_cast<float>(texture->getHeight()));
		sys::Vector anchor = sys::Vector(0.5f, 0.5f, 0.5f);
		if (_textDefine.verticalAlignment == EVA_BOTTOM)
		{
		}
		else if (_textDefine.verticalAlignment == EVA_CENTER)
		{
			orgin.y = (_volume.height - volume.height) * 0.5f;
		}
		else if (_textDefine.verticalAlignment == EVA_TOP)
		{
			orgin.y = _volume.height - volume.height;
		}

		if (_textDefine.horizontalAlignment == EHA_LEFT)
		{
		}
		else if (_textDefine.verticalAlignment == EHA_CENTER)
		{
			orgin.x = (_volume.width - volume.width) * 0.5f;
		}
		else if (_textDefine.verticalAlignment == EHA_RIGHT)
		{
			orgin.x = _volume.width - volume.width;
		}

		TextureTool::setTexture2DVertexts(&_texRect, orgin, volume, anchor);
		TextureTool::setTexture2DFlip(&_texRect, _bFlipX, _bFlipY);
	});
	

	return true;
}

void CtrlText::draw()
{
	CtrlFrame::draw();
}

void CtrlText::setFontPath(const char* fonturl)
{
	_textDefine.filepath = fonturl;
	setDirty(true);
}

const char* CtrlText::getFontPath()
{
	return _textDefine.filepath.c_str();
}

void CtrlText::setFontSize(float size)
{
	_textDefine.fontSize = size;
	setDirty(true);
}

float CtrlText::getFontSize()
{
	return _textDefine.fontSize;
}

void CtrlText::setHorizontalDistance(float distance)
{
	_textDefine.horizontalDistance = distance;
	setDirty(true);
}

float CtrlText::getHorizontalDistance()
{
	return _textDefine.horizontalDistance;
}

void CtrlText::setVerticalDistance(float distance)
{
	_textDefine.verticalDistance = distance;
	setDirty(true);
}

float CtrlText::getVerticalDistance()
{
	return _textDefine.verticalDistance;
}

void CtrlText::setString(const char* text)
{
	TextProtocol::setString(text);
	_textDefine.text = text;
	setDirty(true);
}

void CtrlText::setHorizontalAlignment(HorizontalAlignment alignment)
{
	_textDefine.horizontalAlignment = alignment;
	setDirty(true);
}

HorizontalAlignment CtrlText::getHorizontalAlignment()
{
	return _textDefine.horizontalAlignment;
}

void CtrlText::setVerticalAlignment(VerticalAlignment alignment)
{
	_textDefine.verticalAlignment = alignment;
	setDirty(true);
}

VerticalAlignment CtrlText::getVerticalAlignment()
{
	return _textDefine.verticalAlignment;
}

void CtrlText::setDimensions(float width, float height)
{
	_textDefine.width = width;
	_textDefine.height = height;
	this->setVolume(width, height, 0);

	setDirty(true);
}

void CtrlText::setDimensions(const sys::Size& size)
{
	this->setDimensions(size.width, size.height);
}

sys::Size CtrlText::getDimensions()
{
	return sys::Size(_textDefine.width, _textDefine.height);
}

void CtrlText::setColor(const sys::Color4B& color)
{
	ColorProtocol::setColor(color);
	_textDefine.color = color;
	setDirty(true);
}

void CtrlText::initSelf()
{
	onTextChange();

	CtrlFrame::initSelf();
}

void CtrlText::onTextChange()
{
	Texture2D* texture = G_TEXTURE_CACHE->getTexture2D(_textDefine);
	if (texture == nullptr)
	{
		return;
	}

	if (_textDefine.width == 0 || _textDefine.height == 0)
	{
		this->setWidth(static_cast<float>(texture->getWidth()));
		this->setHeight(static_cast<float>(texture->getHeight()));
	}
	this->setTextureWithRect(texture);
}


