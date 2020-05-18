#include "Texture.h"
#include <exception>
#include "Graphic/GLAPI/GLTexture.h"
#include "TextureCache.h"
using namespace render;


Texture::Texture()
:_textureID(0)
,_width(0)
,_height(0)
,_depth(0)
{
	this->initTexture();
}

Texture::~Texture()
{
	G_TEXTURE_CACHE->removeTexture(this);
	this->releaseTexture();
}

bool render::Texture::isEnable()
{
	if (_textureID == 0)
		return false;
	if (_width == 0 || _height == 0)
		return false;
	return true;
}

void render::Texture::getTextureFormat(sys::ImageDataFormat imgFormat, TexImageDataFormat& format, TexImageInternalFormat& internalFormat)
{
	switch (imgFormat)
	{
	case sys::ImageDataFormat::RED:
	{
		format = TexImageDataFormat::RED;
		internalFormat = TexImageInternalFormat::RED;
	}
	break;
	case sys::ImageDataFormat::RG:
	{
		format = TexImageDataFormat::RG;
		internalFormat = TexImageInternalFormat::RG;
	}
	break;
	case sys::ImageDataFormat::RGB:
	{
		format = TexImageDataFormat::RGB;
		internalFormat = TexImageInternalFormat::RGB;
	}
	break;
	case sys::ImageDataFormat::RGBA:
	{
		format = TexImageDataFormat::RGBA;
		internalFormat = TexImageInternalFormat::RGBA;
	}
	break;
	case sys::ImageDataFormat::BGR:
	{
		format = TexImageDataFormat::BGR;
		internalFormat = TexImageInternalFormat::RGB;
	}
	break;
	case sys::ImageDataFormat::BGRA:
	{
		format = TexImageDataFormat::BGRA;
		internalFormat = TexImageInternalFormat::RGBA;
	}
	break;
	default:
		break;
	}
}

void render::Texture::initTexture()
{
	_textureID = GLTexture::genTexture();
}

void render::Texture::releaseTexture()
{
	GLTexture::deleteTexture(_textureID);
	_textureID = 0;
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
void Texture2D::load(const sys::ImageDetail* image, const TextureSetting2D& setting)
{
	if (image == nullptr || image->getPixels() == nullptr)
	{
		return;
	}


	/* Generate texture */
	GLTexture::bindTexture2D(_textureID);

	/* Setup some parameters for texture filters and mipmapping */
	GLTexture::setTexParameterMinFilter2D(setting.minFilter);
	GLTexture::setTexParameterMagFilter2D(setting.magFilter);
	GLTexture::setTexParameterWrapS2D(setting.wrapS);
	GLTexture::setTexParameterWrapT2D(setting.wrapT);

	TexImageDataFormat format = TexImageDataFormat::RGBA;
	TexImageInternalFormat internalFormat = TexImageInternalFormat::RGBA;
	getTextureFormat(image->getDataFormat(), format, internalFormat);

	GLTexture::setTexImage2D(TexImageTarget2D::TEXTURE_2D,  0, internalFormat,
		image->getWidth(), image->getHeight(), 0, format,
		TexImageDataType::UNSIGNED_BYTE, image->getPixels());
	
	_width = image->getWidth();
	_height = image->getHeight();
}
