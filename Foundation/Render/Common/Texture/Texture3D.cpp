#include "Texture3D.h"
#include "Graphic/import.h"

render::Texture3D::Texture3D()
	:Texture(TextureTarget::TEXTURE_3D)
{
}

render::Texture3D::~Texture3D()
{

}

void render::Texture3D::setTextureStorage(int levels, TextureInternalFormat internalFormat, int width, int height, int depth)
{
	GLTexture::setTexStorage3D((TextureTarget3D)getTextureTarget(), levels, internalFormat, width, height, depth);
}

void render::Texture3D::setTextureSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureDataFormat format, TextureDataType type, const void* pixels)
{
	GLTexture::setTexSubImage3D((TextureTarget3D)getTextureTarget(), level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

void render::Texture3D::setTextureImage(int level, TextureInternalFormat internalFormat, int width, int height, int depth, int border, TextureDataFormat format, TextureDataType type, const void* data)
{
	GLTexture::setTexImage3D((TextureTarget3D)getTextureTarget(), level, internalFormat, width, height, depth, border, format, type, data);
}

