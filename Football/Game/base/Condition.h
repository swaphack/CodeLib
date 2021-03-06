#pragma once

namespace game
{
	class ICondition
	{
	public:
		virtual ~ICondition() {}
		/**
		*	是否匹配条件
		*/
		virtual bool match(float value) const = 0;
	};
	/**
	*	单值条件型
	*/
	class SingleCondtion
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
		// 默认值
		float m_fValue;
		// 操作符类型
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
		// 最小值
		float m_fMinValue;
		// 最大值
		float m_fMaxValue;
		// 区间类型
		int m_nInterval;
	};
}