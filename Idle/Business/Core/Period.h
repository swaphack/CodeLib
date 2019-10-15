#pragma once

namespace business
{
	// 周期类型
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

	// 周期
	class Period
	{
	public:
		Period();
		virtual ~Period();
	public: 
		static Period* create(PeriodType eType);
	public:
		void setDuration(float duration);
		// 周期
		float getDuration();
	private:
		// 周期
		float m_nDuration = 0;
	};

	// 每秒
	class SecondlyPeriod : public Period
	{
	public:
		SecondlyPeriod();
		virtual ~SecondlyPeriod();
	protected:
	private:
	};

	// 每分钟
	class MinutelyPeriod : public Period
	{
	public:
		MinutelyPeriod();
		virtual ~MinutelyPeriod();
	protected:
	private:
	};

	// 每小时
	class HourlyPeriod : public Period
	{
	public:
		HourlyPeriod();
		virtual ~HourlyPeriod();
	protected:
	private:
	};

	// 每天
	class DailyPeriod : public Period
	{
	public:
		DailyPeriod();
		virtual ~DailyPeriod();
	protected:
	private:
	};

	// 每周
	class WeeklyPeriod : public Period
	{
	public:
		WeeklyPeriod();
		virtual ~WeeklyPeriod();
	protected:
	private:
	};

	// 每月
	class MonthlyPeriod : public Period
	{
	public:
		MonthlyPeriod();
		virtual ~MonthlyPeriod();
	protected:
	private:
	};

	// 每季度
	class QuarterlyPeriod : public Period
	{
	public:
		QuarterlyPeriod();
		virtual ~QuarterlyPeriod();
	protected:
	private:
	};

	// 每年
	class YearlyPeriod : public Period
	{
	public:
		YearlyPeriod();
		virtual ~YearlyPeriod();
	protected:
	private:
	};
}