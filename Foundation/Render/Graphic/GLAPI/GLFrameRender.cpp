#include "GLFrameRender.h"

using namespace render;

void GLFrameRender::bindFramebuffer(FrameBufferTarget target, uint32_t frameBuffer)
{
	glBindFramebuffer((GLenum)target, frameBuffer);
}

void GLFrameRender::bindRenderBuffer(RenderBufferTarget target, uint32_t renderBuffer)
{
	glBindRenderbuffer((GLenum)target, renderBuffer);
}

void GLFrameRender::blitFrameBuffer(uint32_t srcX0, uint32_t srcY0, uint32_t srcX1, uint32_t srcY1, uint32_t dstX0, uint32_t dstY0, uint32_t dstX1, uint32_t dstY1, uint32_t mask, BlitFrameBufferFilter filter)
{
	glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, (GLenum)filter);
}

void GLFrameRender::blitNamedFrameBuffer(uint32_t readFrameBuffer, uint32_t drawFrameBuffer, uint32_t srcX0, uint32_t srcY0, uint32_t srcX1, uint32_t srcY1, uint32_t dstX0, uint32_t dstY0, uint32_t dstX1, uint32_t dstY1, uint32_t mask, BlitFrameBufferFilter filter)
{
	glBlitNamedFramebuffer(readFrameBuffer, drawFrameBuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, (GLenum)filter);
}

FrameBufferStatus GLFrameRender::checkFrameBufferStatus(FrameBufferTarget target)
{
	return (FrameBufferStatus)glCheckFramebufferStatus((GLenum)target);
}

FrameBufferStatus GLFrameRender::checkNamedFrameBufferStatus(uint32_t framebuffer, FrameBufferTarget target)
{
	return (FrameBufferStatus)glCheckNamedFramebufferStatus(framebuffer, (GLenum)target);
}

void GLFrameRender::createFrameBuffers(int n, uint32_t *ids)
{
	glCreateFramebuffers(n, ids);
}

void GLFrameRender::createRenderBuffers(int n, uint32_t *ids)
{
	glCreateRenderbuffers(n, ids);
}

void GLFrameRender::deleteFrameBuffers(int n, uint32_t *framebuffers)
{
	glDeleteFramebuffers(n, framebuffers);
}

void GLFrameRender::deleteRenderBuffers(int n, uint32_t *renderBuffers)
{
	glDeleteRenderbuffers(n, renderBuffers);
}

void GLFrameRender::setDrawBuffers(int n, const DrawBufferType* bufs)
{
	uint32_t* data = new uint32_t[n];
	for (int i = 0; i < n; i++)
	{
		data[i] = (GLenum)bufs[i];
	}

	glDrawBuffers(n, data);

	delete[] data;
}

void GLFrameRender::setNamedFrameBufferDrawBuffers(uint32_t framebuffer, int n, const DrawBufferType* bufs)
{
	uint32_t* data = new uint32_t[n];
	for (int i = 0; i < n; i++)
	{
		data[i] = (GLenum)bufs[i];
	}

	glNamedFramebufferDrawBuffers(framebuffer, n, data);

	delete[] data;
}

void GLFrameRender::setFrameBufferParameter(FrameBufferTarget target, FrameBufferParameter name, int value)
{
	glFramebufferParameteri((GLenum)target, (GLenum)name, value);
}

void GLFrameRender::setNamedFrameBufferParameter(uint32_t framebuffer, FrameBufferParameter name, int value)
{
	glNamedFramebufferParameteri(framebuffer, (GLenum)name, value);
}

void GLFrameRender::setFrameBufferRenderBuffer(FrameBufferTarget target, FrameBufferAttachment attachment, RenderBufferTarget rbTarget, uint32_t renderBuffer)
{
	glFramebufferRenderbuffer((GLenum)target, (GLenum)attachment, (GLenum)rbTarget, renderBuffer);
}

