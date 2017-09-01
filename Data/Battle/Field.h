#pragma once
#include <map>
#include <vector>

class Team;
class Soldier;

class Field
{
public:
	// 添加队伍
	void AddTeam(Team* pTeam);
	// 移除队伍
	void RemoveTeam(Team* pTeam);
	// 查找队伍
	Team* FindTeam(int nTeamID);
	// 获取其他队伍
	std::vector<Team*> GetOtherTeams(int nTeamID);
	// 查找士兵
	Soldier* FindSolider(int nSoldierID);
	// 移除所有队伍
	void RemoveAllTeams();
	// 更新
	void Update(float dt);
protected:
	std::map<int, Team*> m_mapTeam;
};