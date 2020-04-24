#include "GLBufferObjects.h"

using namespace render;

void GLBufferObjects::bindBuffer(BufferTarget target, uint32_t buffer)
{
	glBindBuffer((GLenum)target, buffer);
}

void GLBufferObjects::bindBufferBase(BufferTarget target, uint32_t index, uint32_t buffer)
{
	glBindBufferBase((GLenum)target, index, buffer);
}

void GLBufferObjects::bindBufferRange(BufferTarget target, uint32_t index, uint32_t buffer, GLintptr offset, GLsizeiptr size)
{
	glBindBufferRange((GLenum)target, index, buffer, offset, size);
}

void GLBufferObjects::bindBuffersBase(BufferTarget target, uint32_t first, int count, const uint32_t* buffers)
{
	glBindBuffersBase((GLenum)target, first, count, buffers);
}

void GLBufferObjects::bindBuffersRange(BufferTarget target, uint32_t first, int count, const uint32_t* buffers, const GLintptr* offset, const GLsizeiptr* size)
{
	glBindBuffersRange((GLenum)target, first, count, buffers, offset, size);
}
