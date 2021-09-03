#include "Texture.h"
#include <exception>
#include "Graphic/import.h"
#include "Sampler.h"
#include "TextureCache.h"
using namespace render;

Texture::~Texture()
{
	SAFE_RELEASE(_sampler);
	this->releaseTexture();
}

void render::Texture::setTexParameter(TextureParameter name, int value)
{
	GLTexture::setTexParameter(_textureTarget, name, value);
}

void render::Texture::setTexParameter(TextureParameter name, const float* value)
{
	GLTexture::setTexParameter(_textureTarget, name, value);
}

void render::Texture::setTexParameter(TextureParameter name, const int* value)
{
	GLTexture::setTexParameter(_textureTarget, name, value);
}

void render::Texture::setTexParameter(TextureParameter name, float value)
{
	GLTexture::setTexParameter(_textureTarget, name, value);
}

void render::Texture::setTextureParameter(TextureParameter name, int value)
{
	GLTexture::setTextureParameter(_textureID, name, value);
}

void render::Texture::setTextureParameter(TextureParameter name, const float* value)
{
	GLTexture::setTextureParameter(_textureID, name, value);
}

void render::Texture::setTextureParameter(TextureParameter name, const uint32_t* value)
{
	GLTexture::setTextureParameter(_textureID, name, value);
}

void render::Texture::setTextureParameter(TextureParameter name, const int* value)
{
	GLTexture::setTextureParameter(_textureID, name, value);
}

void render::Texture::setTextureParameter(TextureParameter name, float value)
{
	GLTexture::setTextureParameter(_textureID, name, value);
}

bool render::Texture::isValid() const
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

void render::Texture::activeTexture(ActiveTextureName unit)
{
	GLTexture::activeTexture(unit);
}

void render::Texture::activeTexture(uint32_t unit)
{
	GLTexture::activeTexture((ActiveTextureName)((uint32_t)ActiveTextureName::TEXTURE0 + unit));
}

void render::Texture::bindTextureUnit(uint32_t unit)
{
	GLTexture::bindTextureUnit(unit, _textureID);
}

void render::Texture::enableTextureWithSampler(uint32_t unit)
{
	GLDebug::showError();
	GLState::enable((EnableMode)getTextureTarget());
	GLDebug::showError();
	this->activeTexture(unit);
	GLDebug::showError();
	this->bindSampler(unit);
	GLDebug::showError();
	this->bindTexture();
}

void render::Texture::enableTexture(uint32_t unit)
{
	GLState::enable((EnableMode)getTextureTarget());
	this->activeTexture(unit);
	GLDebug::showError();
	this->bindTexture();
	this->applyTextureSetting();
}

void render::Texture::setTextureSetting(const TextureSetting& setting)
{
	_textureSettings = setting;
}

const TextureSetting& render::Texture::getTextureSetting() const
{
	return _textureSettings;
}

TextureSetting& render::Texture::getTextureSetting()
{
	return _textureSettings;
}

void render::Texture::applyTextureSettingWithSampler()
{
	if (_sampler == nullptr)
	{
		return;
	}

	_sampler->apply(_textureSettings);
}

void render::Texture::applyTextureSetting()
{
	this->setTexParameter(TextureParameter::TEXTURE_MIN_FILTER, (int)_textureSettings.minFilter);
	GLDebug::showError();
	this->setTexParameter(TextureParameter::TEXTURE_MAG_FILTER, (int)_textureSettings.magFilter);
	GLDebug::showError();
	this->setTexParameter(TextureParameter::TEXTURE_WRAP_S, (int)_textureSettings.wrapS);
	GLDebug::showError();
	this->setTexParameter(TextureParameter::TEXTURE_WRAP_T, (int)_textureSettings.wrapT);
	GLDebug::showError();
	this->setTexParameter(TextureParameter::TEXTURE_WRAP_R, (int)_textureSettings.wrapR);
	GLDebug::showError();
}

void render::Texture::bindSampler(uint32_t unit)
{
	if (_sampler == nullptr)
	{
		return;
	}
	_sampler->bindTexture(unit);
}

void render::Texture::getTextureImage(int level, TextureExternalFormat format, TextureExternalDataType type, int size, void* pixels)
{
	GLTexture::getTextureImage(_textureID, level, format, type, size, pixels);
}

void render::Texture::generateTextureMipMap()
{
	if (getTextureTarget() != TextureTarget::TEXTURE_1D
		|| getTextureTarget() != TextureTarget::TEXTURE_2D
		|| getTextureTarget() != TextureTarget::TEXTURE_3D
		|| getTextureTarget() != TextureTarget::TEXTURE_1D_ARRAY
		|| getTextureTarget() != TextureTarget::TEXTURE_2D_ARRAY
		|| getTextureTarget() != TextureTarget::TEXTURE_CUBE_MAP)
	{
		return;
	}

	GLTexture::generateTextureMipmap(_textureID);
}

