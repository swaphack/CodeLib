#pragma once
#include "system.h"
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
		ERT_POINTER,
		// 引用类型
		ERT_REFERENCE,
	};

	// 结果
	class Result : public sys::Object
	{
	public:
		Result();
		virtual ~Result();
	public:
		// 获取类型
		ResultType getType();
		// 获取字符串值
		virtual const char* getStringValue();
	protected:
		// 设置类型
		void setType(ResultType value);
	private:
		// 结果类型
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
		// 获取字符串值
		// 如果true,返回“TRUE”,否则“FALSE”
		virtual const char* getStringValue();
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
		// 获取字符串值
		virtual const char* getStringValue();
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
		// 获取字符串值
		virtual const char* getStringValue();
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
		// 获取字符串值
		virtual const char* getStringValue();
	private:
		void* _value;
	};

	// 引用类型
	class ResultRef : public Result
	{
	public:
		ResultRef(void* value);
		virtual ~ResultRef();
	public:
		void* getValue();
		// 获取字符串值
		virtual const char* getStringValue();
	private:
		void* _value;
	};
}