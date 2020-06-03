#include "RenderBufferBase.h"
#include "Graphic/import.h"

render::RenderBufferBase::RenderBufferBase()
{
	this->initRenderBuffer();
}

render::RenderBufferBase::~RenderBufferBase()
{
	this->relaseRenderBuffer();
}

bool render::RenderBufferBase::isValid()
{
	return GLFrameRender::isRenderBuffer(_renderBufferID);
}

uint32_t render::RenderBufferBase::getRenderBufferID() const
{
	return _renderBufferID;
}

void render::RenderBufferBase::setRenderBufferTarget(RenderBufferTarget target)
{
	_renderBufferTarget = target;
}

RenderBufferTarget render::RenderBufferBase::getRenderBufferTarget() const
{
	return _renderBufferTarget;
}

void render::RenderBufferBase::bindRenderBuffer()
{
	GLFrameRender::bindRenderBuffer(getRenderBufferTarget(), _renderBufferID);
}

void render::RenderBufferBase::unbindRenderBuffer()
{
	GLFrameRender::bindRenderBuffer(getRenderBufferTarget(), 0);
}

void render::RenderBufferBase::initRenderBuffer()
{
	_renderBufferID = GLFrameRender::createRenderBuffer();
}

void render::RenderBufferBase::relaseRenderBuffer()
{
	GLFrameRender::deleteRenderBuffer(_renderBufferID);
	_renderBufferID = 0;
}

