#pragma once

#include "Identity.h"

namespace game
{
	/**
	*	条件型
	*/
	class ICondition : public Identity
	{
	public:
		virtual ~ICondition() {}
	public:
		/**
		*	操作符
		*/
		virtual int getOperator() const = 0;
		/**
		*	是否匹配条件
		*/
		virtual bool match(float value) const = 0;
	};

	/**
	*	单值条件型
	*/
	class ISingleCondtion : public ICondition
	{
	public:
		virtual ~ISingleCondtion() {}
	public:
		/**
		*	属性值
		*/
		virtual float getValue();
	};

	/**
	*	区间条件型
	*/
	class IIntervalCondtion : public ICondition
	{
	public:
		virtual ~IIntervalCondtion() {}
	public:
		/**
		*	属性最小值
		*/
		virtual float getMinValue();
		/**
		*	属性最大值
		*/
		virtual float getMinValue();
	};
}