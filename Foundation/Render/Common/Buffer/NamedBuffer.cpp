#include "NamedBuffer.h"
#include "Graphic/import.h"

using namespace render;

render::NamedBuffer::NamedBuffer()
{

}

render::NamedBuffer::~NamedBuffer()
{

}

void render::NamedBuffer::setBufferData(int size, const void* data, BufferDataUsage usage)
{
	GLBufferObjects::setNamedBufferData(getBufferID(), size, data, usage);
}

void render::NamedBuffer::setBufferStorage(ptrdiff_t size, const void* data, uint32_t flags)
{
	GLBufferObjects::setNamedBufferStorage(getBufferID(), size, data, flags);
}

void render::NamedBuffer::setBufferStorage(ptrdiff_t size, const void* data, BufferStorageFlag flag)
{
	GLBufferObjects::setNamedBufferStorage(getBufferID(), size, data, flag);
}

void render::NamedBuffer::setBufferSubData(ptrdiff_t offset, ptrdiff_t size, const void* data)
{
	GLBufferObjects::setNamedBufferSubData(getBufferID(), offset, size, data);
}

void render::NamedBuffer::getBufferSubData(ptrdiff_t offset, ptrdiff_t size, void* data)
{
	GLBufferObjects::getNamedBufferSubData(getBufferID(), offset, size, data);
}

void render::NamedBuffer::clearBufferData(BufferSizedInternalFormat internalformat, BufferImageInternalFormat format, BufferImageDataType type, const void* data)
{
	GLBufferObjects::clearNamedBufferData(getBufferID(), internalformat, format, type, data);
}

void render::NamedBuffer::clearBufferSubData(BufferSizedInternalFormat internalformat, ptrdiff_t offset, ptrdiff_t size, BufferImageInternalFormat format, BufferImageDataType type, const void* data)
{
	GLBufferObjects::clearNamedBufferSubData(getBufferID(), internalformat, offset, size, format, type, data);
}

void render::NamedBuffer::copyBufferSubData(ptrdiff_t readOffset, uint32_t writeBuffer, ptrdiff_t writeOffset, ptrdiff_t size)
{
	GLBufferObjects::copyNamedBufferSubData(getBufferID(), writeBuffer, readOffset, writeOffset, size);
}

void render::NamedBuffer::getBufferParameter(GetBufferParameter pname, int* params)
{
	GLBufferObjects::getNamedBufferParameter(getBufferID(), pname, params);
}

void* render::NamedBuffer::getMapBuffer(AccessType access)
{
	return GLBufferObjects::getMapNamedBuffer(getBufferID(), access);
}

void* render::NamedBuffer::getMapBufferRange(ptrdiff_t offset, ptrdiff_t length, MapBufferRangeAccess access)
{
	return GLBufferObjects::getMapNamedBufferRange(getBufferID(), offset, length, access);
}

void* render::NamedBuffer::getMapBufferRange(ptrdiff_t offset, ptrdiff_t length, uint32_t access)
{
	return GLBufferObjects::getMapNamedBufferRange(getBufferID(), offset, length, access);
}

void render::NamedBuffer::getBufferParameter(GetBufferParameter pname, int64_t* params)
{
	GLBufferObjects::getNamedBufferParameter(getBufferID(), pname, params);
}

void render::NamedBuffer::unmapBuffer()
{
	GLBufferObjects::unmapNamedBuffer(getBufferID());
}

void render::NamedBuffer::flushMappedBufferRange(ptrdiff_t offset, ptrdiff_t length)
{
	GLBufferObjects::flushMappedNamedBufferRange(getBufferID(), offset, length);
}
