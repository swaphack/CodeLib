#include "TaskTimeLimit.h"

alg::work::TaskTimeLimit::TaskTimeLimit()
{

}
alg::work::TaskTimeLimit::TaskTimeLimit(float nTime)
{
	setTime(nTime);
}

alg::work::TaskTimeLimit::~TaskTimeLimit()
{

}


void alg::work::TaskTimeLimit::setTime(float nTime)
{
	m_fTotalTime = nTime;
	m_fCurrentTime = 0;
}

float alg::work::TaskTimeLimit::getCurrentTime() const
{
	return m_fCurrentTime;
}

float alg::work::TaskTimeLimit::getTotalTime() const
{
	return m_fTotalTime;
}

void alg::work::TaskTimeLimit::onUpdate(float dt)
{
	if (m_fCurrentTime >= m_fTotalTime) return;
	m_fCurrentTime += dt;
	if (m_fCurrentTime >= m_fTotalTime)
	{// ³¬Ê±´¥·¢
		this->setTrigger(true);
	}
}

void alg::work::TaskTimeLimit::onReset()
{
	TaskLimit::onReset();

	this->setTime(m_fTotalTime);
}
