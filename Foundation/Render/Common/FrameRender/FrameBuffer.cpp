#include "FrameBuffer.h"
#include "Graphic/import.h"
#include "RenderBufferBase.h"

render::FrameBuffer::FrameBuffer()
{

}

render::FrameBuffer::~FrameBuffer()
{

}

void render::FrameBuffer::setParameter(FrameBufferParameter name, int value)
{
	GLFrameRender::setFrameBufferParameter(getFrameBufferTarget(), name, value);
}

void render::FrameBuffer::setRenderBuffer(FrameBufferAttachment attachment, RenderBufferTarget rbTarget, uint32_t renderBuffer)
{
	GLFrameRender::setFrameBufferRenderBuffer(getFrameBufferTarget(), attachment, rbTarget, renderBuffer);
}

void render::FrameBuffer::setRenderBuffer(FrameBufferAttachment attachment, RenderBufferBase* renderBuffer)
{
	if (renderBuffer == nullptr)
	{
		return;
	}
	this->setRenderBuffer(attachment, renderBuffer->getRenderBufferTarget(), renderBuffer->getRenderBufferID());
}

void render::FrameBuffer::setTexture(FrameBufferAttachment attachment, uint32_t texture, int level)
{
	GLFrameRender::setFrameBufferTexture(getFrameBufferTarget(), attachment, texture, level);
}

void render::FrameBuffer::setTexture1D(FrameBufferAttachment attachment, uint32_t texture, int level)
{
	GLFrameRender::setFrameBufferTexture1D(getFrameBufferTarget(), attachment, texture, level);
}

void render::FrameBuffer::setTexture2D(FrameBufferAttachment attachment, uint32_t texture, int level)
{
	GLFrameRender::setFrameBufferTexture2D(getFrameBufferTarget(), attachment, texture, level);
}

void render::FrameBuffer::setTexture3D(FrameBufferAttachment attachment, uint32_t texture, int level)
{
	GLFrameRender::setFrameBufferTexture3D(getFrameBufferTarget(), attachment, texture, level);
}

void render::FrameBuffer::setTextureLayer(FrameBufferAttachment attachment, uint32_t texture, int level, int layer)
{
	GLFrameRender::setFrameBufferTextureLayer(getFrameBufferTarget(), attachment, texture, level, layer);
}

void render::FrameBuffer::blitFrameBuffer(uint32_t srcX0, uint32_t srcY0, uint32_t srcX1, uint32_t srcY1, uint32_t dstX0, uint32_t dstY0, uint32_t dstX1, uint32_t dstY1, uint32_t mask, BlitFrameBufferFilter filter)
{
	GLFrameRender::blitFrameBuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

FrameBufferStatus render::FrameBuffer::checkStatus()
{
	return GLFrameRender::checkFrameBufferStatus(getFrameBufferTarget());
}

void render::FrameBuffer::invalidateFrameBuffer(int num, const FrameBufferAttachment* attachments)
{
	GLFrameRender::invalidateFrameBuffer(getFrameBufferTarget(), num, attachments);
}

void render::FrameBuffer::invalidateSubFrameBuffer(int num, const FrameBufferAttachment* attachments, int x, int y, int width, int height)
{
	GLFrameRender::invalidateSubFrameBuffer(getFrameBufferTarget(), num, attachments, x, y, width, height);
}

void render::FrameBuffer::getAttachmentParameter(FrameBufferAttachment attachment, FrameBufferAttachmentParameter name, int* params)
{
	GLFrameRender::getFrameBufferAttachmentParameter(getFrameBufferTarget(), attachment, name, params);
}

void render::FrameBuffer::getParameter(FrameBufferParameter name, int* params)
{
	GLFrameRender::getFrameBufferParameter(getFrameBufferTarget(), name, params);
}

