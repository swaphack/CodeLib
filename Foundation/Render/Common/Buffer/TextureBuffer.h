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
	public:
		void setTexture(Texture* texture);
		Texture* getTexture() const;
	public:
		void bindTexture();
		void setTexBuffer(TexSizedInternalFormat internalFormat);
	private:
		Texture* _texture = nullptr;
	};
}
