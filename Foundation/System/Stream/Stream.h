#pragma once
#include "macros.h"

namespace sys
{
#define STREAM_DEFAULT_SIZE 2

	class IStreamBase;

	class Stream
	{
	public:
		Stream(IStreamBase* baseStream);
		virtual ~Stream();
	public:
		// ������������
		virtual void setData(const void* data, size_t size);
		// ������ڴ泤��
		size_t getCapacity() const;
		// ��ȡ���ݳ���
		size_t getLength() const;
		// ��ȡ�α�λ��
		size_t getCursor() const;
		// ��ȡ����ָ��
		const char* getData() const;
		// ���û�����,�������Ƿ��ͷžɵ�������
		void setStream(IStreamBase* baseStream, bool disponable = false);
		// �����α�λ��
		void setCursor(size_t pos);
	protected:
		// ��ȡ������
		IStreamBase* getStream() const;
		// �α��Ƿ񳬳�����
		bool isOutOfLength();
		// �α��Ƿ񳬳�����
		bool isOutOfCapacity();
		// ��ȡ��ǰָ��
		char* getPtr();
		// ���÷�����������ڴ泤��
		void setCapacity(size_t capacity);
		// ��������������
		void setLength(size_t length);
	protected:
		// �α�
		size_t _cursor;
		// ������ڴ泤��
		size_t _capacity;
		// ����������
		IStreamBase* _baseStream;
	};
}