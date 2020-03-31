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
		virtual void setData(const char* data, ss_t size);
		// ������ڴ泤��
		ss_t getCapacity() const;
		// ��ȡ���ݳ���
		ss_t getLength() const;
		// ��ȡ�α�λ��
		ss_t getCursor() const;
		// ��ȡ����ָ��
		const char* getData() const;
		// ���û�����,�������Ƿ��ͷžɵ�������
		void setStream(IStreamBase* baseStream, bool disponable = false);
		// �����α�λ��
		void setCursor(ss_t pos);
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
		void setCapacity(ss_t capacity);
		// ��������������
		void setLength(ss_t length);
	protected:
		// �α�
		ss_t _cursor;
		// ������ڴ泤��
		ss_t _capacity;
		// ����������
		IStreamBase* _baseStream;
	};
}