#include "CtrlText.h"
#include "Common/Texture/TextureCache.h"
#include "Common/Texture/Texture.h"
#include "Common/Texture/TexFrame.h"
#include "Common/Tool/TextureTool.h"

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

	_notify->addListen(ENP_TEXT_FRAME, [&](){
		this->onTextChange();
	});

	_notify->addListen(ENP_TEXTURE_FRAME, [&](){
		const Texture* texture = _texFrame->getTexture();
		if (texture == nullptr)
		{
			return;
		}

		math::Size size = math::Size(static_cast<float>(texture->getWidth()), static_cast<float>(texture->getHeight()));

		if (isCounter())TextureTool::setTexture2DCounterCoords(&_texRect, size, _texFrame->getRect());
		else TextureTool::setTexture2DCoords(&_texRect, size, _texFrame->getRect());

		math::Vector3 orgin = math::Vector3();
		math::Volume volume = math::Volume(static_cast<float>(texture->getWidth()), static_cast<float>(texture->getHeight()));
		math::Vector3 anchor = math::Vector3(0.5f, 0.5f, 0.5f);
		if (_textDefine.verticalAlignment == EVA_BOTTOM)
		{
		}
		else if (_textDefine.verticalAlignment == EVA_CENTER)
		{
			orgin.setY((_volume.getHeight() - volume.getHeight()) * 0.5f);
		}
		else if (_textDefine.verticalAlignment == EVA_TOP)
		{
			orgin.setY(_volume.getHeight() - volume.getHeight());
		}

		if (_textDefine.horizontalAlignment == EHA_LEFT)
		{
		}
		else if (_textDefine.verticalAlignment == EHA_CENTER)
		{
			orgin.setX((_volume.getWidth() - volume.getWidth()) * 0.5f);
		}
		else if (_textDefine.verticalAlignment == EHA_RIGHT)
		{
			orgin.setX(_volume.getWidth() - volume.getWidth());
		}

		TextureTool::setTexture2DVertexts(&_texRect, orgin, volume, anchor);
		TextureTool::setTexture2DFlip(&_texRect, _bFlipX, _bFlipY);
	});
	

	return true;
}

void CtrlText::setFontPath(const char* fonturl)
{
	_textDefine.filepath = fonturl;

	this->notify(ENP_TEXT_FRAME);
}

const char* CtrlText::getFontPath()
{
	return _textDefine.filepath.c_str();
}

void CtrlText::setFontSize(float size)
{
	_textDefine.fontSize = size;

	this->notify(ENP_TEXT_FRAME);
}

float CtrlText::getFontSize()
{
	return _textDefine.fontSize;
}

void CtrlText::setHorizontalDistance(float distance)
{
	_textDefine.horizontalDistance = distance;

	this->notify(ENP_TEXT_FRAME);
}

float CtrlText::getHorizontalDistance()
{
	return _textDefine.horizontalDistance;
}

void CtrlText::setVerticalDistance(float distance)
{
	_textDefine.verticalDistance = distance;

	this->notify(ENP_TEXT_FRAME);
}

float CtrlText::getVerticalDistance()
{
	return _textDefine.verticalDistance;
}

void CtrlText::setString(const char* text)
{
	TextProtocol::setString(text);
	_textDefine.text = text;

	this->notify(ENP_TEXT_FRAME);
}

void CtrlText::setHorizontalAlignment(HorizontalAlignment alignment)
{
	_textDefine.horizontalAlignment = alignment;

	this->notify(ENP_TEXT_FRAME);
}

HorizontalAlignment CtrlText::getHorizontalAlignment()
{
	return _textDefine.horizontalAlignment;
}

void CtrlText::setVerticalAlignment(VerticalAlignment alignment)
{
	_textDefine.verticalAlignment = alignment;

	this->notify(ENP_TEXT_FRAME);
}

VerticalAlignment CtrlText::getVerticalAlignment()
{
	return _textDefine.verticalAlignment;
}

void CtrlText::setDimensions(float width, float height)
{
	_textDefine.width = width;
	_textDefine.height = height;
	this->setVolume(width, height);

	this->notify(ENP_TEXT_FRAME);
}

void CtrlText::setDimensions(const math::Size& size)
{
	this->setDimensions(size.getWidth(), size.getHeight());
}

math::Size CtrlText::getDimensions()
{
	return math::Size(_textDefine.width, _textDefine.height);
}

void CtrlText::setColor(const sys::Color4B& color)
{
	ColorProtocol::setColor(color);
	_textDefine.color = color;
	this->notify(ENP_TEXT_FRAME);
}

void CtrlText::onTextChange()
{
	Texture2D* texture = G_TEXTURE_CACHE->createTexture2D(_textDefine);
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


