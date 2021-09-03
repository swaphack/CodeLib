#pragma once

#include "NumberType.h"
#include <string>
namespace sys
{
#define ONE_HUNDRED 100.0f
#define PERCENT_ONE 0.01f
	// �ٷֱ���ֵ����
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
		*	ת�����ַ���
		*/
		std::string toString() const;
		/**
		*	ת�����ַ���������С�����λ
		*/
		std::string toString(int digits) const;
		/**
		*	���ַ�����ȡ��ֵ
		*/
		static CSSNumber load(const std::string& text);
	public:
		/**
		*	�Ƿ��ǹ�������
		*/
		bool isRelativeType() const;
		/**
		*	�Ƿ��ǹ̶�ֵ
		*/
		bool isFixedValue() const;
		/**
		*	�Ƿ��ǰٷֱ�
		*/
		bool isPercentValue() const;
		/**
		*	��ȡ����
		*/
		NumberType getType() const;
		/**
		*	��������
		*/
		void setType(NumberType eType);
		/**
		*	��ȡֵ
		*/
		float getValue() const;
		/**
		*	����ֵ
		*/
		void setValue(float value);
		/**
		*	����ֵ
		*/
		void set(NumberType eType, float value);
	public:
		/**
		*	��ȡʵ��ֵ
		*/
		float getRealValue() const;
		/**
		*	��ȡʵ��ֵ
		*/
		float getRealValue(float value) const;
		/**
		*	��ȡʵ��ֵ
		*/
		float getRealValueWithDefault(float defaultValue) const;
		/**
		*	��ȡʵ��ֵ
		*/
		float getRealValueWithDefault(float value, float defaultValue) const;
	private:
		// ����
		NumberType _type = NumberType::None;
		// ֵ
		float _value = 0;
	};
}
