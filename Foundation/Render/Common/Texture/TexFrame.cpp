#include "TexFrame.h"
#include "Texture.h"

using namespace render;


TexFrame::TexFrame()
: _texture(nullptr)
{
	_rect.setOrigin(0, 0);
	_rect.setSize(1, 1);
}

TexFrame::~TexFrame()
{
	SAFE_RELEASE(_texture);
}

void TexFrame::setTexture(const Texture* texture)
{
	if (texture == nullptr)
	{
		return;
	}

	SAFE_RELEASE(_texture);
	_texture = (Texture*)texture;
	SAFE_RETAIN(_texture);
}

const Texture* TexFrame::getTexture() const
{
	return _texture;
}

void render::TexFrame::setName(const std::string& name)
{
	_name = name;
}

const std::string& render::TexFrame::getName() const
{
	return _name;
}

void TexFrame::setRect(const math::Rect& rect)
{
	_rect = rect;
}

const math::Rect& TexFrame::getRect() const
{
	return _rect;
}

void render::TexFrame::setRotate(bool bRotated)
{
	_rotate = bRotated;
}

bool render::TexFrame::isRotated() const
{
	return _rotate;
}

math::Size render::TexFrame::getFrameSize() const
{
	if (_texture == nullptr)
	{
		return math::Size();
	}
	
	return math::Size(_rect.getWidth() * _texture->getWidth(), _rect.getHeight() * _texture->getHeight());
}

math::Vector2 render::TexFrame::getFramePosition() const
{
	if (_texture == nullptr)
	{
		return math::Vector2();
	}

	return math::Size(_rect.getMinX() * _texture->getWidth(), _rect.getMinY() * _texture->getHeight());
}

void TexFrame::loadTexture(const Texture* texture, const math::Rect& rect)
{
	if (texture == nullptr)
	{
		return;
	}

	this->setTexture(texture);
	this->setRect(rect);
}

void TexFrame::loadTexture(const Texture* texture)
{
	this->loadTexture(texture, math::Rect(0.0f, 0.0f, 1.0f, 1.0f));
}

TexFrame& TexFrame::operator=(const TexFrame& value)
{
	this->setTexture(value.getTexture());
	this->setRect(value.getRect());

	return *this;
}
