#pragma once

#include "Buffer.h"

namespace render
{
	/**
	*	命名缓存对象
	*/
	class NamedBuffer : public Buffer
	{
	public:
		NamedBuffer();
		virtual ~NamedBuffer();
	public:
		/**
		*	设置存储
		*/
		void setBufferStorage(ptrdiff_t size, const void* data, uint32_t flags);
	public:
		/**
		*	绑定数据
		*/
		void setBufferData(int size, const void* data, BufferDataUsage usage);
		/**
		*	设置部分缓存，必须先调用setBufferStorage， flags 包含GL_CLIENT_STORAGE_BIT
		*/
		void setBufferSubData(ptrdiff_t offset, ptrdiff_t size, const void* data);
		/**
		*	用给定的格式数据，清除存储数据
		*/
		void clearBufferData(BufferSizedInternalFormat internalformat, BufferImageInternalFormat format, BufferImageDataType type, const void* data);
		/**
		*	用给定的格式数据，清除部分存储数据
		*/
		void clearBufferSubData(BufferSizedInternalFormat internalformat, ptrdiff_t offset, ptrdiff_t size, BufferImageInternalFormat format, BufferImageDataType type, const void* data);
		/**
		*	复制部分存储数据
		*/
		void copyBufferSubData(ptrdiff_t readOffset, uint32_t writeBuffer, ptrdiff_t writeOffset, ptrdiff_t size);
	public:
		/**
		*	获取参数
		*/
		void getBufferParameter(GetBufferParameter pname, int* params);
		/**
		*	获取参数
		*/
		void getBufferParameter(GetBufferParameter pname, int64_t* params);
		/**
		*	获取指定位置的数据指针
		*/
		void* setBufferRange(ptrdiff_t offset, ptrdiff_t length, uint32_t access);
		/**
		*	通知指定位置的数据发生改变
		*/
		void flushMappedBufferRange(ptrdiff_t offset, ptrdiff_t length);
		/**
		*	取消关联buffer
		*/
		void unmapBuffer();
	};
}