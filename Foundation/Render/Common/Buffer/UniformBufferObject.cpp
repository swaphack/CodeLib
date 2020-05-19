#include "UniformBufferObject.h"
#include "../Shader/ShaderUniformBlock.h"

render::UniformBufferObject::UniformBufferObject()
{
	this->setBufferTarget(BufferTarget::UNIFORM_BUFFER);
}

render::UniformBufferObject::~UniformBufferObject()
{
}

void render::UniformBufferObject::setUniformBlockData(const ShaderUniformBlockData* data)
{
	this->bindBuffer();
	this->setBufferData(data->getBlockData().getSize(), data->getBlockData().getValue(), BufferDataUsage::STATIC_DRAW);
	this->setBufferBase(data->getUniformBlock()->getUniformBlockID());
}
