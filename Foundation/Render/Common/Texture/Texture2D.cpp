#include "Texture2D.h"
#include "Graphic/import.h"

render::Texture2D::Texture2D()
	:Texture(TextureTarget::TEXTURE_2D)
{
}

render::Texture2D::~Texture2D()
{

}

void render::Texture2D::setTextureStorage(int levels, TextureInternalFormat internalFormat, int width, int height)
{
	GLTexture::setTexStorage2D((TextureTarget2D)getTextureTarget(), levels, internalFormat, width, height);
}

void render::Texture2D::setTextureSubImage(int level, int xoffset, int yoffset, int width, int height, TextureDataFormat format, TextureDataType type, const void* pixels)
{
	GLTexture::setTexSubImage2D((TextureTarget2D)getTextureTarget(), level, xoffset, yoffset, width, height, format, type, pixels);
}

void render::Texture2D::setTextureImage(int level, TextureInternalFormat internalFormat, int width, int height, int border, TextureDataFormat format, TextureDataType type, const void* data)
{
	GLTexture::setTexImage2D((TextureTarget2D)getTextureTarget(), level, internalFormat, width, height, border, format, type, data);
}

void render::Texture2D::load(const sys::ImageDetail* image, const TextureSetting2D& setting /*= TextureSetting2D()*/)
{
	if (image == nullptr || image->getPixels() == nullptr)
	{
		return;
	}

	this->setWidth(image->getWidth());
	this->setHeight(image->getHeight());

	/* Generate texture */
	this->bindTexture();
	GLDebug::showError();

	TextureDataFormat format = TextureDataFormat::RGBA;
	TextureInternalFormat internalFormat = TextureInternalFormat::RGBA;
	
	GLDebug::showError();
	{
		getStorageTextureFormat(image->getDataFormat(), format, internalFormat);

		this->setTextureStorage(1, internalFormat, getWidth(), getHeight());
		GLDebug::showError();
		this->setTextureSubImage(0, 0, 0, getWidth(), getHeight(), format, TextureDataType::UNSIGNED_BYTE, image->getPixels());
	}

#if false
	getTextureFormat(image->getDataFormat(), format, internalFormat);
	this->setTextureImage(0, internalFormat,
		image->getWidth(), image->getHeight(), 0, format,
		TextureDataType::UNSIGNED_BYTE, image->getPixels());
#endif
	/* Setup some parameters for texture filters and mipmapping */
	GLTexture::setTexParameterMinFilter2D(setting.minFilter);
	GLTexture::setTexParameterMagFilter2D(setting.magFilter);
	GLTexture::setTexParameterWrapS2D(setting.wrapS);
	GLTexture::setTexParameterWrapT2D(setting.wrapT);

	this->unbindTexture();

	GLDebug::showError();
}