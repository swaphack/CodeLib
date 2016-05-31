#pragma once

#include <ctime>

namespace sys
{
	class Time
	{
	public:
		Time();
		~Time();
	public:
		static const int StartYear = 1900;
		static const int AddMonth = 1;

		inline int getYear() const { return _tm.tm_year + StartYear; }

		inline int getYearDay() const { return _tm.tm_yday; }

		inline int getMonth() const { return _tm.tm_mon + AddMonth; }

		inline int getMonthDay() const { return _tm.tm_mday; }

		inline int getWeekday() const { return _tm.tm_wday; }

		inline int getHour() const { return _tm.tm_hour; }

		inline int getMinute() const { return _tm.tm_min; }

		inline int getSecond() const { return _tm.tm_sec; }

		static Time* getNow();

		void addSecond(int val);
		void addMinute(int val);
		void addHour(int val);
		void addDay(int val);
		void addYear(int val);

		void setTime(time_t tt);
		void setTM(struct tm* stm);
	protected:
		void adjustTM();
	protected:
		tm _tm;
	};
}