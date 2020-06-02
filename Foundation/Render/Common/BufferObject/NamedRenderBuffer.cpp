#include "NamedRenderBuffer.h"
#include "Graphic/import.h"

render::NamedRenderBuffer::NamedRenderBuffer()
{

}

render::NamedRenderBuffer::~NamedRenderBuffer()
{

}

void render::NamedRenderBuffer::getParameter(RenderBufferParameter name, int* params)
{
	GLFrameBuffer::getNamedRenderBufferParameter(getRenderBufferID(), name, params);
}

void render::NamedRenderBuffer::setStorage(InternalImageFormat format, int width, int height)
{
	GLFrameBuffer::setNamedRenderBufferStorage(getRenderBufferID(), format, width, height);
}

void render::NamedRenderBuffer::setStorageMultisample(int samples, InternalImageFormat format, int width, int height)
{
	GLFrameBuffer::setNamedRenderBufferStorageMultisample(getRenderBufferID(), samples, format, width, height);
}

