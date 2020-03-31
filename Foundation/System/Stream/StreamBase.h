#pragma once

#include "IStreamBase.h"

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
		virtual void setData(const char* data, ss_t size);
		// ��ȡ��������
		const char* getData() const;
		// ��ȡ���ݳ���
		int32_t getLength() const;
		// �������ݳ���
		void setLength(int32_t length);
		// �ͷ�������
		void freeStream();
	protected:
		// ���ݳ���
		ss_t _length;
		// ��������
		char* _data;
	};

	// ���������û�����ǳ����
	class StreamBaseRef : public IStreamBase
	{
	public:
		StreamBaseRef();
		virtual ~StreamBaseRef();
	public:
		// ������������
		virtual void setData(const char* data, ss_t size);
		// ��ȡ��������
		const char* getData() const;
		// ��ȡ���ݳ���
		int32_t getLength() const;
		// �������ݳ���
		void setLength(int32_t length);
		// �ͷ�������
		void freeStream();
	protected:
		// ���ݳ���
		ss_t _length;
		// ��������
		char* _data;
	};

}