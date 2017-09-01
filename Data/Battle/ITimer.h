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
	// �ص�
	std::function<void()> m_pCallback = nullptr;
	// ���ʱ��
	float m_fInterval = 0;
	// ��ǰʱ��
	float m_fCurTime = 0;
};