#include "TextureBufferObject.h"
#include "Graphic/import.h"
#include "Common/Buffer/Buffer.h"
#include "Common/Texture/Texture.h"

using namespace render;

render::TextureBufferObject::TextureBufferObject()
{
	this->initTBO();
}

render::TextureBufferObject::~TextureBufferObject()
{
	SAFE_RELEASE(_texture);
	this->relaseTBO();
}

void render::TextureBufferObject::setTexture(Texture* texture)
{
	SAFE_RELEASE(_texture);
	SAFE_RETAIN(texture);
	_texture = texture;
}

render::Texture* render::TextureBufferObject::getTexture() const
{
	return _texture;
}

void render::TextureBufferObject::bindBuffer()
{
	if (getBuffer() == nullptr)
	{
		return;
	}
	GLBufferObjects::bindBuffer(BufferTarget::TEXTURE_BUFFER, getBuffer()->getBufferID());
}

void render::TextureBufferObject::bindTextureUnit(int32_t index)
{
	if (getTexture() == nullptr)
	{
		return;
	}
	GLTexture::bindTextureUnit(index, getTexture()->getTextureID());
}

void render::TextureBufferObject::bindTexture()
{
	if (getTexture() == nullptr)
	{
		return;
	}
	getTexture()->bindTexture();
}

void render::TextureBufferObject::setFormat(TexSizedInternalFormat format)
{
	if (getBuffer() == nullptr)
	{
		return;
	}
	GLTexture::setTexBuffer(format, getBuffer()->getBufferID());
}

void render::TextureBufferObject::initTBO()
{
}

void render::TextureBufferObject::relaseTBO()
{
}

