#include "GLRender.h"

using namespace render;

void GLRender::clearBuffer(int mask)
{
	glClear(mask);
}

void GLRender::clearBuffer(ClearBufferMask mask)
{
	glClear((GLbitfield)mask);
}

void GLRender::clearColor(float red, float green, float blue, float alpha)
{
	glClearColor(red, green, blue, alpha);
}

void GLRender::clearDepth(float depth)
{
	glClearDepth(depth);
}

void GLRender::clearStencil(int mask)
{
	glClearStencil(mask);
}


void GLRender::setDrawBuffMode(DrawBufferMode mode)
{
	glDrawBuffer((GLenum)mode);
}

void GLRender::setNamedFramebufferDrawBuffer(GLuint framebuffer, DrawBufferMode mode)
{
	glNamedFramebufferDrawBuffer(framebuffer, (GLenum)mode);
}


void GLRender::finish()
{
	glFinish();
}

void GLRender::flush()
{
	glFlush();
}

void GLRender::setReadBufferMode(ReadBufferMode mode)
{
	glReadBuffer((GLenum)mode);
}

void GLRender::setNamedFramebufferReadBuffer(GLuint framebuffer, DrawBufferMode mode)
{
	glNamedFramebufferReadBuffer(framebuffer, (GLenum)mode);
}


void GLRender::readPixels(float x, float y, float width, float height, TexImageDataFormat pixelFormat, TexImageDataType pixelType, void* data)
{
	glReadPixels(x, y, width, height, (GLenum)pixelFormat, (GLenum)pixelType, data);
}