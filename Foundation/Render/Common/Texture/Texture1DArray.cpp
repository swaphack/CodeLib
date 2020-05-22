#include "Texture1DArray.h"
#include "Graphic/import.h"

render::Texture1DArray::Texture1DArray()
	:Texture(TextureTarget::TEXTURE_1D_ARRAY)
{
}

render::Texture1DArray::~Texture1DArray()
{

}

void render::Texture1DArray::setTextureStorage(int levels, TextureInternalSizedFormat internalFormat, int width, int height)
{
	GLTexture::setTexStorage2D((TextureTarget2D)getTextureTarget(), levels, internalFormat, width, height);
}

void render::Texture1DArray::setTextureSubImage(int level, int xoffset, int yoffset, int width, int height, TextureExternalFormat format, TextureExternalDataType type, const void* pixels)
{
	GLTexture::setTexSubImage2D((TextureTarget2D)getTextureTarget(), level, xoffset, yoffset, width, height, format, type, pixels);
}

void render::Texture1DArray::compressedTextureImage(int level, TextureCompressedInternalFormat format, int width, int height, int imageSize, const void* data)
{
	GLTexture::compressedTexImage2D((TextureTarget2D)getTextureTarget(), level, format, width, height, imageSize, data);
}

void render::Texture1DArray::compressedTextureSubImage(int level, int xoffset, int yoffset, int width, int height, TextureCompressedInternalFormat format, int imageSize, const void* data)
{
	GLTexture::compressedTexSubImage2D((TextureTarget2D)getTextureTarget(), level, xoffset, yoffset, width, height, format, imageSize, data);
}

void render::Texture1DArray::setTextureImage(int level, TextureInternalBaseFormat internalFormat, int width, int height, int border, TextureExternalFormat format, TextureExternalDataType type, const void* data)
{
	GLTexture::setTexImage2D((TextureTarget2D)getTextureTarget(), level, internalFormat, width, height, border, format, type, data);
}

