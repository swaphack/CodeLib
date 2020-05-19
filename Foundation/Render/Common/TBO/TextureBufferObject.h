#pragma once

#include "system.h"
#include "Graphic/GLAPI/macros.h"
namespace render
{
	class BufferObject;

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
		*	����������
		*/
		uint32_t getTBOID() const;
	public:
		/**
		*	��buffer
		*/
		void setBufferObject(BufferObject* buffer);
		/**
		*	��buffer
		*/
		BufferObject* getBufferObject();
	public:
		/**
		*	��
		*/
		void setFormat(TexSizedInternalFormat format);
		/**
		*	��
		*/
		void bindTextureUnit(int32_t index);
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
		*	���
		*/
		uint32_t _tboID = 0;
		/**
		*	��buffer
		*/
		BufferObject* _bufferObject = nullptr;
	};
}