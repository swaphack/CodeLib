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
	// ����ս��
	void SetField(Field* pField);
	// ��ȡս��
	Field* GetField();
	// ��ȡ��������ĵз�ʿ��
	Soldier* FindNeareast(Soldier* pSoldier);
private:
	Field* m_pField = nullptr;
};