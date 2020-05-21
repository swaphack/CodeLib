#include "Texture2DArray.h"
#include "Graphic/import.h"

render::Texture2DArray::Texture2DArray()
	:Texture(TextureTarget::TEXTURE_2D_ARRAY)
{
}

render::Texture2DArray::~Texture2DArray()
{

}

void render::Texture2DArray::setTextureStorage(int levels, TextureInternalFormat internalFormat, int width, int height, int depth)
{
	GLTexture::setTexStorage3D((TextureTarget3D)getTextureTarget(), levels, internalFormat, width, height, depth);
}

void render::Texture2DArray::setTextureSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureDataFormat format, TextureDataType type, const void* pixels)
{
	GLTexture::setTexSubImage3D((TextureTarget3D)getTextureTarget(), level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

void render::Texture2DArray::setTextureImage(int level, TextureInternalFormat internalFormat, int width, int height, int depth, int border, TextureDataFormat format, TextureDataType type, const void* data)
{
	GLTexture::setTexImage3D((TextureTarget3D)getTextureTarget(), level, internalFormat, width, height, depth, border, format, type, data);
}
