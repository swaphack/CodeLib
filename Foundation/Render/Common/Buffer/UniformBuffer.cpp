#include "UniformBuffer.h"
#include "../Shader/ShaderUniformBlock.h"

render::UniformBuffer::UniformBuffer()
{
	this->setBufferTarget(BufferTarget::UNIFORM_BUFFER);
}

render::UniformBuffer::~UniformBuffer()
{
}

void render::UniformBuffer::setUniformBlockData(const ShaderUniformBlockData* data)
{
	this->bindBuffer();
	this->setBufferData(data->getBlockData().getSize(), data->getBlockData().getValue(), BufferDataUsage::STATIC_DRAW);
	this->bindBufferBase(data->getUniformBlock()->getUniformBlockID());
}
