#pragma once

class Field;
class Soldier;

class Agent
{
public:
	Agent();
	~Agent();
public:
	static Agent* GetInstance();
public:
	// 设置战场
	void SetField(Field* pField);
	// 获取战场
	Field* GetField();
	// 获取距离最近的敌方士兵
	Soldier* FindNeareast(Soldier* pSoldier);
private:
	Field* m_pField = nullptr;
};