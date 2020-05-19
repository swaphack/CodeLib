#include "ElementArrayBufferObject.h"

render::ElementArrayBufferObject::ElementArrayBufferObject()
{
	this->setBufferTarget(BufferTarget::ELEMENT_ARRAY_BUFFER);
}

render::ElementArrayBufferObject::~ElementArrayBufferObject()
{

}

void render::ElementArrayBufferObject::setElementData(const sys::MemoryData& data)
{
	this->setElementData(data.getSize(), data.getValue());
}

void render::ElementArrayBufferObject::setElementData(uint32_t size, const char* data)
{
	this->bindBuffer();
	this->setBufferData(size, data, BufferDataUsage::STATIC_DRAW);
}

