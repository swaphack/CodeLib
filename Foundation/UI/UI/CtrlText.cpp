#include "CtrlText.h"
#include "Common/Texture/TextureCache.h"
#include "Common/Texture/Texture.h"
#include "Common/Texture/Texture2D.h"
#include "Common/Tool/VertexTool.h"
#include "Common/Mesh/import.h"

using namespace ui;
using namespace render;

CtrlText::CtrlText()
{
	_texture2D = CREATE_NODE(render::DrawTexture2D);
	this->addChild(_texture2D);

	this->setTextHorizontalAlignment(sys::HorizontalAlignment::CENTER);
	this->setTextVerticalAlignment(sys::VerticalAlignment::MIDDLE);
}

CtrlText::~CtrlText()
{
}

bool CtrlText::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}

	addNotifyListener(render::NodeNotifyType::TEXT, [this](){
		onTextTextureChange();
		onTextBodyChange();
	});	

	addNotifyListener(render::NodeNotifyType::BODY, [this]() {
		onTextBodyChange();
	});

	return true;
}

void CtrlText::setFontPath(const std::string& filepath)
{
	_textDefine.filepath = filepath;

	this->notify(render::NodeNotifyType::TEXT);
}

const std::string& CtrlText::getFontPath() const
{
	return _textDefine.filepath;
}

void CtrlText::setFontSize(float size)
{
	_textDefine.fontSize = size;

	this->notify(render::NodeNotifyType::TEXT);
}

float CtrlText::getFontSize() const
{
	return _textDefine.fontSize;
}

void CtrlText::setHorizontalDistance(float distance)
{
	_textDefine.horizontalDistance = distance;

	this->notify(render::NodeNotifyType::TEXT);
}

float CtrlText::getHorizontalDistance() const
{
	return _textDefine.horizontalDistance;
}

void CtrlText::setVerticalDistance(float distance)
{
	_textDefine.verticalDistance = distance;

	this->notify(render::NodeNotifyType::TEXT);
}

float CtrlText::getVerticalDistance() const
{
	return _textDefine.verticalDistance;
}

void ui::CtrlText::setBorder(bool bBorder)
{
	_textDefine.border = bBorder;
	this->notify(render::NodeNotifyType::TEXT);
}

bool ui::CtrlText::isBorder() const
{
	return _textDefine.border;
}

void CtrlText::setString(const std::string& text)
{
	TextProtocol::setString(text);
	_textDefine.text = text;

	this->notify(render::NodeNotifyType::TEXT);
}

void CtrlText::setTextHorizontalAlignment(sys::HorizontalAlignment alignment)
{
	_textDefine.horizontalAlignment = alignment;

	this->notify(render::NodeNotifyType::TEXT);
}

sys::HorizontalAlignment CtrlText::getTextHorizontalAlignment() const
{
	return _textDefine.horizontalAlignment;
}

void CtrlText::setTextVerticalAlignment(sys::VerticalAlignment alignment)
{
	_textDefine.verticalAlignment = alignment;

	this->notify(render::NodeNotifyType::TEXT);
}

sys::VerticalAlignment CtrlText::getTextVerticalAlignment() const
{
	return _textDefine.verticalAlignment;
}

void CtrlText::setDimensions(float width, float height)
{
	_textDefine.width = width;
	_textDefine.height = height;

	this->notify(render::NodeNotifyType::TEXT);
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
	this->notify(render::NodeNotifyType::TEXT);
}

const phy::Color3B& ui::CtrlText::getTextColor() const
{
	return _textDefine.color;
}

void ui::CtrlText::setTexShaderProgram(render::ShaderProgram* shaderProgram)
{
	if (_texture2D)
	{
		_texture2D->setShaderProgram(shaderProgram);
	}
}

void ui::CtrlText::setCamera(const render::Camera* camera)
{
	CtrlWidget::setCamera(camera);

	if (_texture2D)
	{
		_texture2D->setCamera(camera);
	}
}

void ui::CtrlText::setUseDesignCamera(bool bUsed)
{
	CtrlWidget::setUseDesignCamera(bUsed);

	if (_texture2D)
	{
		_texture2D->setUseDesignCamera(bUsed);
	}
}

render::DrawTexture2D* ui::CtrlText::getRenderNode() const
{
	return _texture2D;
}

void ui::CtrlText::onTextBodyChange()
{
	if (_texture2D == nullptr)
	{
		return;
	}

	float w = _texture2D->getWidth();
	float h = _texture2D->getHeight();

	if (_volume.getWidth() != 0 && _volume.getHeight() != 0)
	{
		math::Size size = math::Size(w, h);
		math::Vector3 anchor;
		math::Vector3 orgin;

		getOrgin(size, anchor, orgin);

		_texture2D->setPosition(orgin);
		_texture2D->setAnchorPoint(anchor);
	}
}

void CtrlText::onTextTextureChange()
{
	render::Texture2D* texture = G_TEXTURE_CACHE->createTexture2D(_textDefine);
	_texture2D->cleanTexture();
	_texture2D->loadTexture(texture);
	_texture2D->setNativeTextureSize();
}

void ui::CtrlText::getOrgin(const math::Size& size, math::Vector3& anchor, math::Vector3& position)
{	
	math::Volume volume = math::Volume(size.getWidth(), size.getHeight());
	
	if (_textDefine.verticalAlignment == sys::VerticalAlignment::BOTTOM)
	{
		position.setY(_volume.getHeight() * (0.0f - _anchor.getY()));
	}
	else if (_textDefine.verticalAlignment == sys::VerticalAlignment::MIDDLE)
	{
		anchor.setY(0.5f);
		position.setY(_volume.getHeight() * (0.5f - _anchor.getY()));
	}
	else if (_textDefine.verticalAlignment == sys::VerticalAlignment::TOP)
	{
		anchor.setY(1.0f);
		position.setY(_volume.getHeight() * (1.0f - _anchor.getY()));
	}

	if (_textDefine.horizontalAlignment == sys::HorizontalAlignment::LEFT)
	{
		anchor.setX(0.0f);
		position.setX(_volume.getWidth() * (0.0f - _anchor.getX()));
	}
	else if (_textDefine.horizontalAlignment == sys::HorizontalAlignment::CENTER)
	{
		anchor.setX(0.5f);
		position.setX(_volume.getWidth() * (0.5f - _anchor.getX()));
	}
	else if (_textDefine.horizontalAlignment == sys::HorizontalAlignment::RIGHT)
	{
		anchor.setX(1.0f);
		position.setX(_volume.getWidth() * (1.0f - _anchor.getX()));
	}
}