void render::Texture::getTextureFormat(sys::ImageDataFormat imgFormat, TextureExternalFormat& format, TextureInternalSizedFormat& internalFormat, int& size)
{
	switch (imgFormat)
	{
	case sys::ImageDataFormat::RED:
	{
		format = TextureExternalFormat::RED;
		internalFormat = TextureInternalSizedFormat::R8;
		size = 1;
	}
	break;
	case sys::ImageDataFormat::RG:
	{
		format = TextureExternalFormat::RG;
		internalFormat = TextureInternalSizedFormat::RG8;
		size = 2;
	}
	break;
	case sys::ImageDataFormat::RGB:
	{
		format = TextureExternalFormat::RGB;
		internalFormat = TextureInternalSizedFormat::RGB8;
		size = 3;
	}
	break;
	case sys::ImageDataFormat::RGBA:
	{
		format = TextureExternalFormat::RGBA;
		internalFormat = TextureInternalSizedFormat::RGBA8;
		size = 4;
	}
	break;
	case sys::ImageDataFormat::BGR:
	{
		format = TextureExternalFormat::BGR;
		internalFormat = TextureInternalSizedFormat::RGB8;
		size = 3;
	}
	break;
	case sys::ImageDataFormat::BGRA:
	{
		format = TextureExternalFormat::BGRA;
		internalFormat = TextureInternalSizedFormat::RGBA8;
		size = 4;
	}
	break;
	default:
		break;
	}
}

bool render::Texture::getImageDetail(sys::ImageDetail& detail, TextureExternalFormat format)
{
	int nUnitSize = 0;
	sys::ImageDataFormat dataFormat;
	getImageFormat(format, nUnitSize, dataFormat);
	if (nUnitSize == 0)
	{
		return false;
	}

	int width = getWidth();
	int height = getHeight();
	sys::ImageDataFormat dateFormat = sys::ImageDataFormat::NONE;
	this->bindTexture();
	if (width == 0)
	{
		GLTexture::getTextureParameter(getTextureID(), GetTextureParameter::TEXTURE_WIDTH, &width);
		GLDebug::showError();
		if (width == 0)
		{
			this->unbindTexture();
			return false;
		}
	}
	if (height == 0)
	{
		GLTexture::getTextureParameter(getTextureID(), GetTextureParameter::TEXTURE_HEIGHT, &height);
		GLDebug::showError();
		if(height == 0)
		{
			this->unbindTexture();
			return false;
		}
	}
	int bufferSize = width * height * nUnitSize * sizeof(uint8_t);
	uint8_t* buffer = (uint8_t*)malloc(bufferSize);
	GLTexture::getTextureImage(getTextureID(), 0, format, TextureExternalDataType::UNSIGNED_BYTE, bufferSize, buffer);
	GLDebug::showError();
	this->unbindTexture();

	detail.setDataFormat(dataFormat);
	detail.setPixels(buffer, width, height, nUnitSize);

	return true;
}

bool render::Texture::getImageFormat(TextureExternalFormat format, int& nUnitSize, sys::ImageDataFormat& dataFormat)
{
	nUnitSize = 0;
	dataFormat = sys::ImageDataFormat::NONE;
	switch (format)
	{
	case TextureExternalFormat::RED:
	{
		nUnitSize = 1;
		dataFormat = sys::ImageDataFormat::RED;
	}
	break;
	case TextureExternalFormat::RG:
	{
		nUnitSize = 2;
		dataFormat = sys::ImageDataFormat::RG;
	}
	break;
	case TextureExternalFormat::RGB:
	{
		nUnitSize = 3;
		dataFormat = sys::ImageDataFormat::RGB;
	}
	break;
	case TextureExternalFormat::BGR:
	{
		nUnitSize = 3;
		dataFormat = sys::ImageDataFormat::BGR;
	}
		break;
	case TextureExternalFormat::RGBA:
	{
		nUnitSize = 4;
		dataFormat = sys::ImageDataFormat::RGBA;
	}
		break;
	case TextureExternalFormat::BGRA:
	{
		nUnitSize = 4;
		dataFormat = sys::ImageDataFormat::BGRA;
	}
		break;
	case TextureExternalFormat::DEPTH_COMPONENT:
	{
		nUnitSize = 4;
		dataFormat = sys::ImageDataFormat::RGBA;
	}
		break;
	case TextureExternalFormat::DEPTH_STENCIL:
	{
		nUnitSize = 4;
		dataFormat = sys::ImageDataFormat::RGBA;
	}
		break;
	default:
		return false;
		break;
	}

	return true;
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

	G_TEXTURE_CACHE->removeTexture(this);
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
	_sampler = CREATE_OBJECT(Sampler);
	SAFE_RETAIN(_sampler);

	_textureTarget = target;
	this->initTexture();
}

render::Texture::Texture()
{
	_sampler = CREATE_OBJECT(Sampler);
	SAFE_RETAIN(_sampler);

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
