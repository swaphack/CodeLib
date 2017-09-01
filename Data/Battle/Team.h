#pragma once

#include <map>
#include "Unit.h"

class Soldier;

class Team :public Unit
{
public:
	// 添加士兵
	void AddSoldier(Soldier* pSoldier);
	// 移除士兵
	void RemoveSoldier(Soldier* pSoldier);
	// 移除所有士兵
	void RemoveAllSoldiers();
	// 查找士兵
	Soldier* FindSoldier(int nID);

	const std::map<int, Soldier*>& GetSoldiers();
private:
	std::map<int, Soldier*> m_mapSoldier;
};