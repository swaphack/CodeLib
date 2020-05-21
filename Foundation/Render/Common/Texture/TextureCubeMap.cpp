#include "TextureCubeMap.h"

#include "Graphic/import.h"

render::TextureCubeMap::TextureCubeMap()
	:Texture(TextureTarget::TEXTURE_CUBE_MAP)
{
}

render::TextureCubeMap::~TextureCubeMap()
{

}

void render::TextureCubeMap::setTextureStorage(int levels, TextureInternalFormat internalFormat, int width, int height, int depth)
{
	GLTexture::setTexStorage3D((TextureTarget3D)getTextureTarget(), levels, internalFormat, width, height, depth);
}

