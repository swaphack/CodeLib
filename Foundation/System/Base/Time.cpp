#include "Time.h"
#include "../Math/import.h"

using namespace sys;

Time::Time()
{

}

Time::~Time()
{

}

Time* Time::getNow()
{
	time_t now;
	time(&now);

	struct tm* stm = new struct tm;
	
	localtime_s(stm, &now);

	Time* time = new Time();
	time->setTM(stm);
	delete stm;

	return time;
}

void Time::addSecond(int val)
{
	_tm.tm_sec += val;
	this->resetTime();
}

void Time::addMinute(int val)
{
	_tm.tm_min += val;
	this->resetTime();
}

void Time::addHour(int val)
{
	_tm.tm_hour += val;
	this->resetTime();
}

void Time::addDay(int val)
{
	_tm.tm_yday += val;
	this->resetTime();
}

void Time::addYear(int val)
{
	_tm.tm_year += val;
	this->resetTime();
}

void Time::setTM(struct tm* stm)
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

time_t sys::Time::getTime()
{
	time_t tt = mktime(&_tm);
	return tt;
}

void Time::resetTime()
{
	time_t tt = mktime(&_tm);
	localtime_s(&_tm, &tt);
}
