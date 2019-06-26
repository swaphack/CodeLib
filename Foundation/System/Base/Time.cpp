#include "Time.h"
#include "Math/import.h"

using namespace sys;

Time* Time::s_now = nullptr;
Time* Time::s_gm = nullptr;

Time::Time()
{
	this->setTime(getNowTimeStamp());
}

Time::Time(time_t tt)
{
	this->setTime(tt);
}

Time::Time(struct tm* stm)
{
	this->setTime(stm);
}

Time::~Time()
{

}

Time* Time::getNow()
{
	if (s_now == nullptr)
	{
		s_now = new Time();
	}

	time_t now = 0;
	struct tm* stm = new struct tm();

	time(&now);
	localtime_s(stm, &now);

	s_now->setTime(stm);

	delete stm;

	return s_now;
}

Time* Time::getGM()
{
	if (s_gm == nullptr)
	{
		s_gm = new Time();
	}

	time_t now = 0;
	struct tm* stm = new struct tm();

	time(&now);
	gmtime_s(stm, &now);

	s_gm->setTime(stm);

	delete stm;

	return s_gm;
}

time_t Time::getNowTimeStamp()
{
	time_t now;
	time(&now);

	return now;
}

time_t Time::getGMTimeStamp()
{
	time_t now;
	gmtime(&now);

	return now;
}

void Time::addSecond(int32 val)
{
	_tm.tm_sec += val;
	this->resetTime();
}

void Time::addMinute(int32 val)
{
	_tm.tm_min += val;
	this->resetTime();
}

void Time::addHour(int32 val)
{
	_tm.tm_hour += val;
	this->resetTime();
}

void Time::addDay(int32 val)
{
	_tm.tm_yday += val;
	this->resetTime();
}

void Time::addYear(int32 val)
{
	_tm.tm_year += val;
	this->resetTime();
}

void Time::setTime(struct tm* stm)
{
	if (stm == nullptr)
	{
		return;
	}

	_tm.tm_year = stm->tm_year;
	_tm.tm_yday = stm->tm_yday;
	_tm.tm_mon = stm->tm_mon;
	_tm.tm_mday = stm->tm_mday;
	_tm.tm_wday = stm->tm_wday;
	_tm.tm_hour = stm->tm_hour;
	_tm.tm_min = stm->tm_min;
	_tm.tm_sec = stm->tm_sec;
}

void Time::setTime(time_t tt)
{
	localtime_s(&_tm, &tt);
}

time_t Time::getTimeStamp()
{
	time_t tt = mktime(&_tm);
	return tt;
}

void Time::setTime(Time* time)
{
	if (time == nullptr)
	{
		return;
	}

	this->setTime(time->getTimeStamp());
}

void Time::resetTime()
{
	time_t tt = mktime(&_tm);
	localtime_s(&_tm, &tt);
}
