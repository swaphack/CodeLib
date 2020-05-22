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
	GLTexture::setTexStorage1D((TextureTarget1D)getTextureTarget(), levels, internalFormat, width);
}

void render::Texture1D::setTextureSubImage(int level, int xoffset, int width, TextureExternalFormat format, TextureExternalDataType type, const void* pixels)
{
	GLTexture::setTexSubImage1D((TextureTarget1D)getTextureTarget(), level, xoffset, width, format, type, pixels);
}

void render::Texture1D::compressedTextureImage(int level, TextureCompressedInternalFormat format, int width, int imageSize, const void* data)
{
	GLTexture::compressedTexImage1D((TextureTarget1D)getTextureTarget(), level, format, width, imageSize, data);
}

void render::Texture1D::compressedTextureSubImage(int level, int xoffset, int width, TextureCompressedInternalFormat format, int imageSize, const void* data)
{
	GLTexture::compressedTexSubImage1D((TextureTarget1D)getTextureTarget(), level, xoffset, width, format, imageSize, data);
}

void render::Texture1D::setTextureImage(int level, TextureInternalBaseFormat internalFormat, int width, int border, TextureExternalFormat format, TextureExternalDataType type, const void* data)
{
	GLTexture::setTexImage1D((TextureTarget1D)getTextureTarget(), level, internalFormat, width, border, format, type, data);
}

