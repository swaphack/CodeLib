#pragma once

#include "BufferObjectBase.h"

namespace render
{
	/**
	*	�����������
	*/
	class NamedBufferObject : public BufferObjectBase
	{
	public:
		NamedBufferObject();
		virtual ~NamedBufferObject();
	public:
		/**
		*	������
		*/
		void setBufferData(int size, const void* data, BufferDataUsage usage);
		/**
		*	���ô洢
		*/
		void setBufferStorage(GLsizeiptr size, const void* data, GLbitfield flags);
		/**
		*	���ò��ֻ��棬�����ȵ���setBufferStorage�� flags ����GL_CLIENT_STORAGE_BIT
		*/
		void setBufferSubData(GLintptr offset, GLsizeiptr size, const void* data);

		void clearBufferData(BufferSizedInternalFormat internalformat, BufferImageInternalFormat format, BufferImageDataType type, const void* data);
		void clearBufferSubData(BufferSizedInternalFormat internalformat, GLintptr offset, GLsizeiptr size, BufferImageInternalFormat format, BufferImageDataType type, const void* data);
		void copyBufferSubData(GLintptr readOffset, uint32_t writeBuffer, GLintptr writeOffset, GLintptr size);
	public:
		void getBufferParameter(GetBufferParameter pname, int* params);
		void getBufferParameter(GetBufferParameter pname, int64_t* params);
	};
}