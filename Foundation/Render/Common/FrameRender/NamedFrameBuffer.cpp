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
	GLFrameBuffer::setNamedFrameBufferDrawBuffers(getFrameBufferID(), n, bufs);
}

void render::NamedFrameBuffer::setParameter(FrameBufferParameter name, int value)
{
	GLFrameBuffer::setNamedFrameBufferParameter(getFrameBufferID(), name, value);
}

void render::NamedFrameBuffer::setRenderBuffer(FrameBufferAttachment attachment, RenderBufferTarget rbTarget, uint32_t renderBuffer)
{
	GLFrameBuffer::setNamedFrameBufferRenderBuffer(getFrameBufferID(), attachment, rbTarget, renderBuffer);
}

void render::NamedFrameBuffer::setTexture(FrameBufferAttachment attachment, uint32_t texture, int level)
{
	GLFrameBuffer::setNamedFrameBufferTexture(getFrameBufferID(), attachment, texture, level);
}

void render::NamedFrameBuffer::setTextureLayer(FrameBufferAttachment attachment, uint32_t texture, int level, int layer)
{
	GLFrameBuffer::setNamedFrameBufferTextureLayer(getFrameBufferID(), attachment, texture, level, layer);
}

void render::NamedFrameBuffer::blitFrameBuffer(uint32_t readFrameBuffer, uint32_t drawFrameBuffer,
	uint32_t srcX0, uint32_t srcY0, uint32_t srcX1, uint32_t srcY1, uint32_t dstX0, uint32_t dstY0, uint32_t dstX1, uint32_t dstY1, uint32_t mask, BlitFrameBufferFilter filter)
{
	GLFrameBuffer::blitNamedFrameBuffer(readFrameBuffer, drawFrameBuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

GLenum render::NamedFrameBuffer::checkStatus()
{
	return GLFrameBuffer::checkNamedFrameBufferStatus(getFrameBufferID(), getFrameBufferTarget());
}

void render::NamedFrameBuffer::invalidateFrameBuffer(int num, const FrameBufferAttachment* attachments)
{
	GLFrameBuffer::invalidateNamedFrameBuffer(getFrameBufferID(), num, attachments);
}

void render::NamedFrameBuffer::invalidateSubFrameBuffer(int num, const FrameBufferAttachment* attachments, int x, int y, int width, int height)
{
	GLFrameBuffer::invalidateNamedFrameBufferSubData(getFrameBufferID(), num, attachments, x, y, width, height);
}

void render::NamedFrameBuffer::getAttachmentParameter(FrameBufferAttachment attachment, FrameBufferAttachmentParameter name, int* params)
{
	GLFrameBuffer::getNamedFrameBufferAttachmentParameter(getFrameBufferID(), attachment, name, params);
}

void render::NamedFrameBuffer::getParameter(FrameBufferParameter name, int* params)
{
	GLFrameBuffer::getNamedFrameBufferParameter(getFrameBufferID(), name, params);
}

