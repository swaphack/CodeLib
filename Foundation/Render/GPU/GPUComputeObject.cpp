#include "GPUComputeObject.h"
#include "Common/Shader/ShaderManager.h"
#include "Common/Shader/ComputeShaderProgram.h"

render::GPUComputeObject::GPUComputeObject()
{

}

render::GPUComputeObject::~GPUComputeObject()
{
	SAFE_RELEASE(_computeProgram);
}

void render::GPUComputeObject::loadComputeProgram(const std::string& computeFilepath)
{
	SAFE_RELEASE(_computeProgram);
	_computeProgram = G_SHANDER->createComputeProgram(computeFilepath);
	SAFE_RETAIN(_computeProgram);
}

void render::GPUComputeObject::setGroupSize(uint32_t groupXCount, uint32_t groupYCount /*= 1*/, uint32_t groupZCount /*= 1*/)
{
	_groupSize.x = groupXCount;
	_groupSize.y = groupYCount;
	_groupSize.z = groupZCount;
}

uint32_t render::GPUComputeObject::getGroupXCount() const
{
	return _groupSize.x;
}

uint32_t render::GPUComputeObject::getGroupYCount() const
{
	return _groupSize.y;
}

uint32_t render::GPUComputeObject::getGroupZCount() const
{
	return _groupSize.z;
}

void render::GPUComputeObject::setMemoryBarrier(MemoryBarrierBit bit)
{
	_memoryBarrierBit = bit;
}

MemoryBarrierBit render::GPUComputeObject::getMemoryBarrier() const
{
	return _memoryBarrierBit;
}

void render::GPUComputeObject::setShaderProgramFunc(const ShaderProgramFunc& func)
{
	_shaderProgramFunc = func;
}

render::ShaderProgramFunc render::GPUComputeObject::getShaderProgramFunc() const
{
	return _shaderProgramFunc;
}

bool render::GPUComputeObject::run()
{
	if (_computeProgram == nullptr)
	{
		return false;
	}

	_computeProgram->use();

	if (_shaderProgramFunc)
	{
		_shaderProgramFunc(_computeProgram);
	}

	_computeProgram->dispatchCompute(_groupSize.x, _groupSize.y, _groupSize.z);

	_computeProgram->setMemoryBarrier(_memoryBarrierBit);

	_computeProgram->unuse();

	return true;
}

