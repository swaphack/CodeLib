#include "GLPixels.h"

using namespace render;









void GLPixels::readPixels(float x, float y, float width, float height, PixelFormat pixelFormat, PixelType pixelType, void* data)
{
	glReadPixels(x, y, width, height, (GLenum)pixelFormat, (GLenum)pixelType, data);
}

void GLPixels::copyTexImage1D(int nLevel, TextureParameter internalFormat, int x, int y, int width, int border)
{
	glCopyTexImage1D((GLenum)TextureTarget::TEXTURE_1D, nLevel, (GLenum)internalFormat, x, y, width, border);
}

void render::GLPixels::copyTexImage2D(int nLevel, TextureParameter internalFormat, int x, int y, int width, int height, int border)
{
	glCopyTexImage2D((GLenum)TextureTarget::TEXTURE_2D, nLevel, (GLenum)internalFormat, x, y, width, height, border);
}

void GLPixels::copyTexSubImage1D(int nLevel, int xoffset, int x, int y, int width)
{
	glCopyTexSubImage1D((GLenum)TextureTarget::TEXTURE_1D, nLevel, xoffset, x, y, width);
}

void GLPixels::copyTexSubImage2D(int nLevel, int xoffset, int yoffset, int x, int y, int width, int height)
{
	glCopyTexSubImage2D((GLenum)TextureTarget::TEXTURE_2D, nLevel, xoffset, yoffset, x, y, width, height);
}

