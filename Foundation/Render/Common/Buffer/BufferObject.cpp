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

void render::BufferObject::setBufferTarget(BufferTarget target)
{
	_target = target;
	GLBufferObjects::bindBuffer(_target, _bufferID);
}

void render::BufferObject::setBufferData(int size, const void* data, BufferDataUsage usage)
{
	GLBufferObjects::setBufferData(_target, size, data, usage);
}

void render::BufferObject::setBufferBase(int index)
{
	GLBufferObjects::bindBufferBase(_target, index, _bufferID);
}

void render::BufferObject::setBufferRange(int index, int offset, int size)
{
	GLBufferObjects::bindBufferRange(_target, index, _bufferID, offset, size);
}

void render::BufferObject::initBufferObject()
{
	_bufferID = GLBufferObjects::genBuffer();
}

void render::BufferObject::relaseBufferObject()
{
	GLBufferObjects::deleteBuffer(_bufferID);
	_bufferID = 0;
}
