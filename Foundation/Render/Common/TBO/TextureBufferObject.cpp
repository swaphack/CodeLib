#include "TextureBufferObject.h"
#include "Common/Texture/Texture.h"
#include "Common/Buffer/TextureBuffer.h"
#include "Graphic/import.h"

render::TextureBufferObject::TextureBufferObject()
{
	this->initTBO();
}

render::TextureBufferObject::~TextureBufferObject()
{
	this->releaseTBO();
}

void render::TextureBufferObject::setTexture(Texture* texture)
{
	SAFE_RETAIN(texture);
	SAFE_RELEASE(_texture);

	_texture = texture;
}

render::Texture* render::TextureBufferObject::getTexture() const
{
	return _texture;
}

void render::TextureBufferObject::setTextureBuffer(NoNamedBuffer* buffer)
{
	_textureBuffer = buffer;
}

render::NoNamedBuffer* render::TextureBufferObject::getTextureBuffer() const
{
	return _textureBuffer;
}

void render::TextureBufferObject::bindTexture()
{
	if (_texture)
	{
		_texture->bindTexture();
	}
}

void render::TextureBufferObject::unbindTexture()
{
	if (_texture)
	{
		_texture->unbindTexture();
	}
}

void render::TextureBufferObject::bindTextureBuffer()
{
	if (_texture)
	{
		GLTexture::bindTexture(TextureTarget::TEXTURE_BUFFER, _texture->getTextureID());
	}
}

void render::TextureBufferObject::unbindTextureBuffer()
{
	if (_textureBuffer)
	{
		GLTexture::bindTexture(TextureTarget::TEXTURE_BUFFER, 0);
	}
}

void render::TextureBufferObject::initTBO()
{
	_texture = CREATE_OBJECT(Texture);
	SAFE_RETAIN(_texture);

	_textureBuffer = CREATE_OBJECT(TextureBuffer);
	SAFE_RETAIN(_textureBuffer);
}

void render::TextureBufferObject::releaseTBO()
{
	SAFE_RELEASE(_texture);
	SAFE_RELEASE(_textureBuffer);
}

void render::TextureBufferObject::setTexBufferFromat(TexSizedInternalFormat internalFormat)
{
	if (_textureBuffer)
	{
		GLTexture::setTexBuffer(internalFormat, _textureBuffer->getBufferID());
	}
}
