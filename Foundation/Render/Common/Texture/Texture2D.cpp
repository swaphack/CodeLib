#include "Texture2D.h"
#include "Graphic/import.h"
#include "TextureCache.h"
render::Texture2D::Texture2D()
	:Texture(TextureTarget::TEXTURE_2D)
{
}

render::Texture2D::~Texture2D()
{
}

void render::Texture2D::setTextureStorage(int levels, TextureInternalSizedFormat internalFormat, int width, int height)
{
#if USE_NEW_TEXTURE_FUNCTION
	GLTexture::setTextureStorage2D(getTextureID(), levels, internalFormat, width, height);
#else
	GLTexture::setTexStorage2D((TextureTarget2D)getTextureTarget(), levels, internalFormat, width, height);
#endif
}

void render::Texture2D::setTextureSubImage(int level, int xoffset, int yoffset, int width, int height, TextureExternalFormat format, TextureExternalDataType type, const void* pixels)
{
#if USE_NEW_TEXTURE_FUNCTION
	GLTexture::setTextureSubImage2D(getTextureID(), level, xoffset, yoffset, width, height, format, type, pixels);
#else
	GLTexture::setTexSubImage2D((TextureTarget2D)getTextureTarget(), level, xoffset, yoffset, width, height, format, type, pixels);
#endif
}

void render::Texture2D::compressedTextureImage(int level, TextureCompressedInternalFormat format, int width, int height, int imageSize, const void* data)
{
	GLTexture::compressedTexImage2D((TextureTarget2D)getTextureTarget(), level, format, width, height, imageSize, data);
}

void render::Texture2D::compressedTextureSubImage(int level, int xoffset, int yoffset, int width, int height, TextureCompressedInternalFormat format, int imageSize, const void* data)
{
#if USE_NEW_TEXTURE_FUNCTION
	GLTexture::compressedTextureSubImage2D(getTextureID(), level, xoffset, yoffset, width, height, format, imageSize, data);
#else
	GLTexture::compressedTexSubImage2D((TextureTarget2D)getTextureTarget(), level, xoffset, yoffset, width, height, format, imageSize, data);
#endif
}

void render::Texture2D::setTextureImage(int level, TextureInternalSizedFormat internalFormat, int width, int height, int border, TextureExternalFormat format, TextureExternalDataType type, const void* data)
{
	GLTexture::setTexImage2D((TextureTarget2D)getTextureTarget(), level, internalFormat, width, height, border, format, type, data);
}

void render::Texture2D::load(const sys::ImageDetail* image, const TextureSetting& setting /*= TextureSetting2D()*/)
{
	if (image == nullptr || image->getPixels() == nullptr)
	{
		return;
	}

	this->setTextureSetting(setting);
	GLDebug::showError();

	this->setWidth(image->getWidth());
	this->setHeight(image->getHeight());

	/* Generate texture */
	this->bindTexture();
	GLDebug::showError();
	
	int size = 0;

	TextureExternalFormat format = TextureExternalFormat::RGBA;
	TextureInternalSizedFormat internalFormat = TextureInternalSizedFormat::RGBA8;
	getTextureFormat(image->getDataFormat(), format, internalFormat, size);

	int len = size * getWidth();
	if ((len % 4 == 3) || (len % 4 == 0))
	{
		GLState::setPixelStore(PixelStore::UNPACK_ALIGNMENT, 4);
	}
	else
	{
		GLState::setPixelStore(PixelStore::UNPACK_ALIGNMENT, 2);
	}

#if USE_TEXTURE_STORAGE
	this->setTextureStorage(1, internalFormat, getWidth(), getHeight());
	this->setTextureSubImage(0, 0, 0, getWidth(), getHeight(), format, TextureExternalDataType::UNSIGNED_BYTE, image->getPixels());
#else
	this->setTextureImage(0, internalFormat,
		getWidth(), getHeight(), 0, format,
		TextureExternalDataType::UNSIGNED_BYTE, image->getPixels());
#endif

	GLTexture::generateMipmap((MipmapTextureTarget)getTextureTarget());
	GLDebug::showError();
	this->unbindTexture();
	GLDebug::showError();
}