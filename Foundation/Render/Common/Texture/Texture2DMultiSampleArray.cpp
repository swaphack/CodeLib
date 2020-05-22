#include "Texture2DMultiSampleArray.h"
#include "Graphic/import.h"

render::Texture2DMultiSampleArray::Texture2DMultiSampleArray()
	:Texture(TextureTarget::TEXTURE_2D_MULTISAMPLE_ARRAY)
{
}

render::Texture2DMultiSampleArray::~Texture2DMultiSampleArray()
{

}

void render::Texture2DMultiSampleArray::setTextureStorage(int samples, TextureInternalSizedFormat internalFormat, int width, int height, int depth, bool fixedSamplelocations)
{
	GLTexture::setTexStorage3DMultisample((Texture3DMultisampleTarget)getTextureTarget(), samples, internalFormat, width, height, depth, fixedSamplelocations);
}

void render::Texture2DMultiSampleArray::setTextureImage(int samples, TextureInternalBaseFormat internalFormat, int width, int height, int depth, bool fixedSamplelocations)
{
	GLTexture::setTexImage3DMultisample((Texture3DMultisampleTarget)getTextureTarget(), samples, internalFormat, width, height, depth, fixedSamplelocations);
}
