#include "ITimer.h"


void IIntervalTimer::SetInterval(float dt)
{
	m_fInterval = dt;
}

float IIntervalTimer::GetInterval()
{
	return m_fInterval;
}

void IIntervalTimer::SetCallback(std::function<void()> handler)
{
	m_pCallback = handler;
}

void IIntervalTimer::Update(float dt)
{
	if (Finish())
	{
		return;
	}
	m_fCurTime += dt;
	if (Finish())
	{
		if (m_pCallback)
		{
			m_pCallback();
		}
	}
}

void IIntervalTimer::Reset()
{
	m_fCurTime = 0;
}

bool IIntervalTimer::Finish()
{
	return m_fCurTime >= m_fInterval;
}
