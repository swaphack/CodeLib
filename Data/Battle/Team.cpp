#include "Team.h"
#include "Soldier.h"

void Team::AddSoldier(Soldier* pSoldier)
{
	if (pSoldier == nullptr || pSoldier->GetID() == 0)
	{
		return;
	}

	if (pSoldier->GetTeamID() != 0)
	{
		return;
	}

	if (m_mapSoldier.find(pSoldier->GetID()) != m_mapSoldier.end())
	{
		return;
	}
	
	m_mapSoldier[pSoldier->GetID()] = pSoldier;
	pSoldier->SetTeamID(this->GetID());

	pSoldier->retain();
}

void Team::RemoveSoldier(Soldier* pSoldier)
{
	if (pSoldier == nullptr || pSoldier->GetID() == 0)
	{
		return;
	}

	if (pSoldier->GetTeamID() == 0)
	{
		return;
	}

	if (m_mapSoldier.find(pSoldier->GetID()) == m_mapSoldier.end())
	{
		return;
	}

	m_mapSoldier.erase(pSoldier->GetID());
	pSoldier->release();
}

void Team::RemoveAllSoldiers()
{
	for (std::map<int, Soldier*>::iterator it = m_mapSoldier.begin();
		it != m_mapSoldier.end();
		it ++)
	{
		it->second->release();
	}

	m_mapSoldier.clear();
}

Soldier* Team::FindSoldier(int nID)
{
	if (m_mapSoldier.find(nID) != m_mapSoldier.end())
	{
		return m_mapSoldier[nID];
	}

	return nullptr;
}

const std::map<int, Soldier*>& Team::GetSoldiers()
{
	return m_mapSoldier;
}
