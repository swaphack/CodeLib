#pragma once

#include "../Function.h"
#include "Number/Decimal.h"
#include "Basic/base.h"

namespace math
{
	//////////////////////////////////////////////////////////////////////////
	/**
	*	初等函数
	*/
	class ElementaryFunction : public Function
	{
	public:
		virtual Decimal getValue(const Decimal& var);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	常数函数
	*/
	class ConstantFunction : public ElementaryFunction
	{
	public:
		ConstantFunction();
		ConstantFunction(float constant);
	public:
		/**
		*	常数
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(Decimal, Constant, 0.0f);
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	指数函数
	*	y = e ^ x;
	*/
	class ExponentialFunction : public ElementaryFunction
	{
	public:
		ExponentialFunction();
		ExponentialFunction(float exp);
	public:
		/**
		*	指数
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(Decimal, Exp, 0.0f);
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	对数函数
	*	y = log (x);
	*/
	class LogarithmicFunction : public ElementaryFunction
	{
	public:
		LogarithmicFunction();
		LogarithmicFunction(float base);
	public:
		/**
		*	底数
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(Decimal, Base, 0.0f);
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	幂函数
	*	y = x ^ p
	*/
	class PowerFunction : public ElementaryFunction
	{
	public:
		PowerFunction();
		PowerFunction(float power);
	public:
		/**
		*	幂
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(Decimal, Power, 0.0f);
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};
}