#pragma once

#include "NoNamedBuffer.h"

#include <cstdint>

namespace render
{
	class ElementArrayBuffer : public NoNamedBuffer
	{
	public:
		ElementArrayBuffer();
		virtual ~ElementArrayBuffer();
	public:
		void setElementData(const sys::MemoryData& data);
		void setElementData(uint32_t size, const char* data);
	};
}