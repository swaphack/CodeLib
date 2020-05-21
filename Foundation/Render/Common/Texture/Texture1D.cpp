#include "Texture1D.h"
#include "Graphic/import.h"

render::Texture1D::Texture1D()
	:Texture(TextureTarget::TEXTURE_1D)
{
}

render::Texture1D::~Texture1D()
{

}

void render::Texture1D::setTextureStorage(int levels, TextureInternalFormat internalFormat, int width)
{
	GLTexture::setTexStorage1D((TextureTarget1D)getTextureTarget(), levels, internalFormat, width);
}

void render::Texture1D::setTextureSubImage(int level, int xoffset, int width, TextureDataFormat format, TextureDataType type, const void* pixels)
{
	GLTexture::setTexSubImage1D((TextureTarget1D)getTextureTarget(), level, xoffset, width, format, type, pixels);
}

void render::Texture1D::setTextureImage(int level, TextureInternalFormat internalFormat, int width, int border, TextureDataFormat format, TextureDataType type, const void* data)
{
	GLTexture::setTexImage1D((TextureTarget1D)getTextureTarget(), level, internalFormat, width, border, format, type, data);
}

