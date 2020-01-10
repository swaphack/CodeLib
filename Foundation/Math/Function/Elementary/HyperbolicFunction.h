#pragma once

#include "ElementaryFunction.h"

namespace math
{
	/**
	*	˫������
	*/
	class HyperbolicFunction : public ElementaryFunction
	{
	public:
	};

	/**
	*	˫�����Һ���
	*	y = sinh (x) = (e^(x) - e^(-x)) * 0.5f
	*/
	class SinhFunction : public HyperbolicFunction
	{
	public:
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	˫�����Һ���
	*	y = sinh (x) = (e^(x) + e^(-x)) * 0.5f
	*/
	class CoshFunction : public HyperbolicFunction
	{
	public:
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	˫�����к���
	*	y = tanh (x) = sinh(x) / cosh(x)
	*/
	class TanhFunction : public HyperbolicFunction
	{
	public:
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	˫�����к���
	*	y = coth (x) = cosh(x) / sinh(x)
	*/
	class CothFunction : public HyperbolicFunction
	{
	public:
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	˫�������
	*	y = sech (x) = 1 / cosh(x) 
	*/
	class SechFunction : public HyperbolicFunction
	{
	public:
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	˫������
	*	y = csch (x) = 1 / sinh(x)
	*/
	class CschFunction : public HyperbolicFunction
	{
	public:
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};
}