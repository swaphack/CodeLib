#include "BufferObject.h"
#include "Common/Buffer/Buffer.h"

render::BufferObject::BufferObject()
{

}

render::BufferObject::~BufferObject()
{
	SAFE_RELEASE(_buffer);
}

void render::BufferObject::setBuffer(Buffer* buffer)
{
	SAFE_RELEASE(_buffer);
	SAFE_RETAIN(buffer);
	_buffer = buffer;
}

render::Buffer* render::BufferObject::getBuffer() const
{
	return _buffer;
}

