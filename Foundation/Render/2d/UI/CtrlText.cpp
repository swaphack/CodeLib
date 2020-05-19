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
	if (!CtrlFrame::init())
	{
		return false;
	}

	_notify->removeListens(NodeNotifyType::TEXTURE);

	_notify->addListen(NodeNotifyType::TEXT, [&](){
		_material->updateMatTexture();

		this->onTextChange();

		this->updateBufferData();
	});	

	return true;
}

void CtrlText::setFontPath(const std::string& fonturl)
{
	_textDefine.filepath = fonturl;

	this->notify(NodeNotifyType::TEXT);
}

const std::string& CtrlText::getFontPath()
{
	return _textDefine.filepath;
}

void CtrlText::setFontSize(float size)
{
	_textDefine.fontSize = size;

	this->notify(NodeNotifyType::TEXT);
}

float CtrlText::getFontSize()
{
	return _textDefine.fontSize;
}

void CtrlText::setHorizontalDistance(float distance)
{
	_textDefine.horizontalDistance = distance;

	this->notify(NodeNotifyType::TEXT);
}

float CtrlText::getHorizontalDistance()
{
	return _textDefine.horizontalDistance;
}

void CtrlText::setVerticalDistance(float distance)
{
	_textDefine.verticalDistance = distance;

	this->notify(NodeNotifyType::TEXT);
}

float CtrlText::getVerticalDistance()
{
	return _textDefine.verticalDistance;
}

void CtrlText::setString(const std::string&text)
{
	TextProtocol::setString(text);
	_textDefine.text = text;

	this->notify(NodeNotifyType::TEXT);
}

void CtrlText::setHorizontalAlignment(sys::HorizontalAlignment alignment)
{
	_textDefine.horizontalAlignment = alignment;

	this->notify(NodeNotifyType::TEXT);
}

sys::HorizontalAlignment CtrlText::getHorizontalAlignment()
{
	return _textDefine.horizontalAlignment;
}

void CtrlText::setVerticalAlignment(sys::VerticalAlignment alignment)
{
	_textDefine.verticalAlignment = alignment;

	this->notify(NodeNotifyType::TEXT);
}

sys::VerticalAlignment CtrlText::getVerticalAlignment()
{
	return _textDefine.verticalAlignment;
}

void CtrlText::setDimensions(float width, float height)
{
	_textDefine.width = width;
	_textDefine.height = height;
	this->setVolume(width, height);

	this->notify(NodeNotifyType::TEXT);
}

void CtrlText::setDimensions(const math::Size& size)
{
	this->setDimensions(size.getWidth(), size.getHeight());
}

math::Size CtrlText::getDimensions()
{
	return math::Size(_textDefine.width, _textDefine.height);
}

void CtrlText::setTextColor(const sys::Color3B& color)
{
	_textDefine.color = color;
	this->notify(NodeNotifyType::TEXT);
}

const sys::Color3B& render::CtrlText::getTextColor()
{
	return _textDefine.color;
}

void CtrlText::onTextChange()
{
	Texture2D* texture = G_TEXTURE_CACHE->createTexture2D(_textDefine);
	if (texture == nullptr)
	{
		return;
	}

	this->setTextureWithRect(texture);

	if (_textDefine.width == 0 || _textDefine.height == 0)
	{
		this->setWidth(static_cast<float>(texture->getWidth()));
		this->setHeight(static_cast<float>(texture->getHeight()));
	}

	math::Size size = math::Size(texture->getWidth(), texture->getHeight());
	math::Rect rect(math::Vector2(), size);
	TextureTool::setTexture2DCoords(&_texRect, size, rect);


	math::Vector3 anchor = math::Vector3(0.5f, 0.5f, 0.5f);
	math::Vector3 orgin = getOrgin(size);
	math::Volume volume = math::Volume(texture->getWidth(), texture->getHeight());

	TextureTool::setTexture2DVertexts(&_texRect, orgin, volume, anchor);
}

math::Vector3 render::CtrlText::getOrgin(const math::Size& size)
{
	math::Vector3 orgin = math::Vector3();
	
	math::Volume volume = math::Volume(size.getWidth(), size.getHeight());
	
	if (_textDefine.verticalAlignment == sys::VerticalAlignment::BOTTOM)
	{
	}
	else if (_textDefine.verticalAlignment == sys::VerticalAlignment::MIDDLE)
	{
		orgin.setY((_volume.getHeight() - volume.getHeight()) * 0.5f);
	}
	else if (_textDefine.verticalAlignment == sys::VerticalAlignment::TOP)
	{
		orgin.setY(_volume.getHeight() - volume.getHeight());
	}

	if (_textDefine.horizontalAlignment == sys::HorizontalAlignment::LEFT)
	{
	}
	else if (_textDefine.horizontalAlignment == sys::HorizontalAlignment::CENTER)
	{
		orgin.setX((_volume.getWidth() - volume.getWidth()) * 0.5f);
	}
	else if (_textDefine.horizontalAlignment == sys::HorizontalAlignment::RIGHT)
	{
		orgin.setX(_volume.getWidth() - volume.getWidth());
	}

	return orgin;
}




