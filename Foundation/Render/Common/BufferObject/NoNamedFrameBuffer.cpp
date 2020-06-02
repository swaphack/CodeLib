#include "NoNamedFrameBuffer.h"
#include "Graphic/import.h"

render::NoNamedFrameBuffer::NoNamedFrameBuffer()
{

}

render::NoNamedFrameBuffer::~NoNamedFrameBuffer()
{

}

void render::NoNamedFrameBuffer::setParameter(FrameBufferParameter name, int value)
{
	GLFrameBuffer::setFrameBufferParameter(getFrameBufferTarget(), name, value);
}

void render::NoNamedFrameBuffer::setRenderBuffer(FrameBufferAttachment attachment, RenderBufferTarget rbTarget, uint32_t renderBuffer)
{
	GLFrameBuffer::setFrameBufferRenderBuffer(getFrameBufferTarget(), attachment, rbTarget, renderBuffer);
}

void render::NoNamedFrameBuffer::setTexture(FrameBufferAttachment attachment, uint32_t texture, int level)
{
	GLFrameBuffer::setFrameBufferTexture(getFrameBufferTarget(), attachment, texture, level);
}

void render::NoNamedFrameBuffer::setTexture1D(FrameBufferAttachment attachment, uint32_t texture, int level)
{
	GLFrameBuffer::setFrameBufferTexture1D(getFrameBufferTarget(), attachment, texture, level);
}

void render::NoNamedFrameBuffer::setTexture2D(FrameBufferAttachment attachment, uint32_t texture, int level)
{
	GLFrameBuffer::setFrameBufferTexture2D(getFrameBufferTarget(), attachment, texture, level);
}

void render::NoNamedFrameBuffer::setTexture3D(FrameBufferAttachment attachment, uint32_t texture, int level)
{
	GLFrameBuffer::setFrameBufferTexture3D(getFrameBufferTarget(), attachment, texture, level);
}

void render::NoNamedFrameBuffer::setTextureLayer(FrameBufferAttachment attachment, uint32_t texture, int level, int layer)
{
	GLFrameBuffer::setFrameBufferTextureLayer(getFrameBufferTarget(), attachment, texture, level, layer);
}

void render::NoNamedFrameBuffer::blitFrameBuffer(uint32_t srcX0, uint32_t srcY0, uint32_t srcX1, uint32_t srcY1, uint32_t dstX0, uint32_t dstY0, uint32_t dstX1, uint32_t dstY1, uint32_t mask, BlitFrameBufferFilter filter)
{
	GLFrameBuffer::blitFrameBuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

GLenum render::NoNamedFrameBuffer::checkStatus()
{
	return GLFrameBuffer::checkFrameBufferStatus(getFrameBufferTarget());
}

void render::NoNamedFrameBuffer::invalidateFrameBuffer(int num, const FrameBufferAttachment* attachments)
{
	GLFrameBuffer::invalidateFrameBuffer(getFrameBufferTarget(), num, attachments);
}

void render::NoNamedFrameBuffer::invalidateSubFrameBuffer(int num, const FrameBufferAttachment* attachments, int x, int y, int width, int height)
{
	GLFrameBuffer::invalidateSubFrameBuffer(getFrameBufferTarget(), num, attachments, x, y, width, height);
}

void render::NoNamedFrameBuffer::getAttachmentParameter(FrameBufferAttachment attachment, FrameBufferAttachmentParameter name, int* params)
{
	GLFrameBuffer::getFrameBufferAttachmentParameter(getFrameBufferTarget(), attachment, name, params);
}

void render::NoNamedFrameBuffer::getParameter(FrameBufferParameter name, int* params)
{
	GLFrameBuffer::getFrameBufferParameter(getFrameBufferTarget(), name, params);
}

