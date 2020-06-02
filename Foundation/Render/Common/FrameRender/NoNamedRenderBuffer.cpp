#include "NoNamedRenderBuffer.h"

#include "Graphic/import.h"

render::NoNamedRenderBuffer::NoNamedRenderBuffer()
{

}

render::NoNamedRenderBuffer::~NoNamedRenderBuffer()
{

}

void render::NoNamedRenderBuffer::getParameter(RenderBufferParameter name, int* params)
{
	GLFrameBuffer::getRenderBufferParameter(getRenderBufferTarget(), name, params);
}

void render::NoNamedRenderBuffer::setStorage(InternalImageFormat format, int width, int height)
{
	GLFrameBuffer::setRenderBufferStorage(getRenderBufferTarget(), format, width, height);
}

void render::NoNamedRenderBuffer::setStorageMultisample(int samples, InternalImageFormat format, int width, int height)
{
	GLFrameBuffer::setRenderBufferStorage(getRenderBufferTarget(), format, width, height);
}

