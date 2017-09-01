#include "Timer.h"
#include "ITimer.h"

static Timer* s_pInstance = nullptr;

Timer* Timer::GetInstance()
{
	if (s_pInstance == nullptr)
	{
		s_pInstance = new Timer();
	}

	return s_pInstance;
}

void Timer::RegisterTimer(ITimer* pTimer)
{
	if (pTimer == nullptr)
	{
		return;
	}

	m_setAddTimer.insert(pTimer);
}

void Timer::UnregisterTimer(ITimer* pTimer)
{
	if (pTimer == nullptr)
	{
		return;
	}

	m_setAddTimer.erase(pTimer);
	m_setRemoveTimer.insert(pTimer);
}

void Timer::Update(float dt)
{
	if (!m_setAddTimer.empty())
	{
		for (std::set<ITimer*>::iterator it = m_setAddTimer.begin();
			it != m_setAddTimer.end();
			it++)
		{
			m_setRunningTimer.insert(*it);
		}

		m_setAddTimer.clear();
	}

	if (!m_setRemoveTimer.empty())
	{
		for (std::set<ITimer*>::iterator it = m_setRemoveTimer.begin();
			it != m_setRemoveTimer.end();
			it ++)
		{
			m_setRunningTimer.erase(*it);
		}
		m_setRemoveTimer.clear();
	}	

	for (std::set<ITimer*>::iterator it = m_setRunningTimer.begin();
		it != m_setRunningTimer.end();
		it++)
	{
		(*it)->Update(dt);
	}

}
