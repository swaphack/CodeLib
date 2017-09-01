#pragma once
#include <functional>

class ITimer
{
public:
	~ITimer() {}
public:
	virtual void Update(float dt) = 0;
	virtual bool Finish() { return false; }
};

class IIntervalTimer : public ITimer
{
public:
	virtual ~IIntervalTimer() {}
public:
	void SetInterval(float dt);
	float GetInterval();
	void SetCallback(std::function<void()> handler);
	void Reset();

	virtual void Update(float dt);
	virtual bool Finish();
protected:
	// 回调
	std::function<void()> m_pCallback = nullptr;
	// 间隔时间
	float m_fInterval = 0;
	// 当前时间
	float m_fCurTime = 0;
};