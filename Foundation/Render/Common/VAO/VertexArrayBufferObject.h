#pragma once

#include "system.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class VertexArrayObject;
	class ArrayBuffer;

	/**
	*	�������黺�����
	*/
	class VertexArrayBufferObject : public sys::Object
	{
	public:
		VertexArrayBufferObject();
		virtual ~VertexArrayBufferObject();
	public:
		/**
		*	���ô�С
		*/
		void resize(uint32_t size, BufferDataUsage usage = BufferDataUsage::STATIC_DRAW);
		/**
		*	д������
		*/
		void writeVertexAttrib(VertexAttribPointerType type, const void* value, uint32_t count = 1, uint32_t stride = 0);
		/**
		*	��
		*/
		void bindVertexArray();
		/**
		*	���
		*/
		void unbindVertexArray();
		/**
		*	�����ֶ�
		*/
		void enableVertexArrayAttrib(uint32_t index);
	protected:
		/**
		*	��ʼ��
		*/
		void initVABO();
		/**
		*	�ͷ�
		*/
		void releaseVABO();
	private:
		/**
		*	��ȡ���ʹ�С
		*/
		uint32_t getTypeSize(VertexAttribPointerType type);
	private:
		/**
		*	�����������
		*/
		VertexArrayObject* _vao = nullptr;
		/**
		*	���黺��
		*/
		ArrayBuffer* _buffer = nullptr;
		/**
		*	�α�
		*/
		uint32_t _cursor = 0;
		/**
		*	����
		*/
		uint32_t _index = 0;
	};
}
