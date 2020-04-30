#pragma once

#include "BufferObjectBase.h"

namespace render
{
	/**
	*	缓存对象
	*/
	class BufferObject : public BufferObjectBase
	{
	public:
		BufferObject();
		virtual ~BufferObject();
	public:
		/**
		*	绑定数据
		*/
		void setBufferData(int size, const void* data, BufferDataUsage usage);
		/**
		*	设置存储
		*/
		void setBufferStorage(GLsizeiptr size, const void* data, GLbitfield flags);

		void setBufferSubData(GLintptr offset, GLsizeiptr size, const void* data);
		void clearBufferData(BufferSizedInternalFormat internalformat, BufferImageInternalFormat format, BufferImageDataType type, const void* data);
		void clearBufferSubData(BufferSizedInternalFormat internalformat, GLintptr offset, GLsizeiptr size, BufferImageInternalFormat format, BufferImageDataType type, const void* data);
		void copyBufferSubData(GLintptr readOffset, BufferTarget writeTarget, GLintptr writeOffset, GLintptr size);
	public:
		void getBufferParameter(GetBufferTarget target, GetBufferParameter pname, int* params);
		void getBufferParameter(GetBufferTarget target, GetBufferParameter pname, int64_t* params);
	};
}