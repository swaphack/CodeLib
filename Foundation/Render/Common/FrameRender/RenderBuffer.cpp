#include "RenderBuffer.h"
#include "Graphic/import.h"

render::RenderBuffer::RenderBuffer()
{
	this->initRenderBuffer();
}

render::RenderBuffer::~RenderBuffer()
{
	this->relaseRenderBuffer();
}

bool render::RenderBuffer::isValid()
{
	return GLFrameBuffer::isRenderBuffer(_renderBufferID);
}

uint32_t render::RenderBuffer::getRenderBufferID() const
{
	return _renderBufferID;
}

void render::RenderBuffer::setRenderBufferTarget(RenderBufferTarget target)
{
	_renderBufferTarget = target;
}

RenderBufferTarget render::RenderBuffer::getRenderBufferTarget() const
{
	return _renderBufferTarget;
}

void render::RenderBuffer::initRenderBuffer()
{
	_renderBufferID = GLFrameBuffer::createRenderBuffer();
}

void render::RenderBuffer::relaseRenderBuffer()
{
	GLFrameBuffer::deleteRenderBuffer(_renderBufferID);
	_renderBufferID = 0;
}

