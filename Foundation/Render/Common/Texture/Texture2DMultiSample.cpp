#include "Texture2DMultiSample.h"
#include "Graphic/import.h"

render::Texture2DMultiSample::Texture2DMultiSample()
	:Texture(TextureTarget::TEXTURE_2D_MULTISAMPLE)
{
}

render::Texture2DMultiSample::~Texture2DMultiSample()
{

}

void render::Texture2DMultiSample::setTextureStorage(int samples, TextureInternalFormat internalFormat, int width, int height, bool fixedSamplelocations)
{
	GLTexture::setTexStorage2DMultisample((Texture2DMultisampleTarget)samples, samples, internalFormat, width, height, fixedSamplelocations);
}

void render::Texture2DMultiSample::setTextureImage(int samples, TextureInternalFormat internalFormat, int width, int height, bool fixedSamplelocations)
{
	GLTexture::setTexImage2DMultisample((Texture2DMultisampleTarget)samples, samples, internalFormat, width, height, fixedSamplelocations);
}
