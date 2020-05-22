#include "Texture2D.h"
#include "Graphic/import.h"

#define USE_STORAGE true

render::Texture2D::Texture2D()
	:Texture(TextureTarget::TEXTURE_2D)
{
}

render::Texture2D::~Texture2D()
{

}

void render::Texture2D::setTextureStorage(int levels, TextureInternalSizedFormat internalFormat, int width, int height)
{
	GLTexture::setTexStorage2D((TextureTarget2D)getTextureTarget(), levels, internalFormat, width, height);
}

void render::Texture2D::setTextureSubImage(int level, int xoffset, int yoffset, int width, int height, TextureExternalFormat format, TextureExternalDataType type, const void* pixels)
{
	GLTexture::setTexSubImage2D((TextureTarget2D)getTextureTarget(), level, xoffset, yoffset, width, height, format, type, pixels);
}

void render::Texture2D::compressedTextureImage(int level, TextureCompressedInternalFormat format, int width, int height, int imageSize, const void* data)
{
	GLTexture::compressedTexImage2D((TextureTarget2D)getTextureTarget(), level, format, width, height, imageSize, data);
}

void render::Texture2D::compressedTextureSubImage(int level, int xoffset, int yoffset, int width, int height, TextureCompressedInternalFormat format, int imageSize, const void* data)
{
	GLTexture::compressedTexSubImage2D((TextureTarget2D)getTextureTarget(), level, xoffset, yoffset, width, height, format, imageSize, data);
}

void render::Texture2D::setTextureImage(int level, TextureInternalBaseFormat internalFormat, int width, int height, int border, TextureExternalFormat format, TextureExternalDataType type, const void* data)
{
	GLTexture::setTexImage2D((TextureTarget2D)getTextureTarget(), level, internalFormat, width, height, border, format, type, data);
}

void render::Texture2D::load(const sys::ImageDetail* image, const TextureSetting& setting /*= TextureSetting2D()*/)
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

	
	int size = 0;
#if USE_STORAGE	
	TextureExternalFormat format = TextureExternalFormat::RGBA;
	TextureInternalSizedFormat internalFormat = TextureInternalSizedFormat::RGBA8;
	getStorageTextureFormat(image->getDataFormat(), format, internalFormat, size);
#else
	TextureExternalFormat format = TextureExternalFormat::RGBA;
	TextureInternalBaseFormat internalFormat = TextureInternalBaseFormat::RGBA;
	getTextureFormat(image->getDataFormat(), format, internalFormat, size);
#endif
	int len = size * getWidth();
	if ((len % 4 == 3) || (len % 4 == 0))
	{
		GLState::setPixelStore(PixelStore::UNPACK_ALIGNMENT, 4);
	}
	else
	{
		GLState::setPixelStore(PixelStore::UNPACK_ALIGNMENT, 2);
	}

#if USE_STORAGE
	this->setTextureStorage(1, internalFormat, getWidth(), getHeight());
	this->setTextureSubImage(0, 0, 0, getWidth(), getHeight(), format, TextureExternalDataType::UNSIGNED_BYTE, image->getPixels());
#else
	GLState::setPixelStore(PixelStore::UNPACK_ALIGNMENT, 4);
	this->setTextureImage(0, internalFormat,
		image->getWidth(), image->getHeight(), 0, format,
		TextureExternalDataType::UNSIGNED_BYTE, image->getPixels());
#endif

	GLDebug::showError();
	/* Setup some parameters for texture filters and mipmapping */
	this->apply(setting);

	this->unbindTexture();

	GLDebug::showError();
}