void GLFrameRender::setNamedFrameBufferRenderBuffer(uint32_t framebuffer, FrameBufferAttachment attachment, RenderBufferTarget rbTarget, uint32_t renderBuffer)
{
	glNamedFramebufferRenderbuffer(framebuffer, (GLenum)attachment, (GLenum)rbTarget, renderBuffer);
}

void GLFrameRender::setFrameBufferTexture(FrameBufferTarget target, FrameBufferAttachment attachment, uint32_t texture, int level)
{
	glFramebufferTexture((GLenum)target, (GLenum)attachment, texture, level);
}

void GLFrameRender::setFrameBufferTexture1D(FrameBufferTarget target, FrameBufferAttachment attachment, uint32_t texture, int level)
{
	glFramebufferTexture1D((GLenum)target, (GLenum)attachment, GL_TEXTURE_1D, texture, level);
}

void GLFrameRender::setFrameBufferTexture2D(FrameBufferTarget target, FrameBufferAttachment attachment, uint32_t texture, int level)
{
	glFramebufferTexture2D((GLenum)target, (GLenum)attachment, GL_TEXTURE_2D, texture, level);
}

void GLFrameRender::setFrameBufferTexture3D(FrameBufferTarget target, FrameBufferAttachment attachment, uint32_t texture, int level)
{
	glFramebufferTexture2D((GLenum)target, (GLenum)attachment, GL_TEXTURE_3D, texture, level);
}

void GLFrameRender::setNamedFrameBufferTexture(uint32_t framebuffer, FrameBufferAttachment attachment, uint32_t texture, int level)
{
	glNamedFramebufferTexture(framebuffer, (GLenum)attachment, texture, level);
}

void GLFrameRender::setFrameBufferTextureLayer(FrameBufferTarget target, FrameBufferAttachment attachment, uint32_t texture, int level, int layer)
{
	glFramebufferTextureLayer((GLenum)target, (GLenum)attachment, texture, level, layer);
}

void GLFrameRender::setNamedFrameBufferTextureLayer(uint32_t framebuffer, FrameBufferAttachment attachment, uint32_t texture, int level, int layer)
{
	glNamedFramebufferTextureLayer(framebuffer, (GLenum)attachment, texture, level, layer);
}

void GLFrameRender::genFrameBuffers(int n, uint32_t* ids)
{
	glGenFramebuffers(n, ids);
}

void GLFrameRender::genRenderBuffers(int n, uint32_t* renderbuffers)
{
	glGenRenderbuffers(n, renderbuffers);
}

void GLFrameRender::getFrameBufferAttachmentParameter(FrameBufferTarget target, FrameBufferAttachment attachment, FrameBufferAttachmentParameter name, int* params)
{
	glGetFramebufferAttachmentParameteriv((GLenum)target, (GLenum)attachment, (GLenum)name, params);
}

void GLFrameRender::getNamedFrameBufferAttachmentParameter(uint32_t framebuffer, FrameBufferAttachment attachment, FrameBufferAttachmentParameter name, int* params)
{
	glGetNamedFramebufferAttachmentParameteriv(framebuffer, (GLenum)attachment, (GLenum)name, params);
}

void GLFrameRender::getFrameBufferParameter(FrameBufferTarget target, FrameBufferParameter name, int *params)
{
	glGetFramebufferParameteriv((GLenum)target, (GLenum)name, params);
}

void GLFrameRender::getNamedFrameBufferParameter(uint32_t framebuffer, FrameBufferParameter name, int *params)
{
	glGetNamedFramebufferParameteriv(framebuffer, (GLenum)name, params);
}

void GLFrameRender::getRenderBufferParameter(RenderBufferTarget target, RenderBufferParameter name, int *params)
{
	glGetRenderbufferParameteriv((GLenum)target, (GLenum)name, params);
}

void GLFrameRender::getNamedRenderBufferParameter(uint32_t renderbuffer, RenderBufferParameter name, int *params)
{
	glGetNamedRenderbufferParameteriv(renderbuffer, (GLenum)name, params);
}

