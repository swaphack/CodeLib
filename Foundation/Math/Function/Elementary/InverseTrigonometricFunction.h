#pragma once

#include "ElementaryFunction.h"

namespace math
{
	/**
	*	反三角函数
	*/
	class InverseTrigonometricFunction : public ElementaryFunction
	{

	};

	/**
	*	反正弦函数
	*	y = arcsin (x)
	*/
	class ArcSinFunction : public InverseTrigonometricFunction
	{
	public:
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	反余弦函数
	*	y = arccos (x)
	*/
	class ArcCosFunction : public InverseTrigonometricFunction
	{
	public:
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	反正切函数
	*	y = arctan (x)
	*/
	class ArcTanFunction : public InverseTrigonometricFunction
	{
	public:
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	反余切函数
	*	y = arccot (x)
	*/
	class ArcCotFunction : public InverseTrigonometricFunction
	{
	public:
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	反正割函数
	*	y = arcsec (x)
	*/
	class ArcSecFunction : public InverseTrigonometricFunction
	{
	public:
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	反余割函数
	*	y = arccsc (x)
	*/
	class ArcCscFunction : public InverseTrigonometricFunction
	{
	public:
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};
}