#include "BufferObject.h"
#include "Graphic/import.h"

using namespace render;

render::BufferObject::BufferObject()
{
}

render::BufferObject::~BufferObject()
{

}

void render::BufferObject::setBufferData(int size, const void* data, BufferDataUsage usage)
{
	GLBufferObjects::setBufferData(getBufferTarget(), size, data, usage);
}

void render::BufferObject::setBufferStorage(GLsizeiptr size, const void* data, GLbitfield flags)
{
	GLBufferObjects::setBufferStorage(getBufferTarget(), size, data, flags);
}

void render::BufferObject::setBufferSubData(GLintptr offset, GLsizeiptr size, const void* data)
{
	GLBufferObjects::setBufferSubData(getBufferTarget(), offset, size, data);
}

void render::BufferObject::clearBufferData(BufferSizedInternalFormat internalformat, BufferImageInternalFormat format, BufferImageDataType type, const void* data)
{
	GLBufferObjects::clearBufferData(getBufferTarget(), internalformat, format, type, data);
}

void render::BufferObject::clearBufferSubData(BufferSizedInternalFormat internalformat, GLintptr offset, GLsizeiptr size, BufferImageInternalFormat format, BufferImageDataType type, const void* data)
{
	GLBufferObjects::clearBufferSubData(getBufferTarget(), internalformat, offset, size, format, type, data);
}

void render::BufferObject::copyBufferSubData(GLintptr readOffset, BufferTarget writeTarget, GLintptr writeOffset, GLintptr size)
{
	GLBufferObjects::copyBufferSubData(getBufferTarget(), writeTarget, readOffset, writeOffset, size);
}

void render::BufferObject::getBufferParameter(GetBufferTarget target, GetBufferParameter pname, int* params)
{
	GLBufferObjects::getBufferParameter(target, pname, params);
}

void render::BufferObject::getBufferParameter(GetBufferTarget target, GetBufferParameter pname, int64_t* params)
{
	GLBufferObjects::getBufferParameter(target, pname, params);
}


