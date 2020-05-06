#include "BufferObject.h"
#include "Graphic/import.h"

using namespace render;

render::BufferObject::BufferObject()
{
	this->initBufferObject();
}

render::BufferObject::~BufferObject()
{
	this->relaseBufferObject();
}

uint32_t render::BufferObject::getBufferID() const
{
	return _bufferID;
}

void render::BufferObject::setBufferTarget(BufferTarget target)
{
	_target = target;
}

BufferTarget render::BufferObject::getBufferTarget() const
{
	return _target;
}

void render::BufferObject::bindBuffer()
{
	GLBufferObjects::bindBuffer(_target, _bufferID);
}

void render::BufferObject::setBufferBase(uint32_t index)
{
	GLBufferObjects::bindBufferBase(_target, index, _bufferID);
}

void* render::BufferObject::getMapBuffer(AccessType type)
{
	return GLBufferObjects::getMapBuffer(_target, type);
}

void render::BufferObject::setBufferRange(uint32_t index, int offset, int size)
{
	GLBufferObjects::bindBufferRange(_target, index, _bufferID, offset, size);
}

bool render::BufferObject::isBuffer()
{
	return GLBufferObjects::isBuffer(_bufferID);
}

void render::BufferObject::initBufferObject()
{
	_bufferID = GLBufferObjects::createBuffer();
}

void render::BufferObject::relaseBufferObject()
{
	GLBufferObjects::deleteBuffer(_bufferID);
	_bufferID = 0;
}

void render::BufferObject::invalidateBuffer()
{
	GLBufferObjects::invalidateBufferData(_bufferID);
}

void render::BufferObject::invalidateBufferSubData(ptrdiff_t offset, ptrdiff_t length)
{
	GLBufferObjects::invalidateBufferSubData(_bufferID, offset, length);
}
