#pragma once

#include "NoNamedBuffer.h"

namespace render
{
	class TextureBuffer : public NoNamedBuffer
	{
	public:
		TextureBuffer();
		virtual ~TextureBuffer();
	};
}
