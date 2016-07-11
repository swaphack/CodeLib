#pragma once
#include "system.h"
#include <string>

namespace idea
{
	enum ResultType
	{
		// ������
		ERT_NONE,
		// ��������
		ERT_BOOLEAN,
		// ʵ������
		ERT_NUMBER,
		// �ַ�������
		ERT_STRING,
		// ָ������
		ERT_POINTER,
		// ��������
		ERT_REFERENCE,
	};

	// ���
	class Result : public sys::Object
	{
	public:
		Result();
		virtual ~Result();
	public:
		// ��ȡ����
		ResultType getType();
		// ��ȡ�ַ���ֵ
		virtual const char* getStringValue();
	protected:
		// ��������
		void setType(ResultType value);
	private:
		// �������
		ResultType _type;
	};

	// ��������
	class ResultBoolean : public Result
	{
	public:
		ResultBoolean(bool value);
		virtual ~ResultBoolean();
	public:
		bool getValue();
		// ��ȡ�ַ���ֵ
		// ���true,���ء�TRUE��,����FALSE��
		virtual const char* getStringValue();
	private:
		bool _value;
	};

	// ʵ������
	class ResultNumber : public Result
	{
	public:
		ResultNumber(float value);
		virtual ~ResultNumber();
	public:
		float getValue();
		// ��ȡ�ַ���ֵ
		virtual const char* getStringValue();
	private:
		float _value;
	};

	// �ַ�������
	class ResultString : public Result
	{
	public:
		ResultString(const char* value);
		virtual ~ResultString();
	public:
		const char* getValue();
		// ��ȡ�ַ���ֵ
		virtual const char* getStringValue();
	private:
		std::string _value;
	};

	// ָ������
	class ResultPtr : public Result
	{
	public:
		ResultPtr(void* value);
		virtual ~ResultPtr();
	public:
		void* getValue();
		// ��ȡ�ַ���ֵ
		virtual const char* getStringValue();
	private:
		void* _value;
	};

	// ��������
	class ResultRef : public Result
	{
	public:
		ResultRef(void* value);
		virtual ~ResultRef();
	public:
		void* getValue();
		// ��ȡ�ַ���ֵ
		virtual const char* getStringValue();
	private:
		void* _value;
	};
}