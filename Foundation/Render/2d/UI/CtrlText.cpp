#include "CtrlText.h"
#include "Common/Texture/TextureCache.h"
#include "Common/Texture/Texture.h"
#include "Common/Texture/Texture2D.h"
#include "Common/Texture/TexFrame.h"
#include "Common/Tool/VertexTool.h"
#include "Common/Mesh/import.h"

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

	_notify->removeListens(NodeNotifyType::BODY);
	_notify->removeListens(NodeNotifyType::TEXTURE);

	_notify->addListen(NodeNotifyType::BODY, [&](){
		this->calRealRectPoints();
		this->onCtrlWidgetBodyChange();

		onTextChange();
	});

	_notify->addListen(NodeNotifyType::TEXT, [&](){

		this->onTextChange();
	});	

	return true;
}

void CtrlText::setFontPath(const std::string& fonturl)
{
	_textDefine.filepath = fonturl;

	this->notify(NodeNotifyType::TEXT);
}

const std::string& CtrlText::getFontPath() const
{
	return _textDefine.filepath;
}

void CtrlText::setFontSize(float size)
{
	_textDefine.fontSize = size;

	this->notify(NodeNotifyType::TEXT);
}

float CtrlText::getFontSize() const
{
	return _textDefine.fontSize;
}

void CtrlText::setHorizontalDistance(float distance)
{
	_textDefine.horizontalDistance = distance;

	this->notify(NodeNotifyType::TEXT);
}

float CtrlText::getHorizontalDistance() const
{
	return _textDefine.horizontalDistance;
}

void CtrlText::setVerticalDistance(float distance)
{
	_textDefine.verticalDistance = distance;

	this->notify(NodeNotifyType::TEXT);
}

float CtrlText::getVerticalDistance() const
{
	return _textDefine.verticalDistance;
}

void render::CtrlText::setBorder(bool bBorder)
{
	_textDefine.border = bBorder;
	this->notify(NodeNotifyType::TEXT);
}

bool render::CtrlText::isBorder() const
{
	return _textDefine.border;
}

void CtrlText::setString(const std::string& text)
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

sys::HorizontalAlignment CtrlText::getHorizontalAlignment() const
{
	return _textDefine.horizontalAlignment;
}

void CtrlText::setVerticalAlignment(sys::VerticalAlignment alignment)
{
	_textDefine.verticalAlignment = alignment;

	this->notify(NodeNotifyType::TEXT);
}

sys::VerticalAlignment CtrlText::getVerticalAlignment() const
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

math::Size CtrlText::getDimensions() const
{
	return math::Size(_textDefine.width, _textDefine.height);
}

void CtrlText::setTextColor(const phy::Color3B& color)
{
	_textDefine.color = color;
	this->notify(NodeNotifyType::TEXT);
}

const phy::Color3B& render::CtrlText::getTextColor() const
{
	return _textDefine.color;
}

void CtrlText::onTextChange()
{
	float w = 0, h = 0;
	Texture2D* texture = G_TEXTURE_CACHE->createTexture2D(_textDefine);
	if (texture != nullptr)
	{
		w = texture->getWidth();
		h = texture->getHeight();
		this->setTextureWithRect(texture);
	}
	else
	{
		this->setTextureWithRect(nullptr);
	}

	math::Size size = math::Size(w, h);
	math::Vector3 anchor = getAnchorPoint();
	math::Vector3 orgin = getOrgin(size);
	math::Volume volume = math::Volume(w, h);

	VertexTool::setTexture2DVertices(&_rectVertex, orgin, volume, anchor);

	updateCtrlFrameMeshData();
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




