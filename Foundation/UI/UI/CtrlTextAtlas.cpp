#include "CtrlTextAtlas.h"
ui::CtrlTextAtlas::CtrlTextAtlas()
{
	this->setTextHorizontalAlignment(sys::HorizontalAlignment::CENTER);
	this->setTextVerticalAlignment(sys::VerticalAlignment::MIDDLE);
}

ui::CtrlTextAtlas::~CtrlTextAtlas()
{
}

bool ui::CtrlTextAtlas::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}

	addNotifyListener(render::NodeNotifyType::TEXT, [this]() {
		onTextTextureChange();
		onTextBodyChange();
	});

	addNotifyListener(render::NodeNotifyType::BODY, [this]() {
		onTextBodyChange();
	});

	return true;
}

void ui::CtrlTextAtlas::setAtlas(const std::string& atlasName)
{
	_textDefine.filepath = atlasName;

	this->notify(render::NodeNotifyType::TEXT);
}

const std::string& ui::CtrlTextAtlas::getAtlasName() const
{
	return _textDefine.filepath;
}

void ui::CtrlTextAtlas::setString(const std::string& text)
{
	TextProtocol::setString(text);
	_textDefine.text = text;

	this->notify(render::NodeNotifyType::TEXT);
}

void ui::CtrlTextAtlas::setHorizontalDistance(float distance)
{
	_textDefine.horizontalDistance = distance;

	this->notify(render::NodeNotifyType::TEXT);
}

float ui::CtrlTextAtlas::getHorizontalDistance() const
{
	return _textDefine.horizontalDistance;
}

void ui::CtrlTextAtlas::setVerticalDistance(float distance)
{
	_textDefine.verticalDistance = distance;

	this->notify(render::NodeNotifyType::TEXT);
}

float ui::CtrlTextAtlas::getVerticalDistance() const
{
	return _textDefine.verticalDistance;
}

void ui::CtrlTextAtlas::setBorder(bool bBorder)
{
	_textDefine.border = bBorder;
	this->notify(render::NodeNotifyType::TEXT);
}

bool ui::CtrlTextAtlas::isBorder() const
{
	return _textDefine.border;
}

void ui::CtrlTextAtlas::setTextHorizontalAlignment(sys::HorizontalAlignment alignment)
{
	_textDefine.horizontalAlignment = alignment;

	this->notify(render::NodeNotifyType::TEXT);
}

sys::HorizontalAlignment ui::CtrlTextAtlas::getTextHorizontalAlignment() const
{
	return _textDefine.horizontalAlignment;
}

void ui::CtrlTextAtlas::setTextVerticalAlignment(sys::VerticalAlignment alignment)
{
	_textDefine.verticalAlignment = alignment;

	this->notify(render::NodeNotifyType::TEXT);
}

sys::VerticalAlignment ui::CtrlTextAtlas::getTextVerticalAlignment() const
{
	return _textDefine.verticalAlignment;
}

void ui::CtrlTextAtlas::setDimensions(float width, float height)
{
	_textDefine.size.setWidth(width);
	_textDefine.size.setHeight(height);

	this->notify(render::NodeNotifyType::TEXT);
}

void ui::CtrlTextAtlas::setDimensions(const math::Size& size)
{
	_textDefine.size = size;
	this->notify(render::NodeNotifyType::TEXT);
}

const math::Size& ui::CtrlTextAtlas::getDimensions() const
{
	return _textDefine.size;
}

void ui::CtrlTextAtlas::setTextColor(const phy::Color3B& color)
{
	_textDefine.color = color;
	this->notify(render::NodeNotifyType::TEXT);
}

const phy::Color3B& ui::CtrlTextAtlas::getTextColor() const
{
	return _textDefine.color;
}

void ui::CtrlTextAtlas::setTexShaderProgram(render::ShaderProgram* shaderProgram)
{
}

void ui::CtrlTextAtlas::setCamera(const render::Camera* camera)
{
	CtrlWidget::setCamera(camera);
}

void ui::CtrlTextAtlas::setUseDesignCamera(bool bUsed)
{
	CtrlWidget::setUseDesignCamera(bUsed);
}

void ui::CtrlTextAtlas::getOrgin(const math::Size& size, math::Vector3& anchor, math::Vector3& position)
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

void ui::CtrlTextAtlas::onTextBodyChange()
{
}

void ui::CtrlTextAtlas::onTextTextureChange()
{
}
