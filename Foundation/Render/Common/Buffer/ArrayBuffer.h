#pragma once

#include "NoNamedBuffer.h"

namespace render
{
	class ArrayBuffer : public NoNamedBuffer
	{
	public:
		ArrayBuffer();
		virtual ~ArrayBuffer();
	};
}