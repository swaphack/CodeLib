#include "NamedBufferObject.h"
#include "Graphic/import.h"

using namespace render;

render::NamedBufferObject::NamedBufferObject()
{

}

render::NamedBufferObject::~NamedBufferObject()
{

}

void render::NamedBufferObject::setBufferData(int size, const void* data, BufferDataUsage usage)
{
	GLBufferObjects::setNamedBufferData(getBufferID(), size, data, usage);
}

void render::NamedBufferObject::setBufferStorage(GLsizeiptr size, const void* data, GLbitfield flags)
{
	GLBufferObjects::setNamedBufferStorage(getBufferID(), size, data, flags);
}

void render::NamedBufferObject::setBufferSubData(GLintptr offset, GLsizeiptr size, const void* data)
{
	GLBufferObjects::setNamedBufferSubData(getBufferID(), offset, size, data);
}

void render::NamedBufferObject::clearBufferData(BufferSizedInternalFormat internalformat, BufferImageInternalFormat format, BufferImageDataType type, const void* data)
{
	GLBufferObjects::clearNamedBufferData(getBufferID(), internalformat, format, type, data);
}

void render::NamedBufferObject::clearBufferSubData(BufferSizedInternalFormat internalformat, GLintptr offset, GLsizeiptr size, BufferImageInternalFormat format, BufferImageDataType type, const void* data)
{
	GLBufferObjects::clearNamedBufferSubData(getBufferID(), internalformat, offset, size, format, type, data);
}

void render::NamedBufferObject::copyBufferSubData(GLintptr readOffset, uint32_t writeBuffer, GLintptr writeOffset, GLintptr size)
{
	GLBufferObjects::copyNamedBufferSubData(getBufferID(), writeBuffer, readOffset, writeOffset, size);
}

void render::NamedBufferObject::getBufferParameter(GetBufferParameter pname, int* params)
{
	GLBufferObjects::getNamedBufferParameter(getBufferID(), pname, params);
}

void render::NamedBufferObject::getBufferParameter(GetBufferParameter pname, int64_t* params)
{
	GLBufferObjects::getNamedBufferParameter(getBufferID(), pname, params);
}
