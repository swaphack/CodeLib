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

void render::NamedBufferObject::setBufferStorage(ptrdiff_t size, const void* data, uint32_t flags)
{
	GLBufferObjects::setNamedBufferStorage(getBufferID(), size, data, flags);
}

void render::NamedBufferObject::setBufferSubData(ptrdiff_t offset, ptrdiff_t size, const void* data)
{
	GLBufferObjects::setNamedBufferSubData(getBufferID(), offset, size, data);
}

void render::NamedBufferObject::clearBufferData(BufferSizedInternalFormat internalformat, BufferImageInternalFormat format, BufferImageDataType type, const void* data)
{
	GLBufferObjects::clearNamedBufferData(getBufferID(), internalformat, format, type, data);
}

void render::NamedBufferObject::clearBufferSubData(BufferSizedInternalFormat internalformat, ptrdiff_t offset, ptrdiff_t size, BufferImageInternalFormat format, BufferImageDataType type, const void* data)
{
	GLBufferObjects::clearNamedBufferSubData(getBufferID(), internalformat, offset, size, format, type, data);
}

void render::NamedBufferObject::copyBufferSubData(ptrdiff_t readOffset, uint32_t writeBuffer, ptrdiff_t writeOffset, ptrdiff_t size)
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

void render::NamedBufferObject::unmapBuffer()
{
	GLBufferObjects::unmapNamedBuffer(getBufferID());
}

void* render::NamedBufferObject::setBufferRange(ptrdiff_t offset, ptrdiff_t length, uint32_t type)
{
	return GLBufferObjects::setMapNamedBufferRange(getBufferID(), offset, length, type);
}

void render::NamedBufferObject::flushMappedBufferRange(ptrdiff_t offset, ptrdiff_t length)
{
	GLBufferObjects::flushMappedNamedBufferRange(getBufferID(), offset, length);
}
