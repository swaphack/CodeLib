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

bool TimerTask::isOver()
{
	return m_nTime == 0;
}

void TimerTask::setTime(uint64_t nTime)
{
	m_nTime = nTime;
}

uint64_t TimerTask::getTime()
{
	return m_nTime;
}
