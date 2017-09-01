#pragma once
#include <map>
#include <vector>

class Team;
class Soldier;

class Field
{
public:
	// ��Ӷ���
	void AddTeam(Team* pTeam);
	// �Ƴ�����
	void RemoveTeam(Team* pTeam);
	// ���Ҷ���
	Team* FindTeam(int nTeamID);
	// ��ȡ��������
	std::vector<Team*> GetOtherTeams(int nTeamID);
	// ����ʿ��
	Soldier* FindSolider(int nSoldierID);
	// �Ƴ����ж���
	void RemoveAllTeams();
	// ����
	void Update(float dt);
protected:
	std::map<int, Team*> m_mapTeam;
};