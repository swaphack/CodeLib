#pragma once

#include <string>

namespace idea
{
	enum ResultType
	{
		// 无类型
		ERT_NONE,
		// 布尔类型
		ERT_BOOLEAN,
		// 实数类型
		ERT_NUMBER,
		// 字符串类型
		ERT_STRING,
		// 指针类型
		ERT_PTR,
	};

	// 结果
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

	// 布尔类型
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

	// 实数类型
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

	// 字符串类型
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

	// 指针类型
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