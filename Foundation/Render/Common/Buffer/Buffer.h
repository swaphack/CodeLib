#pragma once

#include "Graphic/GLAPI/macros.h"
#include "system.h"
#include <cstdint>

namespace render
{
	/**
	*	����������
	*/
	class Buffer : public sys::Object
	{
	public:
		Buffer();
		virtual ~Buffer();
	public:
		/**
		*	������
		*/
		uint32_t getBufferID() const;
	public:
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
		void bindBuffer(uint32_t bufferID) const;;
		/**
		*	������
		*/
		void bindBuffer() const;
		/**
		*	������
		*/
		void unbindBuffer() const;
		/**
		*	�Ƿ���Ч
		*/
		bool isBuffer() const;
	public:
		void bindBufferBase(BufferTarget target, uint32_t index);
		/**
		*	������������
		*/
		void bindBufferBase(uint32_t index);
		/**
		*	�������ݷ�Χ
		*/
		void getBufferRange(uint32_t index, ptrdiff_t offset, ptrdiff_t size);
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