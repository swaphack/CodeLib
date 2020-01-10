#pragma once

#include "ElementaryFunction.h"

namespace math
{
	/**
	*	�����Ǻ���
	*/
	class InverseTrigonometricFunction : public ElementaryFunction
	{

	};

	/**
	*	�����Һ���
	*	y = arcsin (x)
	*/
	class ArcSinFunction : public InverseTrigonometricFunction
	{
	public:
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	�����Һ���
	*	y = arccos (x)
	*/
	class ArcCosFunction : public InverseTrigonometricFunction
	{
	public:
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	�����к���
	*	y = arctan (x)
	*/
	class ArcTanFunction : public InverseTrigonometricFunction
	{
	public:
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	�����к���
	*	y = arccot (x)
	*/
	class ArcCotFunction : public InverseTrigonometricFunction
	{
	public:
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	�������
	*	y = arcsec (x)
	*/
	class ArcSecFunction : public InverseTrigonometricFunction
	{
	public:
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};

	/**
	*	������
	*	y = arccsc (x)
	*/
	class ArcCscFunction : public InverseTrigonometricFunction
	{
	public:
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};
}