#pragma once

#include "ElementaryFunction.h"

namespace math
{
	/**
	*	三角函数
	*/
	class TrigonometricFunction : public ElementaryFunction
	{
	public:
	};

	/**
	*	正弦函数
	*	y = sin (x)
	*/
	class SinFunction : public TrigonometricFunction
	{
	public:
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	余弦函数
	*	y = cos (x)
	*/
	class CosFunction : public TrigonometricFunction
	{
	public:
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	正切函数
	*	y = tan (x)
	*/
	class TanFunction : public TrigonometricFunction
	{
	public:
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	余切函数
	*	y = cot (x)
	*/
	class CotFunction : public TrigonometricFunction
	{
	public:
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	正割函数
	*	y = sec (x)
	*/
	class SecFunction : public TrigonometricFunction
	{
	public:
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	余割函数
	*	y = csc (x)
	*/
	class CscFunction : public TrigonometricFunction
	{
	public:
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};
}