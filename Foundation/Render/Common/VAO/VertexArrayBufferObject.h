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
		void resizeBuffer(uint32_t size, BufferDataUsage usage = BufferDataUsage::STATIC_DRAW);
		/**
		*	��������
		*/
		void setSubBuffer(uint32_t offset, uint32_t size, const void* value);
		/**
		*	������������
		*/
		void setVertexAttribPointer(int index, uint32_t count, VertexAttribPointerType type, uint32_t stride, uint32_t offset);
		/**
		*	��
		*/
		void bindVertexArray();
		/**
		*	��
		*/
		void bindBuffer();
		/**
		*	���
		*/
		void unbindBuffer();
		/**
		*	���
		*/
		void unbindVertexArray();
		/**
		*	�����ֶ�
		*/
		void enableVertexArrayAttrib(uint32_t index);
		/**
		*	ʧЧ�ֶ�
		*/
		void disableVertexArrayAttrib(uint32_t index);
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
	};
}
