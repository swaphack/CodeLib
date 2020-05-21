#include "Texture.h"
#include <exception>
#include "Graphic/import.h"
using namespace render;

Texture::~Texture()
{
	this->releaseTexture();
}

bool render::Texture::isValid()
{
	if (_textureID == 0)
		return false;
	if (_width == 0 || _height == 0)
		return false;
	return GLTexture::isTexture(_textureID);
}

void render::Texture::bindTexture()
{
	GLTexture::bindTexture(_textureTarget, _textureID);
}

void render::Texture::unbindTexture()
{
	GLTexture::bindTexture(_textureTarget, 0);
}

void render::Texture::bindTextureUnit(uint32_t unit)
{
	GLTexture::bindTextureUnit(unit, _textureID);
}

void render::Texture::getTextureImage(int level, TextureDataFormat format, TextureDataType type, int size, void* pixels)
{
	GLTexture::getTextureImage(_textureID, level, format, type, size, pixels);
}

void render::Texture::getTextureFormat(sys::ImageDataFormat imgFormat, TextureDataFormat& format, TextureInternalFormat& internalFormat)
{
	switch (imgFormat)
	{
	case sys::ImageDataFormat::RED:
	{
		format = TextureDataFormat::RED;
		internalFormat = TextureInternalFormat::RED;
	}
	break;
	case sys::ImageDataFormat::RG:
	{
		format = TextureDataFormat::RG;
		internalFormat = TextureInternalFormat::RG;
	}
	break;
	case sys::ImageDataFormat::RGB:
	{
		format = TextureDataFormat::RGB;
		internalFormat = TextureInternalFormat::RGB;
	}
	break;
	case sys::ImageDataFormat::RGBA:
	{
		format = TextureDataFormat::RGBA;
		internalFormat = TextureInternalFormat::RGBA;
	}
	break;
	case sys::ImageDataFormat::BGR:
	{
		format = TextureDataFormat::BGR;
		internalFormat = TextureInternalFormat::RGB;
	}
	break;
	case sys::ImageDataFormat::BGRA:
	{
		format = TextureDataFormat::BGRA;
		internalFormat = TextureInternalFormat::RGBA;
	}
	break;
	default:
		break;
	}
}

void render::Texture::getStorageTextureFormat(sys::ImageDataFormat imgFormat, TextureDataFormat& format, TextureInternalFormat& internalFormat)
{
	switch (imgFormat)
	{
	case sys::ImageDataFormat::RED:
	{
		format = TextureDataFormat::RED;
		internalFormat = TextureInternalFormat::R8;
	}
	break;
	case sys::ImageDataFormat::RG:
	{
		format = TextureDataFormat::RG;
		internalFormat = TextureInternalFormat::RG8;
	}
	break;
	case sys::ImageDataFormat::RGB:
	{
		format = TextureDataFormat::RGB;
		internalFormat = TextureInternalFormat::RGB8;
	}
	break;
	case sys::ImageDataFormat::RGBA:
	{
		format = TextureDataFormat::RGBA;
		internalFormat = TextureInternalFormat::RGBA8;
	}
	break;
	case sys::ImageDataFormat::BGR:
	{
		format = TextureDataFormat::BGR;
		internalFormat = TextureInternalFormat::RGB8;
	}
	break;
	case sys::ImageDataFormat::BGRA:
	{
		format = TextureDataFormat::BGRA;
		internalFormat = TextureInternalFormat::RGBA8;
	}
	break;
	default:
		break;
	}
}

void render::Texture::initTexture()
{
	if (_textureTarget == TextureTarget::NONE)
	{
		GLTexture::genTextures(1, &_textureID);
	}
	else
	{
		GLTexture::createTextures(_textureTarget, 1, &_textureID);
	}
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

render::Texture::Texture(TextureTarget target)
{
	_textureTarget = target;
	this->initTexture();
}

render::Texture::Texture()
{
	this->initTexture();
}

uint32_t render::Texture::getTextureID() const
{
	return _textureID;
}

TextureTarget render::Texture::getTextureTarget()
{
	return _textureTarget;
}
