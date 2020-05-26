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
#if USE_NEW_TEXTURE_FUNCTION
	GLTexture::setTextureStorage2D(getTextureID(), levels, internalFormat, width, height);
#else
	GLTexture::setTexStorage2D((TextureTarget2D)getTextureTarget(), levels, internalFormat, width, height);
#endif
}

void render::Texture1DArray::setTextureSubImage(int level, int xoffset, int yoffset, int width, int height, TextureExternalFormat format, TextureExternalDataType type, const void* pixels)
{
#if USE_NEW_TEXTURE_FUNCTION
	GLTexture::setTextureSubImage2D(getTextureID(), level, xoffset, yoffset, width, height, format, type, pixels);
#else
	GLTexture::setTexSubImage2D((TextureTarget2D)getTextureTarget(), level, xoffset, yoffset, width, height, format, type, pixels);
#endif
}

void render::Texture1DArray::compressedTextureImage(int level, TextureCompressedInternalFormat format, int width, int height, int imageSize, const void* data)
{
	GLTexture::compressedTexImage2D((TextureTarget2D)getTextureTarget(), level, format, width, height, imageSize, data);
}

void render::Texture1DArray::compressedTextureSubImage(int level, int xoffset, int yoffset, int width, int height, TextureCompressedInternalFormat format, int imageSize, const void* data)
{
#if USE_NEW_TEXTURE_FUNCTION
	GLTexture::compressedTextureSubImage2D(getTextureID(), level, xoffset, yoffset, width, height, format, imageSize, data);
#else
	GLTexture::compressedTexSubImage2D((TextureTarget2D)getTextureTarget(), level, xoffset, yoffset, width, height, format, imageSize, data);
#endif
}

void render::Texture1DArray::setTextureImage(int level, TextureInternalBaseFormat internalFormat, int width, int height, int border, TextureExternalFormat format, TextureExternalDataType type, const void* data)
{
	GLTexture::setTexImage2D((TextureTarget2D)getTextureTarget(), level, internalFormat, width, height, border, format, type, data);
}

