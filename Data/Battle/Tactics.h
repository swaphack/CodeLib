#pragma once

#include "ITimer.h"

class Soldier;
class AtkInterval;

// 战斗策略
class Tactics : public ITimer
{
public:
	Tactics();
	virtual ~Tactics();
public:
	// 设置士兵
	void SetSoldier(Soldier* pSoldier);
	// 获取士兵
	Soldier* GetSoldier();

	// 设置最近攻击的士兵
	void SetLastAtkSoldier(Soldier* pSoldier);
	// 获取最近攻击的士兵
	Soldier* GetLastAtkSoldier();

	// 重写
	virtual void Update(float dt);
private:
	// 当前士兵
	Soldier* m_pSoldier = nullptr;
	// 攻击间隔
	AtkInterval* m_pAtkInterval = nullptr;

	// 最近攻击的士兵
	Soldier* m_pLastAtkSoldier = nullptr;
};
