#pragma once

#include <cstdio>
#include <sys/timeb.h>
#include <cstdlib>
#include <cstdint>

namespace sys
{
	/**
	*	ʱ��
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
		*	������
		*/
		void setSeconds(uint64_t seconds);
		/**
		*	��
		*/
		uint64_t getSeconds() const;
		/**
		*	���ú���
		*/
		void setMilliseconds(uint16_t milliseconds);
		/**
		*	����
		*/
		uint16_t getMilliseconds() const;
		/**
		*	�����ܺ���
		*/
		void setTotalMilliseconds(uint64_t milliseconds);
		/**
		*	�ܺ���
		*/
		uint64_t getTotalMilliseconds() const;
	public:
		TimeClock& operator=(const TimeClock& time);
		TimeClock& operator=(const timeb& time);
		TimeClock& operator=(const uint64_t& totalMilliseconds);

		uint64_t operator-(const TimeClock& time) const;
	public:
		/**
		*	��ʼ��¼
		*/
		static void startRecord();
		/**
		*	��¼
		*/
		static void record();
		/**
		*	������¼
		*/
		static void endRecord();
	private:
		// �ܺ�����
		timeb _timeColock;

		static TimeClock _recordTime;
	};
}
