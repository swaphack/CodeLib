#include "NamedFrameBuffer.h"
#include "Graphic/import.h"
render::NamedFrameBuffer::NamedFrameBuffer()
{

}

render::NamedFrameBuffer::~NamedFrameBuffer()
{

}

void render::NamedFrameBuffer::setDrawBuffers(int n, const DrawBufferType* bufs)
{
	GLFrameRender::setNamedFrameBufferDrawBuffers(getFrameBufferID(), n, bufs);
}

void render::NamedFrameBuffer::setParameter(FrameBufferParameter name, int value)
{
	GLFrameRender::setNamedFrameBufferParameter(getFrameBufferID(), name, value);
}

void render::NamedFrameBuffer::setRenderBuffer(FrameBufferAttachment attachment, RenderBufferTarget rbTarget, uint32_t renderBuffer)
{
	GLFrameRender::setNamedFrameBufferRenderBuffer(getFrameBufferID(), attachment, rbTarget, renderBuffer);
}

void render::NamedFrameBuffer::setTexture(FrameBufferAttachment attachment, uint32_t texture, int level)
{
	GLFrameRender::setNamedFrameBufferTexture(getFrameBufferID(), attachment, texture, level);
}

void render::NamedFrameBuffer::setTextureLayer(FrameBufferAttachment attachment, uint32_t texture, int level, int layer)
{
	GLFrameRender::setNamedFrameBufferTextureLayer(getFrameBufferID(), attachment, texture, level, layer);
}

void render::NamedFrameBuffer::blitFrameBuffer(uint32_t readFrameBuffer, uint32_t drawFrameBuffer,
	uint32_t srcX0, uint32_t srcY0, uint32_t srcX1, uint32_t srcY1, uint32_t dstX0, uint32_t dstY0, uint32_t dstX1, uint32_t dstY1, uint32_t mask, BlitFrameBufferFilter filter)
{
	GLFrameRender::blitNamedFrameBuffer(readFrameBuffer, drawFrameBuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

FrameBufferStatus render::NamedFrameBuffer::checkStatus()
{
	return GLFrameRender::checkNamedFrameBufferStatus(getFrameBufferID(), getFrameBufferTarget());
}

void render::NamedFrameBuffer::invalidateFrameBuffer(int num, const FrameBufferAttachment* attachments)
{
	GLFrameRender::invalidateNamedFrameBuffer(getFrameBufferID(), num, attachments);
}

void render::NamedFrameBuffer::invalidateSubFrameBuffer(int num, const FrameBufferAttachment* attachments, int x, int y, int width, int height)
{
	GLFrameRender::invalidateNamedFrameBufferSubData(getFrameBufferID(), num, attachments, x, y, width, height);
}

void render::NamedFrameBuffer::getAttachmentParameter(FrameBufferAttachment attachment, FrameBufferAttachmentParameter name, int* params)
{
	GLFrameRender::getNamedFrameBufferAttachmentParameter(getFrameBufferID(), attachment, name, params);
}

void render::NamedFrameBuffer::getParameter(FrameBufferParameter name, int* params)
{
	GLFrameRender::getNamedFrameBufferParameter(getFrameBufferID(), name, params);
}

