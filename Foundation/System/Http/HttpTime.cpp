#include "HttpTime.h"
#include "Base/macros.h"

using namespace sys;

const char* HttpTime::TIME_WKDAY[7] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };

const char* HttpTime::TIME_WEEKDAY[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

const char* HttpTime::TIME_MONTH[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

//////////////////////////////////////////////////////////////////////////
/* Sun, 06 Nov 1994 08:49:37 GMT */
const std::string& HttpTime::getRFC822Time(Time* time)
{
	if (time == nullptr)
	{
		return nullptr;
	}
	return getCString("%s, %02d %s %d %02d:%02d%02d GMT",
		TIME_WKDAY[time->getWeekday()],
		time->getMonthDay(),
		TIME_MONTH[time->getMonth() - Time::IndexOfMonth],
		time->getYear(),
		time->getHour(),
		time->getMinute(),
		time->getSecond());
}

/* Sunday, 06-Nov-94 08:49:37 GMT */
const std::string& HttpTime::getRFC850Time(Time* time)
{
	if (time == nullptr)
	{
		return nullptr;
	}
	return getCString("%s, %02d-%s-%d %02d:%02d%02d GMT",
		TIME_WEEKDAY[time->getWeekday()],
		time->getMonthDay(),
		TIME_MONTH[time->getMonth() - Time::IndexOfMonth],
		time->getYear() - Time::StartYear,
		time->getHour(),
		time->getMinute(),
		time->getSecond());
}

/* Sun Nov  6 08:49:37 1994 */
const std::string& HttpTime::getANSITime(Time* time)
{
	if (time == nullptr)
	{
		return nullptr;
	}
	return getCString("%s %s %d %02d:%02d%02d GMT",
		TIME_WKDAY[time->getWeekday()],
		TIME_MONTH[time->getMonth() - Time::IndexOfMonth],
		time->getMonthDay(),
		time->getHour(),
		time->getMinute(),
		time->getSecond(),
		time->getYear());
}

