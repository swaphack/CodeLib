#include "TextureBuffer.h"
#include "Common/Texture/Texture.h"
#include "Graphic/import.h"

render::TextureBuffer::TextureBuffer()
{
	this->setBufferTarget(BufferTarget::TEXTURE_BUFFER);
}

render::TextureBuffer::~TextureBuffer()
{
	SAFE_RELEASE(_texture);
}

void render::TextureBuffer::setTexture(Texture* texture)
{
	SAFE_RETAIN(texture);
	SAFE_RELEASE(_texture);

	_texture = texture;
}

render::Texture* render::TextureBuffer::getTexture() const
{
	return _texture;
}

void render::TextureBuffer::bindTexture()
{
	if (_texture == nullptr)
	{
		return;
	}

	GLTexture::bindTexture((TextureTarget)getBufferTarget(), _texture->getTextureID());
}

void render::TextureBuffer::setTexBuffer(TexSizedInternalFormat internalFormat)
{
	GLTexture::setTexBuffer(internalFormat, getBufferID());
}
