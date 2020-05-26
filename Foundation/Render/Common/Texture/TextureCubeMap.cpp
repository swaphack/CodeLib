#include "TextureCubeMap.h"

#include "Graphic/import.h"

render::TextureCubeMap::TextureCubeMap()
	:Texture(TextureTarget::TEXTURE_CUBE_MAP)
{
}

render::TextureCubeMap::~TextureCubeMap()
{

}

void render::TextureCubeMap::load(const sys::ImageDetail* imageDetails[6], const TextureSetting& setting /*= TextureSetting()*/)
{
	if (imageDetails == nullptr)
	{
		return;
	}

	this->setTextureSetting(setting);
	this->applyTextureSettingWithSampler();
	GLDebug::showError();

	/* Generate texture */
	this->bindTexture();
	GLDebug::showError();

	for (int i = 0; i <  6; i++)
	{
		auto image = imageDetails[i];
		int size = 0;
#if USE_TEXTURE_STORAGE	
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

		TextureTarget2D target = (TextureTarget2D)((uint32_t)TextureTarget2D::TEXTURE_CUBE_MAP_NEGATIVE_X + i);
#if USE_TEXTURE_STORAGE
		GLTexture::setTexStorage2D(target, 0, internalFormat, getWidth(), getHeight());
		GLTexture::setTexSubImage2D(target, 0, 0, 0, getWidth(), getHeight(), format, TextureExternalDataType::UNSIGNED_BYTE, image->getPixels());
#else
		GLTexture::setTexImage2D(target, 0, internalFormat,
			image->getWidth(), image->getHeight(), 0, format,
			TextureExternalDataType::UNSIGNED_BYTE, image->getPixels());
#endif
	}

	GLDebug::showError();
	/* Setup some parameters for texture filters and mipmapping */
	this->unbindTexture();
	GLDebug::showError();
}

