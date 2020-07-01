#include "NoNamedBuffer.h"
#include "Graphic/import.h"

using namespace render;

render::NoNamedBuffer::NoNamedBuffer()
{
}

render::NoNamedBuffer::~NoNamedBuffer()
{

}

void render::NoNamedBuffer::setBufferData(int size, const void* data, BufferDataUsage usage)
{
	GLBufferObjects::setBufferData(getBufferTarget(), size, data, usage);
}

void render::NoNamedBuffer::setBufferData(int size, BufferDataUsage usage)
{
	this->setBufferData(size, nullptr, usage);
}

void render::NoNamedBuffer::setBufferStorage(ptrdiff_t size, const void* data, uint32_t flags)
{
	GLBufferObjects::setBufferStorage(getBufferTarget(), size, data, flags);
}

void render::NoNamedBuffer::setBufferStorage(ptrdiff_t size, const void* data, BufferStorageFlag flag)
{
	GLBufferObjects::setBufferStorage(getBufferTarget(), size, data, flag);
}

void render::NoNamedBuffer::setBufferSubData(ptrdiff_t offset, ptrdiff_t size, const void* data)
{
	GLBufferObjects::setBufferSubData(getBufferTarget(), offset, size, data);
}

void render::NoNamedBuffer::getBufferSubData(ptrdiff_t offset, ptrdiff_t size, void* data)
{
	GLBufferObjects::getBufferSubData(getBufferTarget(), offset, size, data);
}

void render::NoNamedBuffer::clearBufferData(BufferSizedInternalFormat internalformat, BufferImageInternalFormat format, BufferImageDataType type, const void* data)
{
	GLBufferObjects::clearBufferData(getBufferTarget(), internalformat, format, type, data);
}

void render::NoNamedBuffer::clearBufferSubData(BufferSizedInternalFormat internalformat, ptrdiff_t offset, ptrdiff_t size, BufferImageInternalFormat format, BufferImageDataType type, const void* data)
{
	GLBufferObjects::clearBufferSubData(getBufferTarget(), internalformat, offset, size, format, type, data);
}

void render::NoNamedBuffer::copyBufferSubData(ptrdiff_t readOffset, BufferTarget writeTarget, ptrdiff_t writeOffset, ptrdiff_t size)
{
	GLBufferObjects::copyBufferSubData(getBufferTarget(), writeTarget, readOffset, writeOffset, size);
}

void render::NoNamedBuffer::getBufferParameter(GetBufferTarget target, GetBufferParameter pname, int* params)
{
	GLBufferObjects::getBufferParameter(target, pname, params);
}

void* render::NoNamedBuffer::getMapBuffer(AccessType type)
{
	return GLBufferObjects::getMapBuffer(getBufferTarget(), type);
}

void* render::NoNamedBuffer::getMapBufferRange(ptrdiff_t offset, ptrdiff_t length, MapBufferRangeAccess access)
{
	return GLBufferObjects::getMapBufferRange(getBufferTarget(), offset, length, access);
}

void* render::NoNamedBuffer::getMapBufferRange(ptrdiff_t offset, ptrdiff_t length, uint32_t access)
{
	return GLBufferObjects::getMapBufferRange(getBufferTarget(), offset, length, access);
}

void render::NoNamedBuffer::getBufferParameter(GetBufferTarget target, GetBufferParameter pname, int64_t* params)
{
	GLBufferObjects::getBufferParameter(target, pname, params);
}

void render::NoNamedBuffer::unmapBuffer()
{
	GLBufferObjects::unmapBuffer(getBufferTarget());
}

void render::NoNamedBuffer::flushMappedBufferRange(ptrdiff_t offset, ptrdiff_t length)
{
	GLBufferObjects::flushMappedBufferRange(getBufferTarget(), offset, length);
}

void render::NoNamedBuffer::flush(ptrdiff_t offset, ptrdiff_t length, sys::StreamReader& reader)
{
	this->bindBuffer();

	void* data = this->getMapBufferRange(offset, length, MapBufferRangeAccess::MAP_READ_BIT);
	GLDebug::showError();

	void* cpyData = malloc(length);
	memcpy(cpyData, data, length);

	reader.setData(cpyData, length);
	this->unmapBuffer();

	this->unbindBuffer();
}

