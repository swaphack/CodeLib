#include "TextureCubeMapArray.h"

#include "Graphic/import.h"

render::TextureCubeMapArray::TextureCubeMapArray()
	:Texture(TextureTarget::TEXTURE_CUBE_MAP_ARRAY)
{

}

render::TextureCubeMapArray::~TextureCubeMapArray()
{

}

void render::TextureCubeMapArray::setTextureStorage(int levels, TextureInternalSizedFormat internalFormat, int width, int height, int depth)
{
#if USE_NEW_TEXTURE_FUNCTION
	GLTexture::setTextureStorage3D(getTextureID(), levels, internalFormat, width, height, depth);
#else
	GLTexture::setTexStorage3D((TextureTarget3D)getTextureTarget(), levels, internalFormat, width, height, depth);
#endif	
}

void render::TextureCubeMapArray::setTextureSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureExternalFormat format, TextureExternalDataType type, const void* pixels)
{
#if USE_NEW_TEXTURE_FUNCTION
	GLTexture::setTextureSubImage3D(getTextureID(), level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
#else
	GLTexture::setTexSubImage3D((TextureTarget3D)getTextureTarget(), level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
#endif
}

