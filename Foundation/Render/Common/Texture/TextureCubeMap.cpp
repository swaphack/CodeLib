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
//#if USE_TEXTURE_STORAGE	
//		TextureExternalFormat format = TextureExternalFormat::RGBA;
//		TextureInternalSizedFormat internalFormat = TextureInternalSizedFormat::RGBA8;
//		getStorageTextureFormat(image->getDataFormat(), format, internalFormat, size);
//#else
		TextureExternalFormat format = TextureExternalFormat::RGBA;
		TextureInternalBaseFormat internalFormat = TextureInternalBaseFormat::RGBA;
		getTextureFormat(image->getDataFormat(), format, internalFormat, size);
//#endif
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
			//GLTexture::setTextureStorage2D(getTextureID(), 10, internalFormat, getWidth(), getHeight());
			GLDebug::showError();
		}
		TextureTarget2D target = (TextureTarget2D)((uint32_t)TextureTarget2D::TEXTURE_CUBE_MAP_POSITIVE_X + i);
//#if USE_TEXTURE_STORAGE
//		GLTexture::setTexSubImage2D(target, 0, 0, 0, getWidth(), getHeight(), format, TextureExternalDataType::UNSIGNED_BYTE, image->getPixels());
//#else
		GLTexture::setTexImage2D(target, 0, internalFormat,
			getWidth(), getHeight(), 0, format,
			TextureExternalDataType::UNSIGNED_BYTE, image->getPixels());
//#endif
		GLDebug::showError();
	}

	//GLFrameBuffer::generateMipmap((MipmapTextureTarget)getTextureTarget()));
	GLDebug::showError();
	/* Setup some parameters for texture filters and mipmapping */
	this->unbindTexture();
	GLDebug::showError();
}

