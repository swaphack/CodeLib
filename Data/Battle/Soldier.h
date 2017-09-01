#pragma once

#include "Unit.h"
#include "Enum.h"
#include "macros.h"
#include "Property.h"
#include "Vector3.h"

class Tactics;
class Effects;

// 士兵
class Soldier : public Unit
{
public:
	Soldier();
	virtual ~Soldier();
public:
	// 队伍编号
	void SetTeamID(int nID);
	int GetTeamID();
	// 战术
	Tactics* getTactics();
	// 位置
	Vector3 GetPosition();
	void SetPosition(const Vector3& pos);
public:// 属性
	ADD_PROPERTY(ATK, ATTRIBUTE::ATK);
	ADD_PROPERTY(DEF, ATTRIBUTE::DEF);
	ADD_PROPERTY(HP, ATTRIBUTE::HP);
	ADD_PROPERTY(RNG, ATTRIBUTE::RNG);
	ADD_PROPERTY(MOV, ATTRIBUTE::MOV);
	ADD_PROPERTY(ITV, ATTRIBUTE::ITV);
private:
	// 队伍编号
	int m_nTeamID = 0;
	// 战术
	Tactics* m_pTactics = nullptr;
	// 特效
	Effects* m_pEffects = nullptr;
	// 位置
	Vector3 m_Position;
};