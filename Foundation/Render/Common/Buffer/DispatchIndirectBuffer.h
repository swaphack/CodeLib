#pragma once

#include "NoNamedBuffer.h"

namespace render
{
	/**
	*	计算着色器中派发指向缓存
	*/
	class DispatchIndirectBuffer : public NoNamedBuffer
	{
	public:
		DispatchIndirectBuffer();
		virtual ~DispatchIndirectBuffer();
	public:
		void setDispatchData(uint32_t x, uint32_t y, uint32_t z);
		void setDispatchData(const uint32_t* data);
	protected:
	private:
	};
}