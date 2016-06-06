#pragma once

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
		ERT_PTR,
	};

	// ���
	class Result : public sys::Object
	{
	public:
		Result();
		virtual ~Result();
	public:
		ResultType getType();
	protected:
		void setType(ResultType value);
	private:
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
	private:
		void* _value;
	};
}