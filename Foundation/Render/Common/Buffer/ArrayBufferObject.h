#pragma once

#include "NoNamedBufferObject.h"

namespace render
{
	class ArrayBufferObject : public NoNamedBufferObject
	{
	public:
		ArrayBufferObject();
		virtual ~ArrayBufferObject();
	};
}