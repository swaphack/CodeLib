#include "BufferObjectBase.h"
#include "Graphic/import.h"

using namespace render;

render::BufferObjectBase::BufferObjectBase()
{
	this->initBufferObject();
}

render::BufferObjectBase::~BufferObjectBase()
{
	this->relaseBufferObject();
}

uint32_t render::BufferObjectBase::getBufferID() const
{
	return _bufferID;
}

void render::BufferObjectBase::setBufferTarget(BufferTarget target)
{
	_target = target;
	GLBufferObjects::bindBuffer(_target, _bufferID);
}

BufferTarget render::BufferObjectBase::getBufferTarget() const
{
	return _target;
}

void render::BufferObjectBase::setBufferBase(int index)
{
	GLBufferObjects::bindBufferBase(_target, index, _bufferID);
}

void render::BufferObjectBase::setBufferRange(int index, int offset, int size)
{
	GLBufferObjects::bindBufferRange(_target, index, _bufferID, offset, size);
}

void render::BufferObjectBase::initBufferObject()
{
	_bufferID = GLBufferObjects::createBuffer();
}

void render::BufferObjectBase::relaseBufferObject()
{
	GLBufferObjects::deleteBuffer(_bufferID);
	_bufferID = 0;
}