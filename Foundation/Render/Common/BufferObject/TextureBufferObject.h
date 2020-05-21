#pragma once

#include "BufferObject.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class Buffer;
	class Texture;

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
		*	����
		*/
		void setTexture(Texture* texture);
		/**
		*	����
		*/
		Texture* getTexture() const;
		
		void bindTexture();
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
		*	��
		*/
		void bindBuffer();
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
		*	����
		*/
		Texture* _texture = nullptr;

	};
}