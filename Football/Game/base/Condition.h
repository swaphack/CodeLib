#pragma once

namespace game
{
	class ICondition
	{
	public:
		virtual ~ICondition() {}
		/**
		*	�Ƿ�ƥ������
		*/
		virtual bool match(float value) const = 0;
	};
	/**
	*	��ֵ������
	*/
	class SingleCondtion
	{
	public:
		SingleCondtion();
		virtual ~SingleCondtion();
	public:
		/**
		*	������
		*/
		virtual int getOperator() const;
		/**
		*	������
		*	@param eOperator @see enum eOperator
		*/
		void setOperator(int eOperator);
		/**
		*	�Ƿ�ƥ������
		*/
		virtual bool match(float value) const;
		/**
		*	����ֵ
		*/
		float getValue() const;
		/**
		*	����ֵ
		*/
		void setValue(float value);
	private:
		// Ĭ��ֵ
		float m_fValue;
		// ����������
		int m_nOperator;
	};

	/**
	*	����������
	*/
	class IntervalCondtion : public ICondition
	{
	public:
		IntervalCondtion();
		virtual ~IntervalCondtion();
	public:
		/**
		*	��������
		*/
		virtual int getInterval() const;
		/**
		*	��������
		*	@param eInterval @see enum eInterval
		*/
		void setInterval(int eInterval);
		/**
		*	�Ƿ�ƥ������
		*/
		virtual bool match(float value) const;
		/**
		*	������Сֵ
		*/
		virtual float getMinValue() const;
		/**
		*	������Сֵ
		*/
		virtual void setMinValue(float value);
		/**
		*	�������ֵ
		*/
		virtual float getMaxValue() const;
		/**
		*	�������ֵ
		*/
		virtual void setMaxValue(float value);
	private:
		// ��Сֵ
		float m_fMinValue;
		// ���ֵ
		float m_fMaxValue;
		// ��������
		int m_nInterval;
	};
}