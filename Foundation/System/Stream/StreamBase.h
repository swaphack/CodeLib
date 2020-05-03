#pragma once

#include "IStreamBase.h"
#include "Memory/MemoryPointer.h"
#include "Memory/MemoryData.h"

#include <cstring>

namespace sys
{
	// �����ݻ�������ȿ���
	class StreamBase : public IStreamBase
	{
	public:
		StreamBase();
		virtual ~StreamBase();
	public:
		// ������������
		virtual void setData(const char* data, size_t size);
		// ��ȡ��������
		const char* getData() const;
		// ��ȡ���ݳ���
		size_t getLength() const;
		// �������ݳ���
		void setLength(size_t length);
		// �ͷ�������
		void freeStream();
	protected:
		MemoryData _memoryData;
	};

	// ���������û�����ǳ����
	class StreamBaseRef : public IStreamBase
	{
	public:
		StreamBaseRef();
		virtual ~StreamBaseRef();
	public:
		// ������������
		virtual void setData(const char* data, size_t size);
		// ��ȡ��������
		const char* getData() const;
		// ��ȡ���ݳ���
		size_t getLength() const;
		// �������ݳ���
		void setLength(size_t length);
		// �ͷ�������
		void freeStream();
	protected:
		/**
		*	����
		*/
		size_t _length = 0;
		/**
		*	����
		*/
		char* _data = nullptr;
	};

}