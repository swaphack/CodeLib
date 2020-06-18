#pragma once

#include "NoNamedBuffer.h"

namespace render
{
	class Texture;

	class TextureBuffer : public NoNamedBuffer
	{
	public:
		TextureBuffer();
		virtual ~TextureBuffer();
	};
}
