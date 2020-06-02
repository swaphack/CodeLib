#include "FrameBuffer.h"
#include "Graphic/import.h"

render::FrameBuffer::FrameBuffer()
{
	this->initFrameBuffer();
}

render::FrameBuffer::~FrameBuffer()
{
	this->relaseFrameBuffer();
}

uint32_t render::FrameBuffer::getFrameBufferID() const
{
	return _frameBufferID;
}

bool render::FrameBuffer::isValid()
{
	return GLFrameBuffer::isFrameBuffer(_frameBufferID);
}

void render::FrameBuffer::setFrameBufferTarget(FrameBufferTarget target)
{
	_frameBufferTarget = target;
}

FrameBufferTarget render::FrameBuffer::getFrameBufferTarget() const
{
	return _frameBufferTarget;
}

void render::FrameBuffer::bindTarget()
{
	GLFrameBuffer::bindFramebuffer(_frameBufferTarget, _frameBufferID);
}

void render::FrameBuffer::setDrawBuffers(int n, const DrawBufferType* bufs)
{
	GLFrameBuffer::setDrawBuffers(n, bufs);
}

void render::FrameBuffer::initFrameBuffer()
{
	_frameBufferID = GLFrameBuffer::createFrameBuffer();
}

void render::FrameBuffer::relaseFrameBuffer()
{
	GLFrameBuffer::deleteFrameBuffer(_frameBufferID);
	_frameBufferID = 0;
}

