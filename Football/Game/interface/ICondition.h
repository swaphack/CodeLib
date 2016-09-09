#pragma once

#include "Identity.h"

namespace game
{
	/**
	*	������
	*/
	class ICondition : public Identity
	{
	public:
		virtual ~ICondition() {}
	public:
		/**
		*	������
		*/
		virtual int getOperator() const = 0;
		/**
		*	�Ƿ�ƥ������
		*/
		virtual bool match(float value) const = 0;
	};

	/**
	*	��ֵ������
	*/
	class ISingleCondtion : public ICondition
	{
	public:
		virtual ~ISingleCondtion() {}
	public:
		/**
		*	����ֵ
		*/
		virtual float getValue() const = 0;
	};

	/**
	*	����������
	*/
	class IIntervalCondtion : public ICondition
	{
	public:
		virtual ~IIntervalCondtion() {}
	public:
		/**
		*	������Сֵ
		*/
		virtual float getMinValue() const = 0;
		/**
		*	�������ֵ
		*/
		virtual float getMinValue() const = 0;
	};
}