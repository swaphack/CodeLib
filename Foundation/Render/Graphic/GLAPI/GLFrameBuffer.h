#pragma once

#include "macros.h"

namespace render
{
	class GLFrameBuffer
	{
	public:
		static void bindVertexArray(FrameBufferTarget target, uint32_t ary);
		static void		bindRenderbuffer(RenderBufferTarget target, uint32_t renderBuffer);
		static void 	blitFramebuffer(uint32_t srcX0, uint32_t srcY0, uint32_t srcX1, uint32_t srcY1,
			uint32_t dstX0, uint32_t dstY0, uint32_t dstX1, uint32_t dstY1,
			uint32_t mask, BlitFrameBufferFilter filter);
		static void 	blitNamedFramebuffer(uint32_t readFramebuffer, uint32_t drawFramebuffer,
			uint32_t srcX0, uint32_t srcY0, uint32_t srcX1, uint32_t srcY1,
			uint32_t dstX0, uint32_t dstY0, uint32_t dstX1, uint32_t dstY1,
			uint32_t mask, BlitFrameBufferFilter filter);
		static void 	checkFramebufferStatus(FrameBufferTarget target);
		static void 	checkNamedFramebufferStatus(uint32_t framebuffer, FrameBufferTarget target);
		static void 	createFramebuffers(int n, uint32_t *ids);
		static void 	createRenderbuffers(int n, uint32_t *ids);
		static void 	deleteFramebuffers(int n, uint32_t *framebuffers);
		static void 	deleteRenderbuffers(int n, uint32_t *renderBuffers);
		static void 	setDrawBuffers(int n, const DrawBufferType* bufs);
		static void 	setNamedFramebufferDrawBuffers(uint32_t framebuffer, int n, const DrawBufferType* bufs);
		static void 	setFramebufferParameter(FrameBufferTarget target, FramebufferParameter name, int value);
		static void 	setNamedFramebufferParameter(uint32_t framebuffer, FramebufferParameter name, int value);
		static void 	setFramebufferRenderbuffer(FrameBufferTarget target, FramebufferAttachment attachment, RenderBufferTarget rbTarget, uint32_t renderBuffer);
		static void 	setNamedFramebufferRenderbuffer(uint32_t framebuffer, FramebufferAttachment attachment, RenderBufferTarget rbTarget, uint32_t renderBuffer);
		static void 	setFramebufferTexture(FrameBufferTarget target, FramebufferAttachment attachment, uint32_t texture, int level);
		static void 	setFramebufferTexture1D(FrameBufferTarget target, FramebufferAttachment attachment, uint32_t texture, int level);
		static void 	setFramebufferTexture2D(FrameBufferTarget target, FramebufferAttachment attachment, uint32_t texture, int level);
		static void 	setFramebufferTexture3D(FrameBufferTarget target, FramebufferAttachment attachment, uint32_t texture, int level);
		static void 	setNamedFramebufferTexture(uint32_t framebuffer, FramebufferAttachment attachment, uint32_t texture, int level);

		static void 	setFramebufferTextureLayer(FrameBufferTarget target, FramebufferAttachment attachment, uint32_t texture, int level, int layer);
		static void 	setNamedFramebufferTextureLayer(uint32_t framebuffer, FramebufferAttachment attachment, uint32_t texture, int level, int layer);

		static void 	genFramebuffers(int n, uint32_t* ids);
		static void 	genRenderbuffers(int n, uint32_t* renderbuffers);
		static void 	generateMipmap(MipmapTextureTarget target);
		static void 	generateTextureMipmap(uint32_t texture);
		static void 	getFramebufferAttachmentParameter(FrameBufferTarget target, FramebufferAttachment attachment, FramebufferAttachmentParameter name, int* params);
		static void 	getNamedFramebufferAttachmentParameter(uint32_t framebuffer, FramebufferAttachment attachment, FramebufferAttachmentParameter name, int* params);

		static void 	getFramebufferParameter(FrameBufferTarget target, AllFramebufferParameter name, int *params);
		static void 	getNamedFramebufferParameter(uint32_t framebuffer, FramebufferParameter name, int *params);
		static void 	getRenderbufferParameter(RenderBufferTarget target, RenderbufferParameter name, int *params);
		static void 	getNamedRenderbufferParameter(uint32_t renderbuffer, RenderbufferParameter name, int *params);
		static void 	invalidateFramebuffer(FrameBufferTarget target, int num, const FramebufferAttachment* attachments);
		static void 	invalidateNamesFramebuffer(uint32_t framebuffer, int num, const FramebufferAttachment* attachments);
		static void 	invalidateSubFramebuffer(FrameBufferTarget target, int num, const FramebufferAttachment* attachments, int x, int y, int width, int height);
		static void 	invalidateNamedFramebufferSubData(uint32_t framebuffer, int num, const FramebufferAttachment* attachments, int x, int y, int width, int height);
		static bool 	isFramebuffer(uint32_t framebuffer);
		static bool 	isRenderbuffer(uint32_t renderbuffer);
		static void 	setRenderbufferStorage(RenderBufferTarget target, InternalImageFormat format, int width, int height);
		static void 	setNamedRenderbufferStorage(uint32_t renderbuffer, InternalImageFormat format, int width, int height);
		static void 	setRenderbufferStorageMultisample(RenderBufferTarget target, int samples, InternalImageFormat format, int width, int height);
		static void 	setNamedRenderbufferStorageMultisample(uint32_t renderbuffer, int samples, InternalImageFormat format, int width, int height);

		
	};
}