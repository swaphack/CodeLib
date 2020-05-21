#include "Texture1DArray.h"
#include "Graphic/import.h"

render::Texture1DArray::Texture1DArray()
	:Texture(TextureTarget::TEXTURE_1D_ARRAY)
{
}

render::Texture1DArray::~Texture1DArray()
{

}

void render::Texture1DArray::setTextureStorage(int levels, TextureInternalFormat internalFormat, int width, int height)
{
	GLTexture::setTexStorage2D((TextureTarget2D)getTextureTarget(), levels, internalFormat, width, height);
}

void render::Texture1DArray::setTextureSubImage(int level, int xoffset, int yoffset, int width, int height, TextureDataFormat format, TextureDataType type, const void* pixels)
{
	GLTexture::setTexSubImage2D((TextureTarget2D)getTextureTarget(), level, xoffset, yoffset, width, height, format, type, pixels);
}

void render::Texture1DArray::setTextureImage(int level, TextureInternalFormat internalFormat, int width, int height, int border, TextureDataFormat format, TextureDataType type, const void* data)
{
	GLTexture::setTexImage2D((TextureTarget2D)getTextureTarget(), level, internalFormat, width, height, border, format, type, data);
}

