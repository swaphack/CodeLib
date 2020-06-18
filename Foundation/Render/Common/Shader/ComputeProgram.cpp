#include "ComputeProgram.h"
#include "Graphic/import.h"
#include "Common/Buffer/DispatchIndirectBuffer.h"

render::ComputeProgram::ComputeProgram()
{

}

render::ComputeProgram::~ComputeProgram()
{

}

bool render::ComputeProgram::loadComputeShader(const std::string& cpath)
{
	if (!this->loadShaderFromFile(ShaderType::COMPUTE_SHADER, cpath))
	{
		return false;
	}

	return true;
}

void render::ComputeProgram::dispatchCompute(uint32_t groupXCount, uint32_t groupYCount, uint32_t groupZCount)
{
	GLUtility::dispatchCompute(groupXCount, groupYCount, groupZCount);
}

void render::ComputeProgram::dispatchBuffer(const DispatchIndirectBuffer* buffer)
{
	if (buffer == nullptr)
	{
		return;
	}

	buffer->bindBuffer();
	GLUtility::dispatchComputeIndirect(0);
}


void render::ComputeProgram::setMemoryBarrier(uint32_t barriers)
{
	GLUtility::setMemoryBarrier(barriers);
}

void render::ComputeProgram::setMemoryBarrier(MemoryBarrierBit barrier)
{
	GLUtility::setMemoryBarrier(barrier);
}

void render::ComputeProgram::getMaxWorkGroupSize(uint32_t& x, uint32_t& y, uint32_t& z)
{
	int32_t value[3] = { 0 };
	GLState::getInteger(GetTarget::MAX_COMPUTE_WORK_GROUP_SIZE, value);

	x = value[0];
	y = value[1];
	z = value[2];
}

void render::ComputeProgram::getMaxSharedMemorySize(uint32_t& size)
{
	int value = 0;
	GLState::getInteger(GetTarget::MAX_COMPUTE_SHARED_MEMORY_SIZE, &value);
	size = value;
}

