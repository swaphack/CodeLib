#pragma once

#include "Buffer.h"

namespace render
{
	/**
	*	�����������
	*/
	class NamedBuffer : public Buffer
	{
	public:
		NamedBuffer();
		virtual ~NamedBuffer();
	public:
		/**
		*	���ô洢
		*/
		void setBufferStorage(ptrdiff_t size, const void* data, uint32_t flags);
	public:
		/**
		*	������
		*/
		void setBufferData(int size, const void* data, BufferDataUsage usage);
		/**
		*	���ò��ֻ��棬�����ȵ���setBufferStorage�� flags ����GL_CLIENT_STORAGE_BIT
		*/
		void setBufferSubData(ptrdiff_t offset, ptrdiff_t size, const void* data);
		/**
		*	�ø����ĸ�ʽ���ݣ�����洢����
		*/
		void clearBufferData(BufferSizedInternalFormat internalformat, BufferImageInternalFormat format, BufferImageDataType type, const void* data);
		/**
		*	�ø����ĸ�ʽ���ݣ�������ִ洢����
		*/
		void clearBufferSubData(BufferSizedInternalFormat internalformat, ptrdiff_t offset, ptrdiff_t size, BufferImageInternalFormat format, BufferImageDataType type, const void* data);
		/**
		*	���Ʋ��ִ洢����
		*/
		void copyBufferSubData(ptrdiff_t readOffset, uint32_t writeBuffer, ptrdiff_t writeOffset, ptrdiff_t size);
	public:
		/**
		*	��ȡ����
		*/
		void getBufferParameter(GetBufferParameter pname, int* params);
		/**
		*	��ȡ����
		*/
		void getBufferParameter(GetBufferParameter pname, int64_t* params);
		/**
		*	��ȡָ��λ�õ�����ָ��
		*/
		void* setBufferRange(ptrdiff_t offset, ptrdiff_t length, uint32_t access);
		/**
		*	ָ֪ͨ��λ�õ����ݷ����ı�
		*/
		void flushMappedBufferRange(ptrdiff_t offset, ptrdiff_t length);
		/**
		*	ȡ������buffer
		*/
		void unmapBuffer();
	};
}