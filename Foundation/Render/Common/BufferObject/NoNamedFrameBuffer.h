#pragma once

#include "FrameBuffer.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class NoNamedFrameBuffer : public FrameBuffer
	{
	public:
		NoNamedFrameBuffer();
		virtual ~NoNamedFrameBuffer();
	public:
		void setParameter(FrameBufferParameter name, int value);
		void setRenderBuffer(FrameBufferAttachment attachment, RenderBufferTarget rbTarget, uint32_t renderBuffer);
		void setTexture(FrameBufferAttachment attachment, uint32_t texture, int level);
		void setTexture1D(FrameBufferAttachment attachment, uint32_t texture, int level);
		void setTexture2D(FrameBufferAttachment attachment, uint32_t texture, int level);
		void setTexture3D(FrameBufferAttachment attachment, uint32_t texture, int level);
		void setTextureLayer(FrameBufferAttachment attachment, uint32_t texture, int level, int layer);

		static void blitFrameBuffer(uint32_t srcX0, uint32_t srcY0, uint32_t srcX1, uint32_t srcY1,
			uint32_t dstX0, uint32_t dstY0, uint32_t dstX1, uint32_t dstY1,
			uint32_t mask, BlitFrameBufferFilter filter);

		GLenum checkStatus();

		void invalidateFrameBuffer(int num, const FrameBufferAttachment* attachments);

		void invalidateSubFrameBuffer(int num, const FrameBufferAttachment* attachments, int x, int y, int width, int height);

		void getAttachmentParameter(FrameBufferAttachment attachment, FrameBufferAttachmentParameter name, int* params);
		void getParameter(FrameBufferParameter name, int* params);
	protected:
	private:
	};
}
