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
		// 获取本地当前时间
		static Time* getNow();
		// 获取本地当前时间戳
		static time_t getNowTimeStamp();
		// 获取年份
		inline int getYear() const { return _tm.tm_year + StartYear; }
		// 获取该年的第几天
		inline int getYearDay() const { return _tm.tm_yday; }
		// 获取月份
		inline int getMonth() const { return _tm.tm_mon + AddMonth; }
		// 获取该月的第几天
		inline int getMonthDay() const { return _tm.tm_mday; }
		// 获取星期几
		inline int getWeekday() const { return _tm.tm_wday; }
		// 获取小时数
		inline int getHour() const { return _tm.tm_hour; }
		// 获取分钟数
		inline int getMinute() const { return _tm.tm_min; }
		// 获取秒数
		inline int getSecond() const { return _tm.tm_sec; }
		// 改变秒数
		void addSecond(int val);
		// 改变分钟
		void addMinute(int val);
		// 改变小时数
		void addHour(int val);
		// 改变天数
		void addDay(int val);
		// 改变年份
		void addYear(int val);
		// 设置时间戳
		void setTime(time_t tt);
		// 设置时间格式
		void setTM(struct tm* stm);
		// 获取时间戳
		time_t getTime();
	protected:
		// 更新事件
		void resetTime();
	protected:
		tm _tm;
	};
}