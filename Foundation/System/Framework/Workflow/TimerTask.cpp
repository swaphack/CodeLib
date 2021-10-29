#include "TimerTask.h"
using namespace sys;
TimerTask::TimerTask()
{

}
TimerTask::TimerTask(uint64_t nTime)
{
	m_nTime = nTime;
}

TimerTask::~TimerTask()
{

}

bool TimerTask::isOver() const
{
	return m_nTime == 0;
}

void TimerTask::setTime(uint64_t nTime)
{
	m_nTime = nTime;
}

uint64_t TimerTask::getTime() const
{
	return m_nTime;
}
