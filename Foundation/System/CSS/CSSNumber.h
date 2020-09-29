#pragma once

#include "NumberType.h"
#include <string>
namespace sys
{
#define ONE_HUNDRED 100.0f
#define PERCENT_ONE 0.01f
	// 百分比数值符号
#define PERCENT_NUMBER_SIGN "%"

	struct CSSNumber
	{
	public:
		CSSNumber();
		CSSNumber(NumberType eType, float value);
	public:
		CSSNumber& operator+=(const CSSNumber& value);
		CSSNumber& operator-=(const CSSNumber& value);
		bool operator==(const CSSNumber& value);
		bool operator!=(const CSSNumber& value);

		CSSNumber operator+(const CSSNumber& value);
		CSSNumber operator-(const CSSNumber& value);
		CSSNumber& operator=(const CSSNumber& value);
	public:
		/**
		*	转化成字符串
		*/
		std::string toString() const;
		/**
		*	从字符串获取数值
		*/
		static CSSNumber load(const std::string& text);
	public:
		/**
		*	是否是固定值
		*/
		bool isFixedValue() const;
		/**
		*	是否是百分比
		*/
		bool isPercentValue() const;
		/**
		*	获取类型
		*/
		NumberType getType() const;
		/**
		*	设置类型
		*/
		void setType(NumberType eType);
		/**
		*	获取值
		*/
		float getValue() const;
		/**
		*	设置值
		*/
		void setValue(float value);
		/**
		*	设置值
		*/
		void set(NumberType eType, float value);
	private:
		// 类型
		NumberType _type = NumberType::Fixed;
		// 值
		float _value = 0;
	};
}
