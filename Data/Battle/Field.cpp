#include "Field.h"
#include "Team.h"
#include "Soldier.h"

void Field::AddTeam(Team* pTeam)
{
	if (pTeam == nullptr)
	{
		return;
	}

	if (pTeam->GetID() == 0)
	{
		return;
	}

	if (m_mapTeam.find(pTeam->GetID()) != m_mapTeam.end())
	{
		return;
	}

	m_mapTeam[pTeam->GetID()] = pTeam;
	pTeam->retain();
}

void Field::RemoveTeam(Team* pTeam)
{
	if (pTeam == nullptr || pTeam->GetID() == 0)
	{
		return;
	}

	if (m_mapTeam.find(pTeam->GetID()) == m_mapTeam.end())
	{
		return;
	}

	m_mapTeam.erase(pTeam->GetID());
	pTeam->release();
}

Team* Field::FindTeam(int nTeamID)
{
	if (m_mapTeam.find(nTeamID) != m_mapTeam.end())
	{
		return m_mapTeam[nTeamID];
	}

	return nullptr;
}

std::vector<Team*> Field::GetOtherTeams(int nTeamID)
{
	std::vector<Team*> vecTeam;

	for (std::map<int, Team*>::iterator it = m_mapTeam.begin();
		it != m_mapTeam.end();
		it++)
	{
		if (it->first != nTeamID)
		{
			vecTeam.push_back(it->second);
		}
	}

	return vecTeam;
}

Soldier* Field::FindSolider(int nSoldierID)
{
	for (std::map<int, Team*>::iterator it = m_mapTeam.begin();
		it != m_mapTeam.end();
		it++)
	{
		Soldier* pSoldier = it->second->FindSoldier(nSoldierID);
		if (pSoldier)
		{
			return pSoldier;
		}
	}

	return nullptr;
}

void Field::RemoveAllTeams()
{
	for (std::map<int, Team*>::iterator it = m_mapTeam.begin();
		it != m_mapTeam.end();
		it++)
	{
		it->second->release();
	}

	m_mapTeam.clear();
}

void Field::Update(float dt)
{
}

