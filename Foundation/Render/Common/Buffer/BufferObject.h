#pragma once

#include "BufferObjectBase.h"

namespace render
{
	/**
	*	�������
	*/
	class BufferObject : public BufferObjectBase
	{
	public:
		BufferObject();
		virtual ~BufferObject();
	public:
		/**
		*	������
		*/
		void setBufferData(int size, const void* data, BufferDataUsage usage);
		/**
		*	���ô洢
		*/
		void setBufferStorage(ptrdiff_t size, const void* data, uint32_t flags);

		void setBufferSubData(ptrdiff_t offset, ptrdiff_t size, const void* data);
		void clearBufferData(BufferSizedInternalFormat internalformat, BufferImageInternalFormat format, BufferImageDataType type, const void* data);
		void clearBufferSubData(BufferSizedInternalFormat internalformat, ptrdiff_t offset, ptrdiff_t size, BufferImageInternalFormat format, BufferImageDataType type, const void* data);
		void copyBufferSubData(ptrdiff_t readOffset, BufferTarget writeTarget, ptrdiff_t writeOffset, ptrdiff_t size);
	public:
		void getBufferParameter(GetBufferTarget target, GetBufferParameter pname, int* params);
		void getBufferParameter(GetBufferTarget target, GetBufferParameter pname, int64_t* params);
	public:
		void* setBufferRange(ptrdiff_t offset, ptrdiff_t length, uint32_t access);
		// ָ֪ͨ��λ�õĻ��淢���ı�
		void flushMappedBufferRange(ptrdiff_t offset, ptrdiff_t length);

		void unmapBuffer();
	};
}