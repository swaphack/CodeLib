#include "Texture3D.h"
#include "Graphic/import.h"

render::Texture3D::Texture3D()
	:Texture(TextureTarget::TEXTURE_3D)
{
}

render::Texture3D::~Texture3D()
{

}

void render::Texture3D::setTextureStorage(int levels, TextureInternalSizedFormat internalFormat, int width, int height, int depth)
{
	GLTexture::setTexStorage3D((TextureTarget3D)getTextureTarget(), levels, internalFormat, width, height, depth);
}

void render::Texture3D::setTextureSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureExternalFormat format, TextureExternalDataType type, const void* pixels)
{
	GLTexture::setTexSubImage3D((TextureTarget3D)getTextureTarget(), level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

void render::Texture3D::compressedTextureImage(int level, TextureCompressedInternalFormat format, int width, int height, int depth, int imageSize, const void* data)
{
	GLTexture::compressedTexImage3D((TextureTarget3D)getTextureTarget(), level, format, width, height, depth, imageSize, data);
}

void render::Texture3D::compressedTextureSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureCompressedInternalFormat format, int imageSize, const void* data)
{
	GLTexture::compressedTexSubImage3D((TextureTarget3D)getTextureTarget(), level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}

void render::Texture3D::setTextureImage(int level, TextureInternalBaseFormat internalFormat, int width, int height, int depth, int border, TextureExternalFormat format, TextureExternalDataType type, const void* data)
{
	GLTexture::setTexImage3D((TextureTarget3D)getTextureTarget(), level, internalFormat, width, height, depth, border, format, type, data);
}

