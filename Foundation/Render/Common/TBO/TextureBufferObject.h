#pragma once

#include "Common/Buffer/BufferObject.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class Texture;
	class NoNamedBuffer;

	/**
	*	���������
	*/
	class TextureBufferObject : public sys::Object
	{
	public:
		TextureBufferObject();
		virtual ~TextureBufferObject();
	public:
		/**
		*	��������
		*/
		void setTexture(Texture* texture);
		/**
		*	��ȡ����
		*/
		Texture* getTexture() const;
		/**
		*	����������
		*/
		void setTextureBuffer(NoNamedBuffer* buffer);
		/**
		*	��ȡ������
		*/
		NoNamedBuffer* getTextureBuffer() const;
		/**
		*	�����������ʽ
		*/
		void setTexBufferFromat(TexSizedInternalFormat internalFormat);
	public:
		/**
		*	������
		*/
		void bindTexture();
		/**
		*	��������
		*/
		void unbindTexture();
		/**
		*	��������
		*/
		void bindTextureBuffer();
		/**
		*	����������
		*/
		void unbindTextureBuffer();
	protected:
		void initTBO();
		void releaseTBO();
	private:
		/**
		*	����
		*/
		Texture* _texture = nullptr;
		/**
		*	������
		*/
		NoNamedBuffer* _textureBuffer = nullptr;
	};
}
