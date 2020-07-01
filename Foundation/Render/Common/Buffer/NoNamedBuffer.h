#pragma once

#include "Buffer.h"

namespace render
{
	/**
	*	缓存对象
	*/
	class NoNamedBuffer : public Buffer
	{
	public:
		NoNamedBuffer();
		virtual ~NoNamedBuffer();
	public:
		/**
		*	设置存储数据
		*/
		void setBufferStorage(ptrdiff_t size, const void* data, uint32_t flags);
		/**
		*	设置存储数据
		*/
		void setBufferStorage(ptrdiff_t size, const void* data, BufferStorageFlag flag);
	public:
		/**
		*	绑定数据
		*/
		void setBufferData(int size, BufferDataUsage usage);
		/**
		*	绑定数据
		*/
		void setBufferData(int size, const void* data, BufferDataUsage usage);
		/**
		*	设置部分存储数据
		*/
		void setBufferSubData(ptrdiff_t offset, ptrdiff_t size, const void* data);
		/**
		*	获取部分存储数据
		*/
		void getBufferSubData(ptrdiff_t offset, ptrdiff_t size, void* data);
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
		void copyBufferSubData(ptrdiff_t readOffset, BufferTarget writeTarget, ptrdiff_t writeOffset, ptrdiff_t size);
	public:
		/**
		*	获取参数
		*/
		void getBufferParameter(GetBufferTarget target, GetBufferParameter pname, int* params);
		/**
		*	获取参数
		*/
		void getBufferParameter(GetBufferTarget target, GetBufferParameter pname, int64_t* params);
		/**
		*	获取指定位置的数据指针
		*/
		void* getMapBuffer(AccessType type);
		/**
		*	获取指定位置的数据指针
		*/
		void* getMapBufferRange(ptrdiff_t offset, ptrdiff_t length, uint32_t access);
		/**
		*	获取指定位置的数据指针
		*/
		void* getMapBufferRange(ptrdiff_t offset, ptrdiff_t length, MapBufferRangeAccess access);
		/**
		*	取消关联buffer
		*/
		void unmapBuffer();

		/**
		*	通知指定位置的数据发生改变
		*/
		void flushMappedBufferRange(ptrdiff_t offset, ptrdiff_t length);
		/**
		*	读取数据
		*/
		void flush(ptrdiff_t offset, ptrdiff_t length, sys::StreamReader& reader);
	};
}