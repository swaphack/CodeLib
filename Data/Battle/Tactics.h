#pragma once

#include "ITimer.h"

class Soldier;
class AtkInterval;

// ս������
class Tactics : public ITimer
{
public:
	Tactics();
	virtual ~Tactics();
public:
	// ����ʿ��
	void SetSoldier(Soldier* pSoldier);
	// ��ȡʿ��
	Soldier* GetSoldier();

	// �������������ʿ��
	void SetLastAtkSoldier(Soldier* pSoldier);
	// ��ȡ���������ʿ��
	Soldier* GetLastAtkSoldier();

	// ��д
	virtual void Update(float dt);
private:
	// ��ǰʿ��
	Soldier* m_pSoldier = nullptr;
	// �������
	AtkInterval* m_pAtkInterval = nullptr;

	// ���������ʿ��
	Soldier* m_pLastAtkSoldier = nullptr;
};
