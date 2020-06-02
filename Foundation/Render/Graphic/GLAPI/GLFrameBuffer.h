#pragma once

#include "macros.h"

namespace render
{
	class GLFrameBuffer
	{
	public:
		static uint32_t createFrameBuffer();
		static void createFrameBuffers(int n, uint32_t* ids);

		static void deleteFrameBuffer(uint32_t framebuffer);
		static void deleteFrameBuffers(int n, uint32_t* framebuffers);

	public:
		static uint32_t	genFrameBuffer();
		static void genFrameBuffers(int n, uint32_t* ids);
	public:
		static bool isFrameBuffer(uint32_t framebuffer);

		static void bindFramebuffer(FrameBufferTarget target, uint32_t frameBuffer);
	public:
		static void blitFrameBuffer(uint32_t srcX0, uint32_t srcY0, uint32_t srcX1, uint32_t srcY1,
			uint32_t dstX0, uint32_t dstY0, uint32_t dstX1, uint32_t dstY1,
			uint32_t mask, BlitFrameBufferFilter filter);
		static void blitNamedFrameBuffer(uint32_t readFrameBuffer, uint32_t drawFrameBuffer,
			uint32_t srcX0, uint32_t srcY0, uint32_t srcX1, uint32_t srcY1,
			uint32_t dstX0, uint32_t dstY0, uint32_t dstX1, uint32_t dstY1,
			uint32_t mask, BlitFrameBufferFilter filter);

		static GLenum checkFrameBufferStatus(FrameBufferTarget target);
		static GLenum checkNamedFrameBufferStatus(uint32_t framebuffer, FrameBufferTarget target);
		
	public:
		static void setDrawBuffers(int n, const DrawBufferType* bufs);
	public:
		static void setNamedFrameBufferDrawBuffers(uint32_t framebuffer, int n, const DrawBufferType* bufs);
		static void setNamedFrameBufferParameter(uint32_t framebuffer, FrameBufferParameter name, int value);
		static void setNamedFrameBufferRenderBuffer(uint32_t framebuffer, FrameBufferAttachment attachment, RenderBufferTarget rbTarget, uint32_t renderBuffer);
		static void setNamedFrameBufferTexture(uint32_t framebuffer, FrameBufferAttachment attachment, uint32_t texture, int level);
		static void setNamedFrameBufferTextureLayer(uint32_t framebuffer, FrameBufferAttachment attachment, uint32_t texture, int level, int layer);

		static void setFrameBufferParameter(FrameBufferTarget target, FrameBufferParameter name, int value);
		static void setFrameBufferRenderBuffer(FrameBufferTarget target, FrameBufferAttachment attachment, RenderBufferTarget rbTarget, uint32_t renderBuffer);
		static void setFrameBufferTexture(FrameBufferTarget target, FrameBufferAttachment attachment, uint32_t texture, int level);
		static void setFrameBufferTexture1D(FrameBufferTarget target, FrameBufferAttachment attachment, uint32_t texture, int level);
		static void setFrameBufferTexture2D(FrameBufferTarget target, FrameBufferAttachment attachment, uint32_t texture, int level);
		static void setFrameBufferTexture3D(FrameBufferTarget target, FrameBufferAttachment attachment, uint32_t texture, int level);
		static void setFrameBufferTextureLayer(FrameBufferTarget target, FrameBufferAttachment attachment, uint32_t texture, int level, int layer);
		
	
	public:
		static void invalidateFrameBuffer(FrameBufferTarget target, int num, const FrameBufferAttachment* attachments);

		static void invalidateSubFrameBuffer(FrameBufferTarget target, int num, const FrameBufferAttachment* attachments, int x, int y, int width, int height);

		static void invalidateNamedFrameBuffer(uint32_t framebuffer, int num, const FrameBufferAttachment* attachments);
		static void invalidateNamedFrameBufferSubData(uint32_t framebuffer, int num, const FrameBufferAttachment* attachments, int x, int y, int width, int height);
	
	public:
		static void getFrameBufferAttachmentParameter(FrameBufferTarget target, FrameBufferAttachment attachment, FrameBufferAttachmentParameter name, int* params);
		static void getFrameBufferParameter(FrameBufferTarget target, FrameBufferParameter name, int* params);

		static void getNamedFrameBufferAttachmentParameter(uint32_t framebuffer, FrameBufferAttachment attachment, FrameBufferAttachmentParameter name, int* params);
		static void getNamedFrameBufferParameter(uint32_t framebuffer, FrameBufferParameter name, int* params);

		//////////////////////////////////////////////////////////////////////////
	public:
		static void	bindRenderBuffer(RenderBufferTarget target, uint32_t renderBuffer);

		static uint32_t	genRenderBuffer();
		static void genRenderBuffers(int n, uint32_t* renderbuffers);

		static uint32_t createRenderBuffer();
		static void createRenderBuffers(int n, uint32_t* ids);

		static void deleteRenderBuffer(uint32_t renderBuffer);
		static void deleteRenderBuffers(int n, uint32_t* renderBuffers);
	public:
		static void setRenderBufferStorage(RenderBufferTarget target, InternalImageFormat format, int width, int height);
		static void setRenderBufferStorageMultisample(RenderBufferTarget target, int samples, InternalImageFormat format, int width, int height);
		static void getRenderBufferParameter(RenderBufferTarget target, RenderBufferParameter name, int* params);
	
		static bool isRenderBuffer(uint32_t renderbuffer);
	public:
		static void setNamedRenderBufferStorage(uint32_t renderbuffer, InternalImageFormat format, int width, int height);
		static void getNamedRenderBufferParameter(uint32_t renderbuffer, RenderBufferParameter name, int* params);
		static void setNamedRenderBufferStorageMultisample(uint32_t renderbuffer, int samples, InternalImageFormat format, int width, int height);
	};
}