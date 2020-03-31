#include "GLPixels.h"

using namespace render;

void GLPixels::setDrawBuffMode(DrawBufferMode mode)
{
	glDrawBuffer((GLenum)mode);
}

void GLPixels::setIndexMask(int mask)
{
	glIndexMask(mask);
}

void GLPixels::setColorMask(bool red, bool green, bool blue, bool alpha)
{
	glColorMask(red, green, blue, alpha);
}

void GLPixels::setDepthMask(bool flag)
{
	glDepthMask(flag);
}

void GLPixels::setStencilMask(int mask)
{
	glStencilMask(mask);
}

void GLPixels::clearBuffer(ClearBufferMask mask)
{
	glClear((GLbitfield)mask);
}

void GLPixels::clearColor(float red, float green, float blue, float alpha)
{
	glClearColor(red, green, blue, alpha);
}

void GLPixels::clearIndex(int mask)
{
	glClearIndex(mask);
}

void GLPixels::clearDepth(float depth)
{
	glClearDepth(depth);
}

void GLPixels::clearStencil(int mask)
{
	glClearStencil(mask);
}

void GLPixels::clearAccum(float red, float green, float blue, float alpha)
{
	glClearAccum(red, green, blue, alpha);
}

void GLPixels::readPixels(float x, float y, float width, float height, PixelFormat pixelFormat, PixelType pixelType, void* data)
{
	glReadPixels(x, y, width, height, (GLenum)pixelFormat, (GLenum)pixelType, data);
}

void GLPixels::copyPixels(float x, float y, float width, float height, PixelCopyType copyType)
{
	glCopyPixels(x, y, width, height, (GLenum)copyType);
}

void GLPixels::setReadBufferMode(ReadBufferMode mode)
{
	glReadBuffer((GLenum)mode);
}

void GLPixels::copyTexImage1D(int nLevel, TextureParameter internalFormat, int x, int y, int width, int border)
{
	glCopyTexImage1D((GLenum)TextureTarget::TEXTURE_1D, nLevel, (GLenum)internalFormat, x, y, width, border);
}

void GLPixels::clearBuffer(int mask)
{
	glClear(mask);
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

