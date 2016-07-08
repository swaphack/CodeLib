#pragma once

#include <ctime>

namespace sys
{
	// ʱ��
	class Time
	{
	public:
		Time();
		Time(time_t tt);
		Time(struct tm* stm);
		~Time();
	public:
		// ��ʼ�������
		static const int StartYear = 1900;
		// ʵ���·�����
		static const int IndexOfMonth = 1;
		// ��ȡ���ص�ǰʱ��,�����ͷ�
		static Time* getNow();
		// ��ȡ����ʱ��,�����ͷ�
		static Time* getGM();
		// ��ȡ���ص�ǰʱ���
		static time_t getNowTimeStamp();
		// ��ȡ���ص�ǰʱ���
		static time_t getGMTimeStamp();
		// ��ȡ���
		inline int getYear() const { return _tm.tm_year + StartYear; }
		// ��ȡ����ĵڼ���
		inline int getYearDay() const { return _tm.tm_yday; }
		// ��ȡ�·�
		inline int getMonth() const { return _tm.tm_mon + IndexOfMonth; }
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
		// ��ʱ�������
		void setTime(time_t tt);
		// ��ʱ���ʽ����
		void setTime(struct tm* stm);
		// ����ʱ��
		void setTime(Time* time);
		// ��ȡʱ���
		time_t getTimeStamp();
	protected:
		// �����¼�
		void resetTime();
	protected:
		tm _tm;
	private:
		// ����ʱ��
		static Time* s_now;
		// ����ʱ��
		static Time* s_gm;
	};
}