#pragma once

#include "NoNamedBufferObject.h"

#include <cstdint>

namespace render
{
	class ElementArrayBufferObject : public NoNamedBufferObject
	{
	public:
		ElementArrayBufferObject();
		virtual ~ElementArrayBufferObject();
	public:
		void setElementData(const sys::MemoryData& data);
		void setElementData(uint32_t size, const char* data);
	};
}