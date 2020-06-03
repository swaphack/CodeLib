#include "RenderBuffer.h"

#include "Graphic/import.h"

render::RenderBuffer::RenderBuffer()
{

}

render::RenderBuffer::~RenderBuffer()
{

}

void render::RenderBuffer::getParameter(RenderBufferParameter name, int* params)
{
	GLFrameRender::getRenderBufferParameter(getRenderBufferTarget(), name, params);
}

void render::RenderBuffer::setStorage(RenderBufferInternalFormat format, int width, int height)
{
	GLFrameRender::setRenderBufferStorage(getRenderBufferTarget(), format, width, height);
}

void render::RenderBuffer::setStorageMultisample(int samples, RenderBufferInternalFormat format, int width, int height)
{
	GLFrameRender::setRenderBufferStorage(getRenderBufferTarget(), format, width, height);
}

