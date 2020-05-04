#pragma once

#include "Graphic/GLAPI/macros.h"
#include "system.h"
#include <cstdint>

namespace render
{
	/**
	*	����������
	*/
	class BufferObjectBase : public sys::Object
	{
	public:
		BufferObjectBase();
		virtual ~BufferObjectBase();
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
		*	��������
		*/
		BufferTarget getBufferTarget() const;
	public:
		/**
		*	������������
		*/
		void setBufferBase(int index);
		/**
		*	�������ݷ�Χ
		*/
		void setBufferRange(int index, int offset, int size);
		/**
		*	��ȡ��������
		*/
		void* getMapBuffer(AccessType type);
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