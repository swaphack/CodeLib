#pragma once

#include "../interface/ICondition.h"

namespace game
{
	/**
	*	单值条件型
	*/
	class SingleCondtion : public ICondition
	{
	public:
		SingleCondtion();
		virtual ~SingleCondtion();
	public:
		/**
		*	操作符
		*/
		virtual int getOperator() const;
		/**
		*	操作符
		*	@param eOperator @see enum eOperator
		*/
		void setOperator(int eOperator);
		/**
		*	是否匹配条件
		*/
		virtual bool match(float value) const;
		/**
		*	属性值
		*/
		float getValue() const;
		/**
		*	属性值
		*/
		void setValue(float value);
	private:
		float m_fValue;
		int m_nOperator;
	};

	/**
	*	区间条件型
	*/
	class IntervalCondtion : public ICondition
	{
	public:
		IntervalCondtion();
		virtual ~IntervalCondtion();
	public:
		/**
		*	区间类型
		*/
		virtual int getInterval() const;
		/**
		*	区间类型
		*	@param eInterval @see enum eInterval
		*/
		void setInterval(int eInterval);
		/**
		*	是否匹配条件
		*/
		virtual bool match(float value) const;
		/**
		*	属性最小值
		*/
		virtual float getMinValue() const;
		/**
		*	属性最小值
		*/
		virtual void setMinValue(float value);
		/**
		*	属性最大值
		*/
		virtual float getMaxValue() const;
		/**
		*	属性最大值
		*/
		virtual void setMaxValue(float value);
	private:
		float m_fMinValue;
		float m_fMaxValue;
		int m_nInterval;
	};
}