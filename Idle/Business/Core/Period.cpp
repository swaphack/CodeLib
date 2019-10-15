#include "Period.h"

using namespace business;

Period::Period()
{

}

Period::~Period()
{

}

Period* Period::create(PeriodType eType)
{
	switch (eType)
	{
	case PeriodType::Second:
		return new SecondlyPeriod();
		break;
	case PeriodType::Minute:
		return new MinutelyPeriod();
		break;
	case PeriodType::Hour:
		return new HourlyPeriod();
		break;
	case PeriodType::Day:
		return new DailyPeriod();
		break;
	case PeriodType::Week:
		return new WeeklyPeriod();
		break;
	case PeriodType::Month:
		return new MonthlyPeriod();
		break;
	case PeriodType::Quarter:
		return new QuarterlyPeriod();
		break;
	case PeriodType::Year:
		return new YearlyPeriod();
		break;
	default:
		break;
	}
	return nullptr;
}

void Period::setDuration(float duration)
{
	m_nDuration = duration;
}

float Period::getDuration()
{
	return m_nDuration;
}

//////////////////////////////////////////////////////////////////////////

SecondlyPeriod::SecondlyPeriod()
{
	this->setDuration(1);
}

SecondlyPeriod::~SecondlyPeriod()
{

}

//////////////////////////////////////////////////////////////////////////


MinutelyPeriod::MinutelyPeriod()
{
	this->setDuration(60);
}

MinutelyPeriod::~MinutelyPeriod()
{

}

//////////////////////////////////////////////////////////////////////////

HourlyPeriod::HourlyPeriod()
{
	this->setDuration(3600);
}

HourlyPeriod::~HourlyPeriod()
{

}
//////////////////////////////////////////////////////////////////////////

DailyPeriod::DailyPeriod()
{
	this->setDuration(86400);
}

DailyPeriod::~DailyPeriod()
{

}

//////////////////////////////////////////////////////////////////////////
WeeklyPeriod::WeeklyPeriod()
{
	this->setDuration(604800);
}

WeeklyPeriod::~WeeklyPeriod()
{

}

//////////////////////////////////////////////////////////////////////////

MonthlyPeriod::MonthlyPeriod()
{
}

MonthlyPeriod::~MonthlyPeriod()
{

}
//////////////////////////////////////////////////////////////////////////

QuarterlyPeriod::QuarterlyPeriod()
{

}

QuarterlyPeriod::~QuarterlyPeriod()
{

}
//////////////////////////////////////////////////////////////////////////

YearlyPeriod::YearlyPeriod()
{

}

YearlyPeriod::~YearlyPeriod()
{

}
