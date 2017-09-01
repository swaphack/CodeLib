#include "Agent.h"
#include "Field.h"
#include "Soldier.h"
#include "Team.h"

static Agent* s_pInstance = nullptr;

Agent::Agent()
{

}

Agent::~Agent()
{

}

Agent* Agent::GetInstance()
{
	if (s_pInstance == nullptr)
	{
		s_pInstance = new Agent();
	}

	return s_pInstance;
}

void Agent::SetField(Field* pField)
{
	m_pField = pField;
}

Field* Agent::GetField()
{
	return m_pField;
}

Soldier* Agent::FindNeareast(Soldier* pSoldier)
{
	if (pSoldier == nullptr || m_pField == nullptr)
	{
		return nullptr;
	}

	std::vector<Team*> otherTeams = m_pField->GetOtherTeams(pSoldier->GetTeamID());
	if (otherTeams.size() == 0)
	{
		return nullptr;
	}

	float fLastRNG = -1;
	Soldier* pLastSoldier = 0;

	for (unsigned int i = 0; i < otherTeams.size(); i++)
	{
		const std::map<int, Soldier*>& soldiers = otherTeams[i]->GetSoldiers();

		for (std::map<int, Soldier*>::const_iterator cit = soldiers.begin();
			cit != soldiers.end();
			cit++)
		{
			if (cit->second->GetHP() <= 0)
			{
				continue;
			}
			float dist = pSoldier->GetPosition().Distance(cit->second->GetPosition());
			if (fLastRNG == -1 || dist < fLastRNG)
			{
				fLastRNG = dist;
				pLastSoldier = cit->second;
			}
		}
	}

	return pLastSoldier;
}
