#pragma once

#include <set>

class ITimer;

class Timer
{
public:
	static Timer* GetInstance();
public:
	// ע��ʱ���¼�
	void RegisterTimer(ITimer* pTimer);
	// ע��ʱ���¼�
	void UnregisterTimer(ITimer* pTimer);
	// ����ʱ��
	void Update(float dt);
private:
	// �����ӵĶ�ʱ��
	std::set<ITimer*> m_setAddTimer;
	// ���Ƴ��Ķ�ʱ��
	std::set<ITimer*> m_setRemoveTimer;
	// �������еĶ�ʱ��
	std::set<ITimer*> m_setRunningTimer;
};