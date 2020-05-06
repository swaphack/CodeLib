#include "NoNamedBufferObjects.h"
#include "../Shader/ShaderUniformBlock.h"
using namespace render;

render::NoNamedArrayBuffer::NoNamedArrayBuffer()
{
	this->setBufferTarget(BufferTarget::ARRAY_BUFFER);
}

render::NoNamedArrayBuffer::~NoNamedArrayBuffer()
{

}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
render::NoNamedElemenetArrayBuffer::NoNamedElemenetArrayBuffer()
{
	this->setBufferTarget(BufferTarget::ELEMENT_ARRAY_BUFFER);
}

render::NoNamedElemenetArrayBuffer::~NoNamedElemenetArrayBuffer()
{

}

void render::NoNamedElemenetArrayBuffer::setIndicesData(uint32_t size, const uint32_t* data)
{
	this->bindBuffer();
	this->setBufferData(size, data, BufferDataUsage::STREAM_DRAW);
}


//////////////////////////////////////////////////////////////////////////
render::NoNamedUniformBuffer::NoNamedUniformBuffer()
{
	this->setBufferTarget(BufferTarget::UNIFORM_BUFFER);
}

render::NoNamedUniformBuffer::~NoNamedUniformBuffer()
{

}

void render::NoNamedUniformBuffer::setUniformBlockData(const ShaderUniformBlockData* data)
{
	this->bindBuffer();
	this->setBufferData(data->getBlockData().getSize(), data->getBlockData().getValue(), BufferDataUsage::STATIC_DRAW);
	this->setBufferBase(data->getUniformBlock()->getUniformBlockID());
}