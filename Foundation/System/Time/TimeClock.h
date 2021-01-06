#pragma once

#include <cstdio>
#include <sys/timeb.h>
#include <cstdlib>
#include <cstdint>

namespace sys
{
	/**
	*	时钟
	*/
	class TimeClock
	{
	public:
		TimeClock();
		TimeClock(const TimeClock& time);
		TimeClock(const timeb& time);
		TimeClock(const uint64_t& totalMilliseconds);
		virtual ~TimeClock();
	public:
		static TimeClock* getNow();
		/**
		*	设置秒
		*/
		void setSeconds(uint64_t seconds);
		/**
		*	秒
		*/
		uint64_t getSeconds() const;
		/**
		*	设置毫秒
		*/
		void setMilliseconds(uint16_t milliseconds);
		/**
		*	毫秒
		*/
		uint16_t getMilliseconds() const;
		/**
		*	设置总毫秒
		*/
		void setTotalMilliseconds(uint64_t milliseconds);
		/**
		*	总毫秒
		*/
		uint64_t getTotalMilliseconds() const;
	public:
		TimeClock& operator=(const TimeClock& time);
		TimeClock& operator=(const timeb& time);
		TimeClock& operator=(const uint64_t& totalMilliseconds);

		uint64_t operator-(const TimeClock& time) const;
	public:
		/**
		*	开始记录
		*/
		static void startRecord();
		/**
		*	记录
		*/
		static void record();
		/**
		*	结束记录
		*/
		static void endRecord();
	private:
		// 总毫秒数
		timeb _timeColock;

		static TimeClock _recordTime;
	};
}
