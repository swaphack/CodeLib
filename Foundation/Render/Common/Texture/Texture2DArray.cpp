#include "Texture2DArray.h"
#include "Graphic/import.h"

render::Texture2DArray::Texture2DArray()
	:Texture(TextureTarget::TEXTURE_2D_ARRAY)
{
}

render::Texture2DArray::~Texture2DArray()
{

}

void render::Texture2DArray::setTextureStorage(int levels, TextureInternalSizedFormat internalFormat, int width, int height, int depth)
{
	GLTexture::setTexStorage3D((TextureTarget3D)getTextureTarget(), levels, internalFormat, width, height, depth);
}

void render::Texture2DArray::setTextureSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureExternalFormat format, TextureExternalDataType type, const void* pixels)
{
	GLTexture::setTexSubImage3D((TextureTarget3D)getTextureTarget(), level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

void render::Texture2DArray::compressedTextureImage(int level, TextureCompressedInternalFormat format, int width, int height, int depth, int imageSize, const void* data)
{
	GLTexture::compressedTexImage3D((TextureTarget3D)getTextureTarget(), level, format, width, height, depth, imageSize, data);
}

void render::Texture2DArray::compressedTextureSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureCompressedInternalFormat format, int imageSize, const void* data)
{
	GLTexture::compressedTexSubImage3D((TextureTarget3D)getTextureTarget(), level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}

void render::Texture2DArray::setTextureImage(int level, TextureInternalBaseFormat internalFormat, int width, int height, int depth, int border, TextureExternalFormat format, TextureExternalDataType type, const void* data)
{
	GLTexture::setTexImage3D((TextureTarget3D)getTextureTarget(), level, internalFormat, width, height, depth, border, format, type, data);
}
