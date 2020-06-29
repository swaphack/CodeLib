#include "ComputeShaderProgram.h"
#include "Graphic/import.h"
#include "Common/Buffer/DispatchIndirectBuffer.h"

render::ComputeShaderProgram::ComputeShaderProgram()
{

}

render::ComputeShaderProgram::~ComputeShaderProgram()
{

}

bool render::ComputeShaderProgram::loadComputeShader(const std::string& cpath)
{
	if (!this->loadShaderFromFile(ShaderType::COMPUTE_SHADER, cpath))
	{
		return false;
	}

	return true;
}

void render::ComputeShaderProgram::dispatchCompute(uint32_t groupXCount, uint32_t groupYCount, uint32_t groupZCount)
{
	GLUtility::dispatchCompute(groupXCount, groupYCount, groupZCount);
}

void render::ComputeShaderProgram::dispatchBuffer(const DispatchIndirectBuffer* buffer)
{
	if (buffer == nullptr)
	{
		return;
	}

	buffer->bindBuffer();
	GLUtility::dispatchComputeIndirect(0);
}


void render::ComputeShaderProgram::setMemoryBarrier(uint32_t barriers)
{
	GLUtility::setMemoryBarrier(barriers);
}

void render::ComputeShaderProgram::setMemoryBarrier(MemoryBarrierBit barrier)
{
	GLUtility::setMemoryBarrier(barrier);
}

void render::ComputeShaderProgram::getMaxWorkGroupSize(uint32_t& x, uint32_t& y, uint32_t& z)
{
	int32_t value[3] = { 0 };
	GLState::getInteger(GetTarget::MAX_COMPUTE_WORK_GROUP_SIZE, value);

	x = value[0];
	y = value[1];
	z = value[2];
}

void render::ComputeShaderProgram::getMaxSharedMemorySize(uint32_t& size)
{
	int value = 0;
	GLState::getInteger(GetTarget::MAX_COMPUTE_SHARED_MEMORY_SIZE, &value);
	size = value;
}

