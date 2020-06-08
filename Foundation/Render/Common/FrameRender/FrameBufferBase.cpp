#include "FrameBufferBase.h"
#include "Graphic/import.h"

render::FrameBufferBase::FrameBufferBase()
{
	this->initFrameBuffer();
}

render::FrameBufferBase::~FrameBufferBase()
{
	this->relaseFrameBuffer();
}

uint32_t render::FrameBufferBase::getFrameBufferID() const
{
	return _frameBufferID;
}

bool render::FrameBufferBase::isValid()
{
	return GLFrameRender::isFrameBuffer(_frameBufferID);
}

void render::FrameBufferBase::setFrameBufferTarget(FrameBufferTarget target)
{
	_frameBufferTarget = target;
}

FrameBufferTarget render::FrameBufferBase::getFrameBufferTarget() const
{
	return _frameBufferTarget;
}

void render::FrameBufferBase::bindFrameBuffer()
{
	GLFrameRender::bindFramebuffer(_frameBufferTarget, _frameBufferID);
}

void render::FrameBufferBase::bindFramebuffer(FrameBufferTarget target)
{
	GLFrameRender::bindFramebuffer(target, _frameBufferID);
}

void render::FrameBufferBase::unbindFrameBuffer()
{
	GLFrameRender::bindFramebuffer(_frameBufferTarget, 0);
}

void render::FrameBufferBase::setDrawBuffers(int n, const DrawBufferType* bufs)
{
	GLFrameRender::setDrawBuffers(n, bufs);
}

void render::FrameBufferBase::setDrawBuffer(DrawBufferType buf)
{
	GLFrameRender::setDrawBuffer(buf);
}

void render::FrameBufferBase::initFrameBuffer()
{
	_frameBufferID = GLFrameRender::createFrameBuffer();
}

void render::FrameBufferBase::relaseFrameBuffer()
{
	GLFrameRender::deleteFrameBuffer(_frameBufferID);
	_frameBufferID = 0;
}

