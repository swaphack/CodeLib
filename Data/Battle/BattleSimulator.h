#pragma once

class Field;

class BattleSimulator
{
public:
	void Init();
	void Run();
	void SetFPS(int nVal);
private:
	Field* m_pField = nullptr;
	int m_nFPS = 60;
};