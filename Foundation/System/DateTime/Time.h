#pragma once

#include <ctime>
#include <cstdint>

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
		static const int32_t StartYear = 1900;
		// ʵ���·�����
		static const int32_t IndexOfMonth = 1;
		// ��ȡ���ص�ǰʱ��,�����ͷ�
		static Time* getNow();
		// ��ȡ����ʱ��,�����ͷ�
		static Time* getGM();
		// ��ȡ���ص�ǰʱ���
		static time_t getNowTimeStamp();
		// ��ȡ���ص�ǰʱ���
		static time_t getGMTimeStamp();
		// ��ȡ���
		inline int32_t getYear() const { return _tm.tm_year + StartYear; }
		// ��ȡ����ĵڼ���
		inline int32_t getYearDay() const { return _tm.tm_yday; }
		// ��ȡ�·�
		inline int32_t getMonth() const { return _tm.tm_mon + IndexOfMonth; }
		// ��ȡ���µĵڼ���
		inline int32_t getMonthDay() const { return _tm.tm_mday; }
		// ��ȡ���ڼ�
		inline int32_t getWeekday() const { return _tm.tm_wday; }
		// ��ȡСʱ��
		inline int32_t getHour() const { return _tm.tm_hour; }
		// ��ȡ������
		inline int32_t getMinute() const { return _tm.tm_min; }
		// ��ȡ����
		inline int32_t getSecond() const { return _tm.tm_sec; }
		// �ı�����
		void addSecond(int32_t val);
		// �ı����
		void addMinute(int32_t val);
		// �ı�Сʱ��
		void addHour(int32_t val);
		// �ı�����
		void addDay(int32_t val);
		// �ı����
		void addYear(int32_t val);
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