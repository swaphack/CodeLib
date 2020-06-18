#include "TextureBufferObject.h"
#include "Common/Texture/Texture.h"
#include "Common/Buffer/Buffer.h"
#include "Graphic/import.h"

render::TextureBufferObject::TextureBufferObject()
{
	_texture = CREATE_OBJECT(Texture);
	SAFE_RETAIN(_texture);
}

render::TextureBufferObject::~TextureBufferObject()
{
	SAFE_RELEASE(_texture);
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

void render::TextureBufferObject::bindTexture()
{
	if (_texture == nullptr)
	{
		return;
	}

	GLTexture::bindTexture(TextureTarget::TEXTURE_BUFFER, _texture->getTextureID());
}

void render::TextureBufferObject::setTexBuffer(TexSizedInternalFormat internalFormat)
{
	GLTexture::setTexBuffer(internalFormat, getBuffer()->getBufferID());
}
