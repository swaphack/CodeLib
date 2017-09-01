#include "Tactics.h"
#include "Agent.h"
#include "Timer.h"
#include "Soldier.h"
#include "NumCalculation.h"
#include "Team.h"
#include "Field.h"

/// 攻击间隔
class AtkInterval : public IIntervalTimer
{
public:
	~AtkInterval() {}
public:
};


Tactics::Tactics()
{
	Timer::GetInstance()->RegisterTimer(this);

	m_pAtkInterval = new AtkInterval();
}

Tactics::~Tactics()
{
	Timer::GetInstance()->UnregisterTimer(this);

	delete m_pAtkInterval;
}

void Tactics::SetSoldier(Soldier* pSoldier)
{
	m_pSoldier = pSoldier;

	if (pSoldier)
	{
		float fInterval = NumCalculation::AtkInterval(pSoldier->getProperty());
		m_pAtkInterval->SetInterval(fInterval);
	}
}

Soldier* Tactics::GetSoldier()
{
	return m_pSoldier;
}

void Tactics::SetLastAtkSoldier(Soldier* pSoldier)
{
	m_pLastAtkSoldier = pSoldier;
}

Soldier* Tactics::GetLastAtkSoldier()
{
	return m_pLastAtkSoldier;
}

void Tactics::Update(float dt)
{
	if (m_pSoldier->GetHP() <= 0)
	{
		Timer::GetInstance()->UnregisterTimer(this);
		return;
	}
	if (m_pLastAtkSoldier == nullptr || m_pLastAtkSoldier->GetHP() <= 0)  
	{// 查找目标，如果目标死亡，重新查找最近的目标，直到找不到
		Soldier* pSoldier = Agent::GetInstance()->FindNeareast(m_pSoldier);
		if (pSoldier == nullptr)
		{
			return;
		}
		m_pLastAtkSoldier = pSoldier;

		m_pAtkInterval->SetCallback([this](){
			float fAtk = NumCalculation::Attack(m_pSoldier->getProperty(), m_pLastAtkSoldier->getProperty());
			m_pLastAtkSoldier->SetHP(m_pLastAtkSoldier->GetHP() - fAtk);
			printf("Soldier %d Attack Soldier %d, Hurt %f, Remain HP %f\n", m_pSoldier->GetID(), m_pLastAtkSoldier->GetID(), fAtk, m_pLastAtkSoldier->GetHP());
		});
	}

	Vector3 vector = m_pLastAtkSoldier->GetPosition() - m_pSoldier->GetPosition();
	if (vector.Length() >= m_pSoldier->GetRNG())
	{// 攻击距离外，朝目标移动
		Vector3 speed = vector * (dt / m_pSoldier->GetMOV());
		m_pSoldier->SetPosition(m_pSoldier->GetPosition() + speed);

		Vector3 pos = m_pSoldier->GetPosition();
		printf("Soldier ID %d, Position(%f, %f, %f)\n", m_pSoldier->GetID(), pos.x, pos.y, pos.z);
	}
	else
	{
		m_pAtkInterval->Update(dt);
		if (m_pAtkInterval->Finish())
		{
			m_pAtkInterval->Reset();
		}
	}
}
