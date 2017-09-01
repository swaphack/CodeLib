#pragma once

#include <map>
#include "Unit.h"

class Soldier;

class Team :public Unit
{
public:
	// ���ʿ��
	void AddSoldier(Soldier* pSoldier);
	// �Ƴ�ʿ��
	void RemoveSoldier(Soldier* pSoldier);
	// �Ƴ�����ʿ��
	void RemoveAllSoldiers();
	// ����ʿ��
	Soldier* FindSoldier(int nID);

	const std::map<int, Soldier*>& GetSoldiers();
private:
	std::map<int, Soldier*> m_mapSoldier;
};