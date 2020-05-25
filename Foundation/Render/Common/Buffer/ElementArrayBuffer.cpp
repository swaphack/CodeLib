#include "ElementArrayBuffer.h"

render::ElementArrayBuffer::ElementArrayBuffer()
{
	this->setBufferTarget(BufferTarget::ELEMENT_ARRAY_BUFFER);
}

render::ElementArrayBuffer::~ElementArrayBuffer()
{

}

void render::ElementArrayBuffer::setElementData(const sys::MemoryData& data)
{
	this->setElementData(data.getSize(), data.getValue());
}

void render::ElementArrayBuffer::setElementData(uint32_t size, const char* data)
{
	this->setBufferData(size, data, BufferDataUsage::STATIC_DRAW);
}

