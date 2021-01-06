#include "DateTime.h"

using namespace sys;

DateTime* DateTime::s_now = nullptr;
DateTime* DateTime::s_gm = nullptr;

DateTime::DateTime()
{
	this->setTime(getNowTimeStamp());
}

DateTime::DateTime(time_t tt)
{
	this->setTime(tt);
}

DateTime::DateTime(struct tm* stm)
{
	this->setTime(stm);
}

DateTime::~DateTime()
{

}

DateTime* DateTime::getNow()
{
	if (s_now == nullptr)
	{
		s_now = new DateTime();
	}

	time_t now = 0;
	struct tm* stm = new struct tm();

	time(&now);
	localtime_s(stm, &now);

	s_now->setTime(stm);

	delete stm;

	return s_now;
}

DateTime* DateTime::getGM()
{
	if (s_gm == nullptr)
	{
		s_gm = new DateTime();
	}

	time_t now = 0;
	struct tm* stm = new struct tm();

	time(&now);
	gmtime_s(stm, &now);

	s_gm->setTime(stm);

	delete stm;

	return s_gm;
}

time_t DateTime::getNowTimeStamp()
{
	time_t now;
	time(&now);

	return now;
}

time_t DateTime::getGMTimeStamp()
{
	time_t now;
	gmtime(&now);

	return now;
}

void DateTime::addSecond(int32_t val)
{
	_tm.tm_sec += val;
	this->resetTime();
}

void DateTime::addMinute(int32_t val)
{
	_tm.tm_min += val;
	this->resetTime();
}

void DateTime::addHour(int32_t val)
{
	_tm.tm_hour += val;
	this->resetTime();
}

void DateTime::addDay(int32_t val)
{
	_tm.tm_yday += val;
	this->resetTime();
}

void DateTime::addYear(int32_t val)
{
	_tm.tm_year += val;
	this->resetTime();
}

void DateTime::setTime(struct tm* stm)
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

void DateTime::setTime(time_t tt)
{
	localtime_s(&_tm, &tt);
}

time_t DateTime::getTimeStamp()
{
	time_t tt = mktime(&_tm);
	return tt;
}

void DateTime::setTime(DateTime* time)
{
	if (time == nullptr)
	{
		return;
	}

	this->setTime(time->getTimeStamp());
}

void DateTime::resetTime()
{
	time_t tt = mktime(&_tm);
	localtime_s(&_tm, &tt);
}
