#pragma once

#include "BufferObject.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class Buffer;

	/**
	*	���������
	*/
	class TextureBufferObject : public BufferObject
	{
	public:
		TextureBufferObject();
		virtual ~TextureBufferObject();
	public:
		/**
		*	������
		*/
		uint32_t getTextureID() const;
		/**
		*	��
		*/
		void bindBuffer();
	public:
		/**
		*	�����������ݸ�ʽ
		*/
		void setFormat(TexSizedInternalFormat format);
		/**
		*	��
		*/
		void bindTextureUnit(int32_t index);
		/**
		*	������
		*/
		void bindTexture(TextureTarget target);
	protected:
		/**
		*	����tbo
		*/
		void initTBO();
		/**
		*	�ͷ�tbo
		*/
		void relaseTBO();
	private:
		/**
		*	������
		*/
		uint32_t _textureID = 0;
	};
}