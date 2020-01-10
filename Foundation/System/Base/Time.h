#pragma once

#include <ctime>
#include "Base/Types.h"

namespace sys
{
	// 时间
	class Time
	{
	public:
		Time();
		Time(time_t tt);
		Time(struct tm* stm);
		~Time();
	public:
		// 起始计算年份
		static const int32_t StartYear = 1900;
		// 实际月份索引
		static const int32_t IndexOfMonth = 1;
		// 获取本地当前时间,不用释放
		static Time* getNow();
		// 获取格林时间,不用释放
		static Time* getGM();
		// 获取本地当前时间戳
		static time_t getNowTimeStamp();
		// 获取本地当前时间戳
		static time_t getGMTimeStamp();
		// 获取年份
		inline int32_t getYear() const { return _tm.tm_year + StartYear; }
		// 获取该年的第几天
		inline int32_t getYearDay() const { return _tm.tm_yday; }
		// 获取月份
		inline int32_t getMonth() const { return _tm.tm_mon + IndexOfMonth; }
		// 获取该月的第几天
		inline int32_t getMonthDay() const { return _tm.tm_mday; }
		// 获取星期几
		inline int32_t getWeekday() const { return _tm.tm_wday; }
		// 获取小时数
		inline int32_t getHour() const { return _tm.tm_hour; }
		// 获取分钟数
		inline int32_t getMinute() const { return _tm.tm_min; }
		// 获取秒数
		inline int32_t getSecond() const { return _tm.tm_sec; }
		// 改变秒数
		void addSecond(int32_t val);
		// 改变分钟
		void addMinute(int32_t val);
		// 改变小时数
		void addHour(int32_t val);
		// 改变天数
		void addDay(int32_t val);
		// 改变年份
		void addYear(int32_t val);
		// 由时间戳设置
		void setTime(time_t tt);
		// 由时间格式设置
		void setTime(struct tm* stm);
		// 设置时间
		void setTime(Time* time);
		// 获取时间戳
		time_t getTimeStamp();
	protected:
		// 更新事件
		void resetTime();
	protected:
		tm _tm;
	private:
		// 本地时间
		static Time* s_now;
		// 格林时间
		static Time* s_gm;
	};
}