#include "HttpTime.h"

using namespace web;

const char* HttpTime::TIME_WKDAY[7] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };

const char* HttpTime::TIME_WEEKDAY[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

const char*HttpTime::TIME_MONTH[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

//////////////////////////////////////////////////////////////////////////
/* Sun, 06 Nov 1994 08:49:37 GMT */
sys::String HttpTime::getRFC882Time(sys::Time* time)
{
	sys::String strTime;
	if (time == nullptr)
	{
		return strTime;
	}
	strTime.make("%s, %02d %s %d %02d:%02d%02d GMT",
		TIME_WKDAY[time->getWeekday()],
		time->getMonthDay(),
		TIME_MONTH[time->getMonth() - sys::Time::IndexOfMonth],
		time->getYear(),
		time->getHour(),
		time->getMinute(),
		time->getSecond());

	return strTime;
}

/* Sunday, 06-Nov-94 08:49:37 GMT */
sys::String HttpTime::getRFC850Time(sys::Time* time)
{
	sys::String strTime;
	if (time == nullptr)
	{
		return strTime;
	}
	strTime.make("%s, %02d-%s-%d %02d:%02d%02d GMT",
		TIME_WEEKDAY[time->getWeekday()],
		time->getMonthDay(),
		TIME_MONTH[time->getMonth() - sys::Time::IndexOfMonth],
		time->getYear() - sys::Time::StartYear,
		time->getHour(),
		time->getMinute(),
		time->getSecond());

	return strTime;
}

/* Sun Nov  6 08:49:37 1994 */
sys::String HttpTime::getANSITime(sys::Time* time)
{
	sys::String strTime;
	if (time == nullptr)
	{
		return strTime;
	}
	strTime.make("%s %s %d %02d:%02d%02d GMT",
		TIME_WKDAY[time->getWeekday()],
		TIME_MONTH[time->getMonth() - sys::Time::IndexOfMonth],
		time->getMonthDay(),
		time->getHour(),
		time->getMinute(),
		time->getSecond(),
		time->getYear());

	return strTime;
}

