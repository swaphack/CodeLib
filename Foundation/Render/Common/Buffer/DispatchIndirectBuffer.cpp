#include "DispatchIndirectBuffer.h"

render::DispatchIndirectBuffer::DispatchIndirectBuffer()
{
	this->setBufferTarget(BufferTarget::DISPATCH_INDIRECT_BUFFER);
}

render::DispatchIndirectBuffer::~DispatchIndirectBuffer()
{

}

void render::DispatchIndirectBuffer::setDispatchData(uint32_t x, uint32_t y, uint32_t z)
{
	uint32_t data[3] = { x, y, z };
	this->setDispatchData(data);
}

void render::DispatchIndirectBuffer::setDispatchData(const uint32_t* data)
{
	this->setBufferData(sizeof(data), data, BufferDataUsage::STATIC_DRAW);
}

