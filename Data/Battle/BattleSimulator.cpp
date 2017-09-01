#include "BattleSimulator.h"
#include "Field.h"
#include "Team.h"
#include "Soldier.h"
#include "Random.h"
#include "Timer.h"
#include "Agent.h"
#include <thread>

void BattleSimulator::Init()
{
	if (!m_pField)
	{
		m_pField = new Field();
	}

	m_pField->RemoveAllTeams();

	for (int i = 0; i < 2; i++)
	{
		Team* pTeam = new Team();
		for (int j = 0; j < 5; j++)
		{
			Soldier* pSoldier = new Soldier();
			pSoldier->SetATK(Random::GetInstance()->Next(1, 10));
			pSoldier->SetDEF(Random::GetInstance()->Next(1, 10));
			pSoldier->SetHP(Random::GetInstance()->Next(90, 100));
			pSoldier->SetRNG(Random::GetInstance()->Next(1, 5));
			pSoldier->SetMOV(Random::GetInstance()->Next(1, 2));
			pSoldier->SetITV(Random::GetInstance()->Next(0.78f, 2.5f));
			pSoldier->SetPosition(
				Vector3(Random::GetInstance()->Next(1.0f, 100.0f), 
				Random::GetInstance()->Next(1.0f, 100.0f))
			);
			pTeam->AddSoldier(pSoldier);
		}
		m_pField->AddTeam(pTeam);
	}

	Agent::GetInstance()->SetField(m_pField);
}

void BattleSimulator::Run()
{
	while (true)
	{
		float dt = 1.0f / m_nFPS;
		int milliseconds = dt * 1000;
		std::chrono::milliseconds st(milliseconds);
		std::this_thread::sleep_for(st);
		Timer::GetInstance()->Update(dt);
	}
}

void BattleSimulator::SetFPS(int nVal)
{
	m_nFPS = nVal;
}

