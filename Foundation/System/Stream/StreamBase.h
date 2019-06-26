#pragma once

#include "Base/Types.h"
#include "IStreamBase.h"
#include "StreamHelper.h"

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
		int32 getLength() const;
		// �������ݳ���
		void setLength(int32 length);
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
		int32 getLength() const;
		// �������ݳ���
		void setLength(int32 length);
		// �ͷ�������
		void freeStream();
	protected:
		// ���ݳ���
		ss_t _length;
		// ��������
		char* _data;
	};

}