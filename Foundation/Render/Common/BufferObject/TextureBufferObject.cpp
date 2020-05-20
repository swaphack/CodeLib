#include "TextureBufferObject.h"
#include "Graphic/import.h"
#include "Common/Buffer/Buffer.h"

using namespace render;

render::TextureBufferObject::TextureBufferObject()
{
	this->initTBO();
}

render::TextureBufferObject::~TextureBufferObject()
{
	this->relaseTBO();
}

uint32_t render::TextureBufferObject::getTextureID() const
{
	return _textureID;
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
	GLTexture::bindTextureUnit(index, _textureID);
}

void render::TextureBufferObject::bindTexture(TextureTarget target)
{
	GLTexture::bindTexture(target, _textureID);
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
	_textureID = GLTexture::genTexture();
}

void render::TextureBufferObject::relaseTBO()
{
	GLTexture::deleteTexture(_textureID);
}

