#include "Soldier.h"
#include "Tactics.h"
#include "Effects.h"

Soldier::Soldier()
{
	m_pTactics = new Tactics();
	m_pTactics->SetSoldier(this);

	m_pEffects = new Effects();
}

Soldier::~Soldier()
{
	delete m_pTactics;
	delete m_pEffects;
}

Tactics* Soldier::getTactics()
{
	return m_pTactics;
}

void Soldier::SetTeamID(int nID)
{
	m_nTeamID = nID;
}

int Soldier::GetTeamID()
{
	return m_nTeamID;
}

Vector3 Soldier::GetPosition()
{
	return m_Position;
}

void Soldier::SetPosition(const Vector3& pos)
{
	m_Position = pos;
}
