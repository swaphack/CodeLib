#include "NoNamedBufferObject.h"
#include "Graphic/import.h"

using namespace render;

render::NoNamedBufferObject::NoNamedBufferObject()
{
}

render::NoNamedBufferObject::~NoNamedBufferObject()
{

}

void render::NoNamedBufferObject::setBufferData(int size, const void* data, BufferDataUsage usage)
{
	GLBufferObjects::setBufferData(getBufferTarget(), size, data, usage);
}

void render::NoNamedBufferObject::setBufferStorage(ptrdiff_t size, const void* data, uint32_t flags)
{
	GLBufferObjects::setBufferStorage(getBufferTarget(), size, data, flags);
}

void render::NoNamedBufferObject::setBufferSubData(ptrdiff_t offset, ptrdiff_t size, const void* data)
{
	GLBufferObjects::setBufferSubData(getBufferTarget(), offset, size, data);
}

void render::NoNamedBufferObject::clearBufferData(BufferSizedInternalFormat internalformat, BufferImageInternalFormat format, BufferImageDataType type, const void* data)
{
	GLBufferObjects::clearBufferData(getBufferTarget(), internalformat, format, type, data);
}

void render::NoNamedBufferObject::clearBufferSubData(BufferSizedInternalFormat internalformat, ptrdiff_t offset, ptrdiff_t size, BufferImageInternalFormat format, BufferImageDataType type, const void* data)
{
	GLBufferObjects::clearBufferSubData(getBufferTarget(), internalformat, offset, size, format, type, data);
}

void render::NoNamedBufferObject::copyBufferSubData(ptrdiff_t readOffset, BufferTarget writeTarget, ptrdiff_t writeOffset, ptrdiff_t size)
{
	GLBufferObjects::copyBufferSubData(getBufferTarget(), writeTarget, readOffset, writeOffset, size);
}

void render::NoNamedBufferObject::getBufferParameter(GetBufferTarget target, GetBufferParameter pname, int* params)
{
	GLBufferObjects::getBufferParameter(target, pname, params);
}

void render::NoNamedBufferObject::getBufferParameter(GetBufferTarget target, GetBufferParameter pname, int64_t* params)
{
	GLBufferObjects::getBufferParameter(target, pname, params);
}

void render::NoNamedBufferObject::unmapBuffer()
{
	GLBufferObjects::unmapBuffer(getBufferTarget());
}

void* render::NoNamedBufferObject::setBufferRange(ptrdiff_t offset, ptrdiff_t length, uint32_t type)
{
	return GLBufferObjects::setMapBufferRange(getBufferTarget(), offset, length, type);
}

void render::NoNamedBufferObject::flushMappedBufferRange(ptrdiff_t offset, ptrdiff_t length)
{
	GLBufferObjects::flushMappedBufferRange(getBufferTarget(), offset, length);
}


