#pragma once

#include "system.h"

namespace render
{
	class Buffer;

	class BufferObject : public sys::Object
	{
	public:
		BufferObject();
		virtual ~BufferObject();
	public:
		/**
		*	���û������
		*/
		void setBuffer(Buffer* buffer);
		/**
		*	��ȡ�������
		*/
		Buffer* getBuffer() const;
	private:
		/**
		*	�������
		*/
		Buffer* _buffer = nullptr;
	};
}
