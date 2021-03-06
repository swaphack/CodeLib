#include "GLRender.h"

using namespace render;

void GLRender::clear(int mask)
{
	glClear(mask);
}

void GLRender::clear(ClearBufferBitType mask)
{
	glClear((uint32_t)mask);
}

void render::GLRender::clearBuffer(ClearBufferType mask, int drawbuffer, const float* value)
{
	glClearBufferfv((GLenum)mask, drawbuffer, value);
}

void render::GLRender::setDrawBuffer(int mode)
{
	glDrawBuffer(mode);
}

void render::GLRender::clearBuffer(float depth, float stencil)
{
	glClearBufferfi(GL_DEPTH_STENCIL, 0, depth, stencil);
}

void render::GLRender::clearBuffer(ClearBufferType mask, int drawbuffer, const uint32_t* value)
{
	glClearBufferuiv((GLenum)mask, drawbuffer, value);
}

void render::GLRender::clearBuffer(ClearBufferType mask, int drawbuffer, const int* value)
{
	glClearBufferiv((GLenum)mask, drawbuffer, value);
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


void GLRender::setDrawBuffer(DrawBufferMode mode)
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

void GLRender::setReadBuffer(ReadBufferMode mode)
{
	glReadBuffer((GLenum)mode);
}

void GLRender::setNamedFramebufferReadBuffer(GLuint framebuffer, DrawBufferMode mode)
{
	glNamedFramebufferReadBuffer(framebuffer, (GLenum)mode);
}

void GLRender::readPixels(float x, float y, float width, float height, ReadPixelDataFormat pixelFormat, ReadPixelDataType pixelType, void* data)
{
	glReadPixels(x, y, width, height, (GLenum)pixelFormat, (GLenum)pixelType, data);
}