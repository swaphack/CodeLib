#pragma once

#include "Unit.h"
#include "Enum.h"
#include "macros.h"
#include "Property.h"
#include "Vector3.h"

class Tactics;
class Effects;

// ʿ��
class Soldier : public Unit
{
public:
	Soldier();
	virtual ~Soldier();
public:
	// ������
	void SetTeamID(int nID);
	int GetTeamID();
	// ս��
	Tactics* getTactics();
	// λ��
	Vector3 GetPosition();
	void SetPosition(const Vector3& pos);
public:// ����
	ADD_PROPERTY(ATK, ATTRIBUTE::ATK);
	ADD_PROPERTY(DEF, ATTRIBUTE::DEF);
	ADD_PROPERTY(HP, ATTRIBUTE::HP);
	ADD_PROPERTY(RNG, ATTRIBUTE::RNG);
	ADD_PROPERTY(MOV, ATTRIBUTE::MOV);
	ADD_PROPERTY(ITV, ATTRIBUTE::ITV);
private:
	// ������
	int m_nTeamID = 0;
	// ս��
	Tactics* m_pTactics = nullptr;
	// ��Ч
	Effects* m_pEffects = nullptr;
	// λ��
	Vector3 m_Position;
};