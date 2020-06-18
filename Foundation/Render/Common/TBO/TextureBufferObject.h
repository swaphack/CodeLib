#pragma once

#include "Common/Buffer/BufferObject.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class Texture;
	/**
	*	Œ∆¿Ìª∫¥Ê∂‘œÛ
	*/
	class TextureBufferObject : public BufferObject
	{
	public:
		TextureBufferObject();
		virtual ~TextureBufferObject();
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
