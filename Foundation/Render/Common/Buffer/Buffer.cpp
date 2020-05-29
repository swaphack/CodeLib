#include "Buffer.h"
#include "Graphic/import.h"

using namespace render;

render::Buffer::Buffer()
{
	this->initBufferObject();
}

render::Buffer::~Buffer()
{
	this->relaseBufferObject();
}

uint32_t render::Buffer::getBufferID() const
{
	return _bufferID;
}

void render::Buffer::setBufferTarget(BufferTarget target)
{
	_target = target;
}

BufferTarget render::Buffer::getBufferTarget() const
{
	return _target;
}

void render::Buffer::bindBuffer()
{
	GLBufferObjects::bindBuffer(_target, _bufferID);
}

void render::Buffer::bindBuffer(uint32_t bufferID)
{
	GLBufferObjects::bindBuffer(_target, bufferID);
}

void render::Buffer::unbindBuffer()
{
	GLBufferObjects::bindBuffer(_target, 0);
}

void render::Buffer::bindBufferBase(uint32_t index)
{
	GLBufferObjects::bindBufferBase(_target, index, _bufferID);
}

void render::Buffer::bindBufferBase(BufferTarget target, uint32_t index)
{
	GLBufferObjects::bindBufferBase(target, index, _bufferID);
}

void* render::Buffer::getMapBuffer(AccessType type)
{
	return GLBufferObjects::getMapBuffer(_target, type);
}

void render::Buffer::getBufferRange(uint32_t index, ptrdiff_t offset, ptrdiff_t size)
{
	GLBufferObjects::bindBufferRange(_target, index, _bufferID, offset, size);
}

bool render::Buffer::isBuffer()
{
	return GLBufferObjects::isBuffer(_bufferID);
}

void render::Buffer::initBufferObject()
{
	_bufferID = GLBufferObjects::createBuffer();
}

void render::Buffer::relaseBufferObject()
{
	GLBufferObjects::deleteBuffer(_bufferID);
	_bufferID = 0;
}

void render::Buffer::invalidateBuffer()
{
	GLBufferObjects::invalidateBufferData(_bufferID);
}

void render::Buffer::invalidateBufferSubData(ptrdiff_t offset, ptrdiff_t length)
{
	GLBufferObjects::invalidateBufferSubData(_bufferID, offset, length);
}
