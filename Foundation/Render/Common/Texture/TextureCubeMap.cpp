#include "TextureCubeMap.h"

#include "Graphic/import.h"

render::TextureCubeMap::TextureCubeMap()
	:Texture(TextureTarget::TEXTURE_CUBE_MAP)
{
}

render::TextureCubeMap::~TextureCubeMap()
{

}

void render::TextureCubeMap::load(int count, sys::ImageDetail** imageDetails, const TextureSetting& setting /*= TextureSetting()*/)
{
	if (imageDetails == nullptr)
	{
		return;
	}

	this->setTextureSetting(setting);
	GLDebug::showError();

	/* Generate texture */
	this->bindTexture();
	GLDebug::showError();

	this->setDepth(count);
	for (int i = 0; i < count; i++)
	{
		auto image = imageDetails[i];
		
		
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

		
		if (i == 0)
		{
			this->setWidth(image->getWidth());
			this->setHeight(image->getHeight());
			GLDebug::showError();
		}
		TextureTarget2D target = (TextureTarget2D)((uint32_t)TextureTarget2D::TEXTURE_CUBE_MAP_POSITIVE_X + i);

		GLTexture::setTexImage2D(target, 0, internalFormat,
			getWidth(), getHeight(), 0, format,
			TextureExternalDataType::UNSIGNED_BYTE, image->getPixels());

		GLDebug::showError();
	}

	this->applyTextureSetting();
	GLDebug::showError();
	this->unbindTexture();
	GLDebug::showError();
}

