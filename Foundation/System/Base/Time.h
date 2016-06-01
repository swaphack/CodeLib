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
		// ��ȡ���ص�ǰʱ��
		static Time* getNow();
		// ��ȡ���ص�ǰʱ���
		static time_t getNowTimeStamp();
		// ��ȡ���
		inline int getYear() const { return _tm.tm_year + StartYear; }
		// ��ȡ����ĵڼ���
		inline int getYearDay() const { return _tm.tm_yday; }
		// ��ȡ�·�
		inline int getMonth() const { return _tm.tm_mon + AddMonth; }
		// ��ȡ���µĵڼ���
		inline int getMonthDay() const { return _tm.tm_mday; }
		// ��ȡ���ڼ�
		inline int getWeekday() const { return _tm.tm_wday; }
		// ��ȡСʱ��
		inline int getHour() const { return _tm.tm_hour; }
		// ��ȡ������
		inline int getMinute() const { return _tm.tm_min; }
		// ��ȡ����
		inline int getSecond() const { return _tm.tm_sec; }
		// �ı�����
		void addSecond(int val);
		// �ı����
		void addMinute(int val);
		// �ı�Сʱ��
		void addHour(int val);
		// �ı�����
		void addDay(int val);
		// �ı����
		void addYear(int val);
		// ����ʱ���
		void setTime(time_t tt);
		// ����ʱ���ʽ
		void setTM(struct tm* stm);
		// ��ȡʱ���
		time_t getTime();
	protected:
		// �����¼�
		void resetTime();
	protected:
		tm _tm;
	};
}