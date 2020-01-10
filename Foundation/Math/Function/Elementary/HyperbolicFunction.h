#pragma once

#include "ElementaryFunction.h"

namespace math
{
	/**
	*	双曲函数
	*/
	class HyperbolicFunction : public ElementaryFunction
	{
	public:
	};

	/**
	*	双曲正弦函数
	*	y = sinh (x) = (e^(x) - e^(-x)) * 0.5f
	*/
	class SinhFunction : public HyperbolicFunction
	{
	public:
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	双曲余弦函数
	*	y = sinh (x) = (e^(x) + e^(-x)) * 0.5f
	*/
	class CoshFunction : public HyperbolicFunction
	{
	public:
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	双曲正切函数
	*	y = tanh (x) = sinh(x) / cosh(x)
	*/
	class TanhFunction : public HyperbolicFunction
	{
	public:
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	双曲余切函数
	*	y = coth (x) = cosh(x) / sinh(x)
	*/
	class CothFunction : public HyperbolicFunction
	{
	public:
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	双曲正割函数
	*	y = sech (x) = 1 / cosh(x) 
	*/
	class SechFunction : public HyperbolicFunction
	{
	public:
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	双曲余割函数
	*	y = csch (x) = 1 / sinh(x)
	*/
	class CschFunction : public HyperbolicFunction
	{
	public:
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};
}