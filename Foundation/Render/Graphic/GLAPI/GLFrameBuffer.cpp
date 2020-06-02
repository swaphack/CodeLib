#include "GLFrameBuffer.h"

using namespace render;

void GLFrameBuffer::bindFramebuffer(FrameBufferTarget target, uint32_t frameBuffer)
{
	glBindFramebuffer((GLenum)target, frameBuffer);
}

void GLFrameBuffer::bindRenderBuffer(RenderBufferTarget target, uint32_t renderBuffer)
{
	glBindRenderbuffer((GLenum)target, renderBuffer);
}

void GLFrameBuffer::blitFrameBuffer(uint32_t srcX0, uint32_t srcY0, uint32_t srcX1, uint32_t srcY1, uint32_t dstX0, uint32_t dstY0, uint32_t dstX1, uint32_t dstY1, uint32_t mask, BlitFrameBufferFilter filter)
{
	glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, (GLenum)filter);
}

void GLFrameBuffer::blitNamedFrameBuffer(uint32_t readFrameBuffer, uint32_t drawFrameBuffer, uint32_t srcX0, uint32_t srcY0, uint32_t srcX1, uint32_t srcY1, uint32_t dstX0, uint32_t dstY0, uint32_t dstX1, uint32_t dstY1, uint32_t mask, BlitFrameBufferFilter filter)
{
	glBlitNamedFramebuffer(readFrameBuffer, drawFrameBuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, (GLenum)filter);
}

GLenum GLFrameBuffer::checkFrameBufferStatus(FrameBufferTarget target)
{
	return glCheckFramebufferStatus((GLenum)target);
}

GLenum GLFrameBuffer::checkNamedFrameBufferStatus(uint32_t framebuffer, FrameBufferTarget target)
{
	return glCheckNamedFramebufferStatus(framebuffer, (GLenum)target);
}

void GLFrameBuffer::createFrameBuffers(int n, uint32_t *ids)
{
	glCreateFramebuffers(n, ids);
}

void GLFrameBuffer::createRenderBuffers(int n, uint32_t *ids)
{
	glCreateRenderbuffers(n, ids);
}

void GLFrameBuffer::deleteFrameBuffers(int n, uint32_t *framebuffers)
{
	glDeleteFramebuffers(n, framebuffers);
}

void GLFrameBuffer::deleteRenderBuffers(int n, uint32_t *renderBuffers)
{
	glDeleteRenderbuffers(n, renderBuffers);
}

void GLFrameBuffer::setDrawBuffers(int n, const DrawBufferType* bufs)
{
	uint32_t* data = new uint32_t[n];
	for (int i = 0; i < n; i++)
	{
		data[i] = (GLenum)bufs[i];
	}

	glDrawBuffers(n, data);

	delete[] data;
}

void GLFrameBuffer::setNamedFrameBufferDrawBuffers(uint32_t framebuffer, int n, const DrawBufferType* bufs)
{
	uint32_t* data = new uint32_t[n];
	for (int i = 0; i < n; i++)
	{
		data[i] = (GLenum)bufs[i];
	}

	glNamedFramebufferDrawBuffers(framebuffer, n, data);

	delete[] data;
}

void GLFrameBuffer::setFrameBufferParameter(FrameBufferTarget target, FrameBufferParameter name, int value)
{
	glFramebufferParameteri((GLenum)target, (GLenum)name, value);
}

void GLFrameBuffer::setNamedFrameBufferParameter(uint32_t framebuffer, FrameBufferParameter name, int value)
{
	glNamedFramebufferParameteri(framebuffer, (GLenum)name, value);
}

void GLFrameBuffer::setFrameBufferRenderBuffer(FrameBufferTarget target, FrameBufferAttachment attachment, RenderBufferTarget rbTarget, uint32_t renderBuffer)
{
	glFramebufferRenderbuffer((GLenum)target, (GLenum)attachment, (GLenum)rbTarget, renderBuffer);
}

