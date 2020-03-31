#include "TexFrame.h"
#include "Texture.h"

using namespace render;


TexFrame::TexFrame()
: _texture(nullptr)
{
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

void TexFrame::setRect(const math::Rect& rect)
{
	_rect = rect;
}

const math::Rect& TexFrame::getRect() const
{
	return _rect;
}

void TexFrame::setTextureWithRect(const Texture* texture, const math::Rect& rect)
{
	if (texture == nullptr)
	{
		return;
	}

	this->setTexture(texture);
	this->setRect(rect);
}

void TexFrame::setTextureWithRect(const Texture* texture)
{
	this->setTextureWithRect(texture, math::Rect(0.0f, 0.0f, 1.0f * texture->getWidth(), 1.0f * texture->getHeight()));
}

TexFrame& TexFrame::operator=(const TexFrame& value)
{
	this->setTexture(value.getTexture());
	this->setRect(value.getRect());

	return *this;
}
