#pragma once

#include "ElementaryFunction.h"

namespace math
{
	/**
	*	���Ǻ���
	*/
	class TrigonometricFunction : public ElementaryFunction
	{
	public:
	};

	/**
	*	���Һ���
	*	y = sin (x)
	*/
	class SinFunction : public TrigonometricFunction
	{
	public:
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	���Һ���
	*	y = cos (x)
	*/
	class CosFunction : public TrigonometricFunction
	{
	public:
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	���к���
	*	y = tan (x)
	*/
	class TanFunction : public TrigonometricFunction
	{
	public:
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	���к���
	*	y = cot (x)
	*/
	class CotFunction : public TrigonometricFunction
	{
	public:
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	�����
	*	y = sec (x)
	*/
	class SecFunction : public TrigonometricFunction
	{
	public:
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	����
	*	y = csc (x)
	*/
	class CscFunction : public TrigonometricFunction
	{
	public:
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};
}