void GLFrameBuffer::setNamedFrameBufferRenderBuffer(uint32_t framebuffer, FrameBufferAttachment attachment, RenderBufferTarget rbTarget, uint32_t renderBuffer)
{
	glNamedFramebufferRenderbuffer(framebuffer, (GLenum)attachment, (GLenum)rbTarget, renderBuffer);
}

void GLFrameBuffer::setFrameBufferTexture(FrameBufferTarget target, FrameBufferAttachment attachment, uint32_t texture, int level)
{
	glFramebufferTexture((GLenum)target, (GLenum)attachment, texture, level);
}

void GLFrameBuffer::setFrameBufferTexture1D(FrameBufferTarget target, FrameBufferAttachment attachment, uint32_t texture, int level)
{
	glFramebufferTexture1D((GLenum)target, (GLenum)attachment, GL_TEXTURE_1D, texture, level);
}

void GLFrameBuffer::setFrameBufferTexture2D(FrameBufferTarget target, FrameBufferAttachment attachment, uint32_t texture, int level)
{
	glFramebufferTexture2D((GLenum)target, (GLenum)attachment, GL_TEXTURE_2D, texture, level);
}

void GLFrameBuffer::setFrameBufferTexture3D(FrameBufferTarget target, FrameBufferAttachment attachment, uint32_t texture, int level)
{
	glFramebufferTexture2D((GLenum)target, (GLenum)attachment, GL_TEXTURE_3D, texture, level);
}

void GLFrameBuffer::setNamedFrameBufferTexture(uint32_t framebuffer, FrameBufferAttachment attachment, uint32_t texture, int level)
{
	glNamedFramebufferTexture(framebuffer, (GLenum)attachment, texture, level);
}

void GLFrameBuffer::setFrameBufferTextureLayer(FrameBufferTarget target, FrameBufferAttachment attachment, uint32_t texture, int level, int layer)
{
	glFramebufferTextureLayer((GLenum)target, (GLenum)attachment, texture, level, layer);
}

void GLFrameBuffer::setNamedFrameBufferTextureLayer(uint32_t framebuffer, FrameBufferAttachment attachment, uint32_t texture, int level, int layer)
{
	glNamedFramebufferTextureLayer(framebuffer, (GLenum)attachment, texture, level, layer);
}

void GLFrameBuffer::genFrameBuffers(int n, uint32_t* ids)
{
	glGenFramebuffers(n, ids);
}

void GLFrameBuffer::genRenderBuffers(int n, uint32_t* renderbuffers)
{
	glGenRenderbuffers(n, renderbuffers);
}

void GLFrameBuffer::getFrameBufferAttachmentParameter(FrameBufferTarget target, FrameBufferAttachment attachment, FrameBufferAttachmentParameter name, int* params)
{
	glGetFramebufferAttachmentParameteriv((GLenum)target, (GLenum)attachment, (GLenum)name, params);
}

void GLFrameBuffer::getNamedFrameBufferAttachmentParameter(uint32_t framebuffer, FrameBufferAttachment attachment, FrameBufferAttachmentParameter name, int* params)
{
	glGetNamedFramebufferAttachmentParameteriv(framebuffer, (GLenum)attachment, (GLenum)name, params);
}

void GLFrameBuffer::getFrameBufferParameter(FrameBufferTarget target, FrameBufferParameter name, int *params)
{
	glGetFramebufferParameteriv((GLenum)target, (GLenum)name, params);
}

void GLFrameBuffer::getNamedFrameBufferParameter(uint32_t framebuffer, FrameBufferParameter name, int *params)
{
	glGetNamedFramebufferParameteriv(framebuffer, (GLenum)name, params);
}

void GLFrameBuffer::getRenderBufferParameter(RenderBufferTarget target, RenderBufferParameter name, int *params)
{
	glGetRenderbufferParameteriv((GLenum)target, (GLenum)name, params);
}

void GLFrameBuffer::getNamedRenderBufferParameter(uint32_t renderbuffer, RenderBufferParameter name, int *params)
{
	glGetNamedRenderbufferParameteriv(renderbuffer, (GLenum)name, params);
}

