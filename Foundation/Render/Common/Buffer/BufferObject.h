#pragma once

#include "Graphic/GLAPI/macros.h"
#include "system.h"
#include <cstdint>

namespace render
{
	/**
	*	����������
	*/
	class BufferObject : public sys::Object
	{
	public:
		BufferObject();
		virtual ~BufferObject();
	public:
		/**
		*	������
		*/
		uint32_t getBufferID() const;
		/**
		*	��������
		*/
		void setBufferTarget(BufferTarget target);
		/**
		*	��ȡ����
		*/
		BufferTarget getBufferTarget() const;
		/**
		*	������
		*/
		void bindBuffer();
		/**
		*	�Ƿ���Ч
		*/
		bool isBuffer();
	public:
		/**
		*	������������
		*/
		void setBufferBase(uint32_t index);
		/**
		*	�������ݷ�Χ
		*/
		void setBufferRange(uint32_t index, int offset, int size);
		/**
		*	��ȡ��������
		*/
		void* getMapBuffer(AccessType type);
		/**
		*	����
		*/
		void invalidateBuffer();
		/**
		*	����
		*/
		void invalidateBufferSubData(ptrdiff_t offset, ptrdiff_t length);
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
		/**
		*	������
		*/
		uint32_t _bufferID = 0;
		/**
		*	��������
		*/
		BufferTarget _target;
	};
}