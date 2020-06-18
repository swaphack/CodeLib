#pragma once

#include "NoNamedBuffer.h"

namespace render
{
	/**
	*	������ɫ�����ɷ�ָ�򻺴�
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