void GLFrameBuffer::invalidateFrameBuffer(FrameBufferTarget target, int num, const FrameBufferAttachment* attachments)
{
	uint32_t* data = new uint32_t[num];
	for (int i = 0; i < num; i++)
	{
		data[i] = (GLenum)attachments[i];
	}
	glInvalidateFramebuffer((GLenum)target, num, data);

	delete[] data;
}

void GLFrameBuffer::invalidateNamedFrameBuffer(uint32_t framebuffer, int num, const FrameBufferAttachment* attachments)
{
	uint32_t* data = new uint32_t[num];
	for (int i = 0; i < num; i++)
	{
		data[i] = (GLenum)attachments[i];
	}
	glInvalidateNamedFramebufferData(framebuffer, num, data);

	delete[] data;
}

void GLFrameBuffer::invalidateSubFrameBuffer(FrameBufferTarget target, int num, const FrameBufferAttachment* attachments, int x, int y, int width, int height)
{
	uint32_t* data = new uint32_t[num];
	for (int i = 0; i < num; i++)
	{
		data[i] = (GLenum)attachments[i];
	}
	glInvalidateSubFramebuffer((GLenum)target, num, data, x, y, width, height);

	delete[] data;
}

void GLFrameBuffer::invalidateNamedFrameBufferSubData(uint32_t framebuffer, int num, const FrameBufferAttachment* attachments, int x, int y, int width, int height)
{
	uint32_t* data = new uint32_t[num];
	for (int i = 0; i < num; i++)
	{
		data[i] = (GLenum)attachments[i];
	}
	glInvalidateNamedFramebufferSubData(framebuffer, num, data, x, y, width, height);

	delete[] data;
}

bool GLFrameBuffer::isFrameBuffer(uint32_t framebuffer)
{
	return glIsFramebuffer(framebuffer) == GL_TRUE;
}

bool GLFrameBuffer::isRenderBuffer(uint32_t renderbuffer)
{
	return glIsRenderbuffer(renderbuffer) == GL_TRUE;
}

void GLFrameBuffer::setRenderBufferStorage(RenderBufferTarget target, InternalImageFormat format, int width, int height)
{
	glRenderbufferStorage((GLenum)target, (GLenum)format, width, height);
}

void GLFrameBuffer::setNamedRenderBufferStorage(uint32_t renderbuffer, InternalImageFormat format, int width, int height)
{
	glNamedRenderbufferStorage(renderbuffer, (GLenum)format, width, height);
}

void GLFrameBuffer::setRenderBufferStorageMultisample(RenderBufferTarget target, int samples, InternalImageFormat format, int width, int height)
{
	glRenderbufferStorageMultisample((GLenum)target, samples,(GLenum)format, width, height);
}

void GLFrameBuffer::setNamedRenderBufferStorageMultisample(uint32_t renderbuffer, int samples, InternalImageFormat format, int width, int height)
{
	glNamedRenderbufferStorageMultisample(renderbuffer, samples, (GLenum)format, width, height);
}

uint32_t render::GLFrameBuffer::createFrameBuffer()
{
	uint32_t id = 0;
	createFrameBuffers(1, &id);
	return id;
}

uint32_t render::GLFrameBuffer::createRenderBuffer()
{
	uint32_t id = 0;
	createRenderBuffers(1, &id);
	return id;
}

void render::GLFrameBuffer::deleteFrameBuffer(uint32_t framebuffer)
{
	deleteFrameBuffers(1, &framebuffer);
}

void render::GLFrameBuffer::deleteRenderBuffer(uint32_t renderBuffer)
{
	deleteRenderBuffers(1, &renderBuffer);
}

uint32_t render::GLFrameBuffer::genFrameBuffer()
{
	uint32_t id = 0;
	genFrameBuffers(1, &id);
	return id;
}

uint32_t render::GLFrameBuffer::genRenderBuffer()
{
	uint32_t id = 0;
	genRenderBuffers(1, &id);
	return id;
}

