#include "Texture1D.h"
#include "Graphic/import.h"

render::Texture1D::Texture1D()
	:Texture(TextureTarget::TEXTURE_1D)
{
}

render::Texture1D::~Texture1D()
{

}

void render::Texture1D::setTextureStorage(int levels, TextureInternalSizedFormat internalFormat, int width)
{
#if USE_NEW_TEXTURE_FUNCTION
	GLTexture::setTextureStorage1D(getTextureID(), levels, internalFormat, width);
#else
	GLTexture::setTexStorage1D((TextureTarget1D)getTextureTarget(), levels, internalFormat, width);
#endif
	
}

void render::Texture1D::setTextureSubImage(int level, int xoffset, int width, TextureExternalFormat format, TextureExternalDataType type, const void* pixels)
{
#if USE_NEW_TEXTURE_FUNCTION
	GLTexture::setTextureSubImage1D(getTextureID(), level, xoffset, width, format, type, pixels);
#else
	GLTexture::setTexSubImage1D((TextureTarget1D)getTextureTarget(), level, xoffset, width, format, type, pixels);
#endif
}

void render::Texture1D::compressedTextureImage(int level, TextureCompressedInternalFormat format, int width, int imageSize, const void* data)
{
	GLTexture::compressedTexImage1D((TextureTarget1D)getTextureTarget(), level, format, width, imageSize, data);

}

void render::Texture1D::compressedTextureSubImage(int level, int xoffset, int width, TextureCompressedInternalFormat format, int imageSize, const void* data)
{
#if USE_NEW_TEXTURE_FUNCTION
	GLTexture::compressedTextureSubImage1D(getTextureID(), level, xoffset, width, format, imageSize, data);
#else
	GLTexture::compressedTexSubImage1D((TextureTarget1D)getTextureTarget(), level, xoffset, width, format, imageSize, data);
#endif
}

void render::Texture1D::setTextureImage(int level, TextureInternalBaseFormat internalFormat, int width, int border, TextureExternalFormat format, TextureExternalDataType type, const void* data)
{
	GLTexture::setTexImage1D((TextureTarget1D)getTextureTarget(), level, internalFormat, width, border, format, type, data);
}

