#pragma once

#include "Buffer.h"

namespace render
{
	/**
	*	�������
	*/
	class NoNamedBuffer : public Buffer
	{
	public:
		NoNamedBuffer();
		virtual ~NoNamedBuffer();
	public:
		/**
		*	���ô洢����
		*/
		void setBufferStorage(ptrdiff_t size, const void* data, uint32_t flags);
		/**
		*	���ô洢����
		*/
		void setBufferStorage(ptrdiff_t size, const void* data, BufferStorageFlag flag);
	public:
		/**
		*	������
		*/
		void setBufferData(int size, BufferDataUsage usage);
		/**
		*	������
		*/
		void setBufferData(int size, const void* data, BufferDataUsage usage);
		/**
		*	���ò��ִ洢����
		*/
		void setBufferSubData(ptrdiff_t offset, ptrdiff_t size, const void* data);
		/**
		*	��ȡ���ִ洢����
		*/
		void getBufferSubData(ptrdiff_t offset, ptrdiff_t size, void* data);
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
		void copyBufferSubData(ptrdiff_t readOffset, BufferTarget writeTarget, ptrdiff_t writeOffset, ptrdiff_t size);
	public:
		/**
		*	��ȡ����
		*/
		void getBufferParameter(GetBufferTarget target, GetBufferParameter pname, int* params);
		/**
		*	��ȡ����
		*/
		void getBufferParameter(GetBufferTarget target, GetBufferParameter pname, int64_t* params);
		/**
		*	��ȡָ��λ�õ�����ָ��
		*/
		void* getMapBuffer(AccessType type);
		/**
		*	��ȡָ��λ�õ�����ָ��
		*/
		void* getMapBufferRange(ptrdiff_t offset, ptrdiff_t length, uint32_t access);
		/**
		*	��ȡָ��λ�õ�����ָ��
		*/
		void* getMapBufferRange(ptrdiff_t offset, ptrdiff_t length, MapBufferRangeAccess access);
		/**
		*	ȡ������buffer
		*/
		void unmapBuffer();

		/**
		*	ָ֪ͨ��λ�õ����ݷ����ı�
		*/
		void flushMappedBufferRange(ptrdiff_t offset, ptrdiff_t length);
		/**
		*	��ȡ����
		*/
		void flush(ptrdiff_t offset, ptrdiff_t length, sys::StreamReader& reader);
	};
}