void GLFrameRender::invalidateFrameBuffer(FrameBufferTarget target, int num, const FrameBufferAttachment* attachments)
{
	uint32_t* data = new uint32_t[num];
	for (int i = 0; i < num; i++)
	{
		data[i] = (GLenum)attachments[i];
	}
	glInvalidateFramebuffer((GLenum)target, num, data);

	delete[] data;
}

void GLFrameRender::invalidateNamedFrameBuffer(uint32_t framebuffer, int num, const FrameBufferAttachment* attachments)
{
	uint32_t* data = new uint32_t[num];
	for (int i = 0; i < num; i++)
	{
		data[i] = (GLenum)attachments[i];
	}
	glInvalidateNamedFramebufferData(framebuffer, num, data);

	delete[] data;
}

void GLFrameRender::invalidateSubFrameBuffer(FrameBufferTarget target, int num, const FrameBufferAttachment* attachments, int x, int y, int width, int height)
{
	uint32_t* data = new uint32_t[num];
	for (int i = 0; i < num; i++)
	{
		data[i] = (GLenum)attachments[i];
	}
	glInvalidateSubFramebuffer((GLenum)target, num, data, x, y, width, height);

	delete[] data;
}

void GLFrameRender::invalidateNamedFrameBufferSubData(uint32_t framebuffer, int num, const FrameBufferAttachment* attachments, int x, int y, int width, int height)
{
	uint32_t* data = new uint32_t[num];
	for (int i = 0; i < num; i++)
	{
		data[i] = (GLenum)attachments[i];
	}
	glInvalidateNamedFramebufferSubData(framebuffer, num, data, x, y, width, height);

	delete[] data;
}

bool GLFrameRender::isFrameBuffer(uint32_t framebuffer)
{
	return glIsFramebuffer(framebuffer) == GL_TRUE;
}

bool GLFrameRender::isRenderBuffer(uint32_t renderbuffer)
{
	return glIsRenderbuffer(renderbuffer) == GL_TRUE;
}

void GLFrameRender::setRenderBufferStorage(RenderBufferTarget target, RenderBufferInternalFormat format, int width, int height)
{
	glRenderbufferStorage((GLenum)target, (GLenum)format, width, height);
}

void GLFrameRender::setNamedRenderBufferStorage(uint32_t renderbuffer, RenderBufferInternalFormat format, int width, int height)
{
	glNamedRenderbufferStorage(renderbuffer, (GLenum)format, width, height);
}

void GLFrameRender::setRenderBufferStorageMultisample(RenderBufferTarget target, int samples, RenderBufferInternalFormat format, int width, int height)
{
	glRenderbufferStorageMultisample((GLenum)target, samples,(GLenum)format, width, height);
}

void GLFrameRender::setNamedRenderBufferStorageMultisample(uint32_t renderbuffer, int samples, RenderBufferInternalFormat format, int width, int height)
{
	glNamedRenderbufferStorageMultisample(renderbuffer, samples, (GLenum)format, width, height);
}

uint32_t render::GLFrameRender::createFrameBuffer()
{
	uint32_t id = 0;
	createFrameBuffers(1, &id);
	return id;
}

uint32_t render::GLFrameRender::createRenderBuffer()
{
	uint32_t id = 0;
	createRenderBuffers(1, &id);
	return id;
}

void render::GLFrameRender::deleteFrameBuffer(uint32_t framebuffer)
{
	deleteFrameBuffers(1, &framebuffer);
}

void render::GLFrameRender::deleteRenderBuffer(uint32_t renderBuffer)
{
	deleteRenderBuffers(1, &renderBuffer);
}

uint32_t render::GLFrameRender::genFrameBuffer()
{
	uint32_t id = 0;
	genFrameBuffers(1, &id);
	return id;
}

void render::GLFrameRender::setDrawBuffer(DrawBufferType mode)
{
	glDrawBuffer((GLenum)mode);
}

uint32_t render::GLFrameRender::genRenderBuffer()
{
	uint32_t id = 0;
	genRenderBuffers(1, &id);
	return id;
}

