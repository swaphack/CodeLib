#pragma once

#include "../Base/Types.h"
#include "IStreamBase.h"

namespace sys
{
	// ��������
	class StreamHelper
	{
	public:
		// ����һ����С�����ƶ�����ռ���ڴ�
		static char* mallocStream(ss_t size);
		// ����һ����С����Ŀ�������ڴ棬����ֵ
		static char* mallocStream(void* data, ss_t size);
		// ����һ����С����ָ������ռ���ڴ棬����������
		static char* mallocStream(ss_t capacity, void* data, ss_t size);
		// �ͷ���
		static void freeStream(void* data);
	protected:
	private:
	};

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
		int getLength() const;
		// �������ݳ���
		void setLength(int length);
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
		int getLength() const;
		// �������ݳ���
		void setLength(int length);
		// �ͷ�������
		void freeStream();
	protected:
		// ���ݳ���
		ss_t _length;
		// ��������
		char* _data;
	};

}