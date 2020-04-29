#pragma once

#include "Graphic/GLAPI/macros.h"
#include "system.h"
#include <cstdint>

namespace render
{
	class BufferObject : public sys::Object
	{
	public:
		BufferObject();
		virtual ~BufferObject();
	public:
		/**
		*	��������
		*/
		void setBufferTarget(BufferTarget target);
		/**
		*	������
		*/
		void setBufferData(int size, const void* data, BufferDataUsage usage);
		/**
		*	������������
		*/
		void setBufferBase(int index);
		/**
		*	�������ݷ�Χ
		*/
		void setBufferRange(int index, int offset, int size);
	protected:
		/**
		*	��ʼ��
		*/
		void initBufferObject();
		/**
		*	�ͷ�
		*/
		void relaseBufferObject();
	private:
		uint32_t _bufferID = 0;
		BufferTarget _target;
	};
}