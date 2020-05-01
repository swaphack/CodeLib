#include "Texture.h"
#include <exception>
#include "Graphic/GLAPI/GLTexture.h"
#include "TextureCache.h"
#include "Resource/Detail/ImageDetail.h"
using namespace render;


Texture::Texture()
:_textureID(0)
,_width(0)
,_height(0)
,_depth(0)
{
}

Texture::~Texture()
{
	G_TEXTURE_CACHE->removeTexture(this);
	GLTexture::deleteTexture(_textureID);
	_textureID = 0;
}

bool render::Texture::isEnable()
{
	if (_textureID == 0)
		return false;
	if (_width == 0 || _height == 0)
		return false;
	return true;
}

void render::Texture::setDepth(uint32_t val)
{
	_depth = val;
}

uint32_t render::Texture::getDepth() const
{
	return _depth;
}

void render::Texture::setHeight(uint32_t val)
{
	_height = val;
}

uint32_t render::Texture::getHeight() const
{
	return _height;
}

void render::Texture::setWidth(uint32_t val)
{
	_width = val;
}

int render::Texture::getWidth() const
{
	return _width;
}

uint32_t render::Texture::getTextureID() const
{
	return _textureID;
}

//////////////////////////////////////////////////////////////////////////
void Texture2D::load(const ImageDetail* image)
{
	if (image == nullptr || image->getPixels() == nullptr)
	{
		return;
	}

	GLuint tex_id = GLTexture::genTexture();

	/* Generate texture */
	GLTexture::bindTexture2D(tex_id);

	/* Setup some parameters for texture filters and mipmapping */
	GLTexture::setTexParameterMinFilter2D(TextureMinFilter::LINEAR);
	GLTexture::setTexParameterMagFilter2D(TextureMagFilter::LINEAR);
	GLTexture::setTexParameterWrapS2D(TextureWrapMode::CLAMP);
	GLTexture::setTexParameterWrapT2D(TextureWrapMode::CLAMP);

	GLTexture::setTexImage2D(TexImageTarget2D::TEXTURE_2D,  0, image->getInternalFormat(),
		image->getWidth(), image->getHeight(), 0, image->getFormat(),
		TexImageDataType::UNSIGNED_BYTE, image->getPixels());
	
	_textureID = tex_id;
	_width = image->getWidth();
	_height = image->getHeight();
}
