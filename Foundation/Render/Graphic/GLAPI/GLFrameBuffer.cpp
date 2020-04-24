#include "GLFrameBuffer.h"

using namespace render;

void render::GLFrameBuffer::bindVertexArray(FrameBufferTarget target, uint32_t ary)
{
	glBindFramebuffer((GLenum)target, ary);
}

void render::GLFrameBuffer::bindRenderbuffer(RenderBufferTarget target, uint32_t renderBuffer)
{
	glBindRenderbuffer((GLenum)target, renderBuffer);
}

void render::GLFrameBuffer::blitFramebuffer(uint32_t srcX0, uint32_t srcY0, uint32_t srcX1, uint32_t srcY1, uint32_t dstX0, uint32_t dstY0, uint32_t dstX1, uint32_t dstY1, GLbitfield mask, BlitFrameBufferFilter filter)
{
	glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, (GLenum)filter);
}

void render::GLFrameBuffer::blitNamedFramebuffer(uint32_t readFramebuffer, uint32_t drawFramebuffer, uint32_t srcX0, uint32_t srcY0, uint32_t srcX1, uint32_t srcY1, uint32_t dstX0, uint32_t dstY0, uint32_t dstX1, uint32_t dstY1, GLbitfield mask, BlitFrameBufferFilter filter)
{
	glBlitNamedFramebuffer(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, (GLenum)filter);
}

void render::GLFrameBuffer::checkFramebufferStatus(FrameBufferTarget target)
{
	glCheckFramebufferStatus((GLenum)target);
}

void render::GLFrameBuffer::checkNamedFramebufferStatus(uint32_t framebuffer, FrameBufferTarget target)
{
	glCheckNamedFramebufferStatus(framebuffer, (GLenum)target);
}

void render::GLFrameBuffer::createFramebuffers(int n, uint32_t *ids)
{
	glCreateFramebuffers(n, ids);
}

void render::GLFrameBuffer::createRenderbuffers(int n, uint32_t *ids)
{
	glCreateRenderbuffers(n, ids);
}

void render::GLFrameBuffer::deleteFramebuffers(int n, uint32_t *framebuffers)
{
	glDeleteFramebuffers(n, framebuffers);
}

void render::GLFrameBuffer::deleteRenderbuffers(int n, uint32_t *renderBuffers)
{
	glDeleteRenderbuffers(n, renderBuffers);
}

void render::GLFrameBuffer::setDrawBuffers(int n, const DrawBufferType* bufs)
{
	uint32_t* data = new uint32_t[n];
	for (int i = 0; i < n; i++)
	{
		data[i] = (GLenum)bufs[i];
	}

	glDrawBuffers(n, data);

	delete data;
}

void render::GLFrameBuffer::setNamedFramebufferDrawBuffers(uint32_t framebuffer, int n, const DrawBufferType* bufs)
{
	uint32_t* data = new uint32_t[n];
	for (int i = 0; i < n; i++)
	{
		data[i] = (GLenum)bufs[i];
	}

	glNamedFramebufferDrawBuffers(framebuffer, n, data);

	delete data;
}

void render::GLFrameBuffer::setFramebufferParameter(FrameBufferTarget target, FramebufferParameterName name, int value)
{
	glFramebufferParameteri((GLenum)target, (GLenum)name, value);
}

void render::GLFrameBuffer::setNamedFramebufferParameter(uint32_t framebuffer, FramebufferParameterName name, int value)
{
	glNamedFramebufferParameteri(framebuffer, (GLenum)name, value);
}

void render::GLFrameBuffer::setFramebufferRenderbuffer(FrameBufferTarget target, FramebufferAttachment attachment, RenderBufferTarget rbTarget, uint32_t renderBuffer)
{
	glFramebufferRenderbuffer((GLenum)target, (GLenum)attachment, (GLenum)rbTarget, renderBuffer);
}

void render::GLFrameBuffer::setNamedFramebufferRenderbuffer(uint32_t framebuffer, FramebufferAttachment attachment, RenderBufferTarget rbTarget, uint32_t renderBuffer)
{
	glNamedFramebufferRenderbuffer(framebuffer, (GLenum)attachment, (GLenum)rbTarget, renderBuffer);
}

void GLFrameBuffer::setFramebufferTexture(FrameBufferTarget target, FramebufferAttachment attachment, uint32_t texture, int level)
{
	glFramebufferTexture((GLenum)target, (GLenum)attachment, texture, level);
}

void render::GLFrameBuffer::setFramebufferTexture1D(FrameBufferTarget target, FramebufferAttachment attachment, uint32_t texture, int level)
{
	glFramebufferTexture1D((GLenum)target, (GLenum)attachment, GL_TEXTURE_1D, texture, level);
}

void render::GLFrameBuffer::setFramebufferTexture2D(FrameBufferTarget target, FramebufferAttachment attachment, uint32_t texture, int level)
{
	glFramebufferTexture2D((GLenum)target, (GLenum)attachment, GL_TEXTURE_2D, texture, level);
}

void render::GLFrameBuffer::setFramebufferTexture3D(FrameBufferTarget target, FramebufferAttachment attachment, uint32_t texture, int level)
{
	glFramebufferTexture2D((GLenum)target, (GLenum)attachment, GL_TEXTURE_3D, texture, level);
}

void render::GLFrameBuffer::setNamedFramebufferTexture(uint32_t framebuffer, FramebufferAttachment attachment, uint32_t texture, int level)
{
	glNamedFramebufferTexture(framebuffer, (GLenum)attachment, texture, level);
}

void render::GLFrameBuffer::setFramebufferTextureLayer(FrameBufferTarget target, FramebufferAttachment attachment, uint32_t texture, int level, int layer)
{
	glFramebufferTextureLayer((GLenum)target, (GLenum)attachment, texture, level, layer);
}

