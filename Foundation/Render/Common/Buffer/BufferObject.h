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
		*	设置缓存对象
		*/
		void setBuffer(Buffer* buffer);
		/**
		*	获取缓存对象
		*/
		Buffer* getBuffer() const;
	private:
		/**
		*	缓存对象
		*/
		Buffer* _buffer = nullptr;
	};
}
