#include "VertexAttribPointer.h"
#include "Graphic/import.h"
#include "VertexArrayObject.h"
using namespace render;

VertexAttribPointer::VertexAttribPointer(uint32_t index, VertexArrayObject* obj)
	:VertexArrayAttrib(index, obj)
{

}

VertexAttribPointer::~VertexAttribPointer()
{

}

void render::VertexAttribPointer::setVertexAttribLPointer(int size, VertexAttribLPointerType type, int stride, const void* pointer)
{
	GLBufferObjects::setVertexAttribLPointer(getIndex(), size, type, stride, pointer);
}

void render::VertexAttribPointer::setVertexAttribIPointer(int size, VertexAttribIPointerType type, int stride, const void* pointer)
{
	GLBufferObjects::setVertexAttribIPointer(getIndex(), size, type, stride, pointer);
}

void render::VertexAttribPointer::setVertexAttribPointer(int size, VertexAttribPointerType type, bool normalized, int stride, const void* pointer)
{
	GLBufferObjects::setVertexAttribPointer(getIndex(), size, type, normalized, stride, pointer);
}

void render::VertexAttribPointer::setVertexAttribPointer(int size, VertexAttribPointerType type, uint32_t offset)
{
	this->setVertexAttribPointer(size, type, 0, offset);
}

void render::VertexAttribPointer::setVertexAttribPointer(int size, VertexAttribPointerType type, int stride, uint32_t offset)
{
	this->setVertexAttribPointer(size, type, false, stride, offset);
}

void render::VertexAttribPointer::setVertexAttribPointer(int size, VertexAttribPointerType type, bool normalized, int stride, uint32_t offset)
{
	this->setVertexAttribPointer(size, type, normalized, stride, (const void*)offset);
}