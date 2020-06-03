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
	GLFrameRender::getNamedRenderBufferParameter(getRenderBufferID(), name, params);
}

void render::NamedRenderBuffer::setStorage(RenderBufferInternalFormat format, int width, int height)
{
	GLFrameRender::setNamedRenderBufferStorage(getRenderBufferID(), format, width, height);
}

void render::NamedRenderBuffer::setStorageMultisample(int samples, RenderBufferInternalFormat format, int width, int height)
{
	GLFrameRender::setNamedRenderBufferStorageMultisample(getRenderBufferID(), samples, format, width, height);
}

