#pragma once

#include "../Function.h"
#include "Number/Decimal.h"
#include "Basic/base.h"

namespace math
{
	//////////////////////////////////////////////////////////////////////////
	/**
	*	���Ⱥ���
	*/
	class ElementaryFunction : public Function
	{
	public:
		virtual Decimal getValue(const Decimal& var);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	��������
	*/
	class ConstantFunction : public ElementaryFunction
	{
	public:
		ConstantFunction();
		ConstantFunction(float constant);
	public:
		/**
		*	����
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(Decimal, Constant, 0.0f);
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	ָ������
	*	y = e ^ x;
	*/
	class ExponentialFunction : public ElementaryFunction
	{
	public:
		ExponentialFunction();
		ExponentialFunction(float exp);
	public:
		/**
		*	ָ��
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(Decimal, Exp, 0.0f);
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	��������
	*	y = log (x);
	*/
	class LogarithmicFunction : public ElementaryFunction
	{
	public:
		LogarithmicFunction();
		LogarithmicFunction(float base);
	public:
		/**
		*	����
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(Decimal, Base, 0.0f);
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	�ݺ���
	*	y = x ^ p
	*/
	class PowerFunction : public ElementaryFunction
	{
	public:
		PowerFunction();
		PowerFunction(float power);
	public:
		/**
		*	��
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(Decimal, Power, 0.0f);
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};
}