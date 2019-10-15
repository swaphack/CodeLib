#pragma once

namespace business
{
	// ��������
	enum class PeriodType
	{
		Second,
		Minute,
		Hour,
		Day,
		Week,
		Month,
		Quarter,
		Year,
	};

	// ����
	class Period
	{
	public:
		Period();
		virtual ~Period();
	public: 
		static Period* create(PeriodType eType);
	public:
		void setDuration(float duration);
		// ����
		float getDuration();
	private:
		// ����
		float m_nDuration = 0;
	};

	// ÿ��
	class SecondlyPeriod : public Period
	{
	public:
		SecondlyPeriod();
		virtual ~SecondlyPeriod();
	protected:
	private:
	};

	// ÿ����
	class MinutelyPeriod : public Period
	{
	public:
		MinutelyPeriod();
		virtual ~MinutelyPeriod();
	protected:
	private:
	};

	// ÿСʱ
	class HourlyPeriod : public Period
	{
	public:
		HourlyPeriod();
		virtual ~HourlyPeriod();
	protected:
	private:
	};

	// ÿ��
	class DailyPeriod : public Period
	{
	public:
		DailyPeriod();
		virtual ~DailyPeriod();
	protected:
	private:
	};

	// ÿ��
	class WeeklyPeriod : public Period
	{
	public:
		WeeklyPeriod();
		virtual ~WeeklyPeriod();
	protected:
	private:
	};

	// ÿ��
	class MonthlyPeriod : public Period
	{
	public:
		MonthlyPeriod();
		virtual ~MonthlyPeriod();
	protected:
	private:
	};

	// ÿ����
	class QuarterlyPeriod : public Period
	{
	public:
		QuarterlyPeriod();
		virtual ~QuarterlyPeriod();
	protected:
	private:
	};

	// ÿ��
	class YearlyPeriod : public Period
	{
	public:
		YearlyPeriod();
		virtual ~YearlyPeriod();
	protected:
	private:
	};
}