void render::GLFrameBuffer::setNamedFramebufferTextureLayer(uint32_t framebuffer, FramebufferAttachment attachment, uint32_t texture, int level, int layer)
{
	glNamedFramebufferTextureLayer(framebuffer, (GLenum)attachment, texture, level, layer);
}

void render::GLFrameBuffer::genFramebuffers(int n, uint32_t* ids)
{
	glGenFramebuffers(n, ids);
}

void render::GLFrameBuffer::genRenderbuffers(int n, uint32_t* renderbuffers)
{
	glGenRenderbuffers(n, renderbuffers);
}

void render::GLFrameBuffer::generateMipmap(MipmapTextureTarget target)
{
	glGenerateMipmap((GLenum)target);
}

void render::GLFrameBuffer::generateTextureMipmap(uint32_t texture)
{
	glGenerateTextureMipmap(texture);
}

void render::GLFrameBuffer::getFramebufferAttachmentParameter(FrameBufferTarget target, FramebufferAttachment attachment, FramebufferAttachmentParameter name, int* params)
{
	glGetFramebufferAttachmentParameteriv((GLenum)target, (GLenum)attachment, (GLenum)name, params);
}

void render::GLFrameBuffer::getNamedFramebufferAttachmentParameter(uint32_t framebuffer, FramebufferAttachment attachment, FramebufferAttachmentParameter name, int* params)
{
	glGetNamedFramebufferAttachmentParameteriv(framebuffer, (GLenum)attachment, (GLenum)name, params);
}

void render::GLFrameBuffer::getFramebufferParameter(FrameBufferTarget target, AllFramebufferParameterName name, int *params)
{
	glGetFramebufferParameteriv((GLenum)target, (GLenum)name, params);
}

void render::GLFrameBuffer::getNamedFramebufferParameter(uint32_t framebuffer, FramebufferParameterName name, int *params)
{
	glGetNamedFramebufferParameteriv(framebuffer, (GLenum)name, params);
}

void render::GLFrameBuffer::getRenderbufferParameter(RenderBufferTarget target, RenderbufferParameterName name, int *params)
{
	glGetRenderbufferParameteriv((GLenum)target, (GLenum)name, params);
}

void render::GLFrameBuffer::getNamedRenderbufferParameter(uint32_t renderbuffer, RenderbufferParameterName name, int *params)
{
	glGetNamedRenderbufferParameteriv(renderbuffer, (GLenum)name, params);
}

void render::GLFrameBuffer::invalidateFramebuffer(FrameBufferTarget target, int num, const FramebufferAttachment* attachments)
{
	uint32_t* data = new uint32_t[num];
	for (int i = 0; i < num; i++)
	{
		data[i] = (GLenum)attachments[i];
	}
	glInvalidateFramebuffer((GLenum)target, num, data);

	delete data;
}

void render::GLFrameBuffer::invalidateNamesFramebuffer(uint32_t framebuffer, int num, const FramebufferAttachment* attachments)
{
	uint32_t* data = new uint32_t[num];
	for (int i = 0; i < num; i++)
	{
		data[i] = (GLenum)attachments[i];
	}
	glInvalidateNamedFramebufferData(framebuffer, num, data);

	delete data;
}

void render::GLFrameBuffer::invalidateSubFramebuffer(FrameBufferTarget target, int num, const FramebufferAttachment* attachments, int x, int y, int width, int height)
{
	uint32_t* data = new uint32_t[num];
	for (int i = 0; i < num; i++)
	{
		data[i] = (GLenum)attachments[i];
	}
	glInvalidateSubFramebuffer((GLenum)target, num, data, x, y, width, height);

	delete data;
}

void render::GLFrameBuffer::invalidateNamedFramebufferSubData(uint32_t framebuffer, int num, const FramebufferAttachment* attachments, int x, int y, int width, int height)
{
	uint32_t* data = new uint32_t[num];
	for (int i = 0; i < num; i++)
	{
		data[i] = (GLenum)attachments[i];
	}
	glInvalidateNamedFramebufferSubData(framebuffer, num, data, x, y, width, height);

	delete data;
}

bool render::GLFrameBuffer::isFramebuffer(uint32_t framebuffer)
{
	return glIsFramebuffer(framebuffer) == GL_TRUE;
}

bool render::GLFrameBuffer::isRenderbuffer(uint32_t renderbuffer)
{
	return glIsRenderbuffer(renderbuffer) == GL_TRUE;
}

void render::GLFrameBuffer::setRenderbufferStorage(RenderBufferTarget target, InternalImageFormat format, int width, int height)
{
	glRenderbufferStorage((GLenum)target, (GLenum)format, width, height);
}

void render::GLFrameBuffer::setNamedRenderbufferStorage(uint32_t renderbuffer, InternalImageFormat format, int width, int height)
{
	glNamedRenderbufferStorage(renderbuffer, (GLenum)format, width, height);
}

void render::GLFrameBuffer::setRenderbufferStorageMultisample(RenderBufferTarget target, int samples, InternalImageFormat format, int width, int height)
{
	glRenderbufferStorageMultisample((GLenum)target, samples,(GLenum)format, width, height);
}

void render::GLFrameBuffer::setNamedRenderbufferStorageMultisample(uint32_t renderbuffer, int samples, InternalImageFormat format, int width, int height)
{
	glNamedRenderbufferStorageMultisample(renderbuffer, samples, (GLenum)format, width, height);
}

void render::GLFrameBuffer::setSampleMask(uint32_t maskNumber, GLbitfield mask)
{
	glSampleMaski(maskNumber, mask);
}

