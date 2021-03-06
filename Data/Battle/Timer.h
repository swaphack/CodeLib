#pragma once

#include <set>

class ITimer;

class Timer
{
public:
	static Timer* GetInstance();
public:
	// 注册时间事件
	void RegisterTimer(ITimer* pTimer);
	// 注销时间事件
	void UnregisterTimer(ITimer* pTimer);
	// 更新时间
	void Update(float dt);
private:
	// 待增加的定时器
	std::set<ITimer*> m_setAddTimer;
	// 待移除的定时器
	std::set<ITimer*> m_setRemoveTimer;
	// 正在运行的定时器
	std::set<ITimer*> m_setRunningTimer;
};