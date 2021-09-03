#include "TimeClock.h"
#include <ctime>
#include "Base/macros.h"

sys::TimeClock sys::TimeClock::_recordTime = sys::TimeClock();
uint64_t sys::TimeClock::_recordDiffTime = 0;

sys::TimeClock::TimeClock()
{
	timeb timeClock;
	ftime(&timeClock);

	this->setSeconds(timeClock.time);
	this->setMilliseconds(timeClock.millitm);
}

sys::TimeClock::TimeClock(const TimeClock& time)
{
	this->setSeconds(time.getSeconds());
	this->setMilliseconds(time.getMilliseconds());
}

sys::TimeClock::TimeClock(const timeb& time)
{
	this->setSeconds(time.time);
	this->setMilliseconds(time.millitm);
}

sys::TimeClock::TimeClock(const uint64_t& totalMilliseconds)
{
	this->setSeconds(totalMilliseconds / 1000);
	this->setMilliseconds(totalMilliseconds % 1000);
}

sys::TimeClock::~TimeClock()
{
}

sys::TimeClock* sys::TimeClock::getNow()
{
	static TimeClock sInstance;

	timeb timeClock;
	ftime(&timeClock);

	sInstance = timeClock;
	return &sInstance;
}

void sys::TimeClock::setSeconds(uint64_t seconds)
{
	_timeColock.time = seconds;
}

uint64_t sys::TimeClock::getSeconds() const
{
	return _timeColock.time;
}

void sys::TimeClock::setMilliseconds(uint16_t milliseconds)
{
	_timeColock.millitm = milliseconds;
}

uint16_t sys::TimeClock::getMilliseconds() const
{
	return _timeColock.millitm;
}

void sys::TimeClock::setTotalMilliseconds(uint64_t milliseconds)
{
	_timeColock.millitm = milliseconds % 1000;
	_timeColock.time = milliseconds / 1000;
}

uint64_t sys::TimeClock::getTotalMilliseconds() const
{
	return _timeColock.time * 1000 + _timeColock.millitm;
}

sys::TimeClock& sys::TimeClock::operator=(const TimeClock& time)
{
	this->setSeconds(time.getSeconds());
	this->setMilliseconds(time.getMilliseconds());

	return *this;
}

sys::TimeClock& sys::TimeClock::operator=(const timeb& time)
{
	this->setSeconds(time.time);
	this->setMilliseconds(time.millitm);

	return *this;
}

sys::TimeClock& sys::TimeClock::operator=(const uint64_t& totalMilliseconds)
{
	this->setSeconds(totalMilliseconds / 1000);
	this->setMilliseconds(totalMilliseconds % 1000);

	return *this;
}

uint64_t sys::TimeClock::operator-(const TimeClock& time) const
{
	return getTotalMilliseconds() - time.getTotalMilliseconds();
}

void sys::TimeClock::startRecord()
{
	_recordTime = *getNow();
}

uint64_t sys::TimeClock::getDifferenceOfRecordTime()
{
	return _recordDiffTime;
}

void sys::TimeClock::endRecord()
{
	auto time = *getNow();

	_recordDiffTime = time - _recordTime;
	_recordTime = time;
}
