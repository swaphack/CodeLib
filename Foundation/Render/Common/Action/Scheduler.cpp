#include "Scheduler.h"

using namespace render;

Scheduler::Scheduler()
{

}

Scheduler::~Scheduler()
{

}

Scheduler* render::Scheduler::createOnce(float delayTime, const SCHEDULER_FUNC& func)
{
	Scheduler* pScheduler = CREATE_OBJECT(Scheduler);
	pScheduler->setDelayTime(delayTime);
	pScheduler->setHandler(func);
	return pScheduler;
}

Scheduler* render::Scheduler::createSchedule(float delayTime, float totalTime, float intervalTime, const SCHEDULER_FUNC& func)
{
	Scheduler* pScheduler = CREATE_OBJECT(Scheduler);
	pScheduler->setDelayTime(delayTime);
	pScheduler->setTotalTime(totalTime);
	pScheduler->setIntervalTime(intervalTime);
	pScheduler->setHandler(func);
	return pScheduler;
}

Scheduler* render::Scheduler::createForever(float delayTime, float intervalTime, const SCHEDULER_FUNC& func)
{
	Scheduler* pScheduler = CREATE_OBJECT(Scheduler);
	pScheduler->setDelayTime(delayTime);
	pScheduler->setTotalTime(-1);
	pScheduler->setIntervalTime(intervalTime);
	pScheduler->setHandler(func);
	return pScheduler;
}

void Scheduler::update(float interval)
{
	if (!isRunning())
	{
		return;
	}
	float lastTime = _currentTime;
	_currentTime += interval;
	if (_delayTime > 0)
	{
		if (_currentTime < _delayTime)
		{
			return;
		}
	}

	if (_totalTime > 0)
	{
		if (_currentTime > _delayTime + _totalTime)
		{
			this->stop();
			return;
		}
	}
	if (_intervalTime > 0)
	{
		int a = (lastTime - _delayTime) / _intervalTime;
		int b = (_currentTime - _delayTime) / _intervalTime;
		if (b == a)
		{
			return;
		}
	}

	if (_handler.first != nullptr && _handler.second != nullptr)
	{
		(_handler.first->*_handler.second)(interval);
	}
	
	if (_func)
	{
		_func(interval);
	}

	if (_totalTime == 0)
	{
		this->stop();
	}
}

void Scheduler::setHandler(Node* target, SCHEDULER_DELEGATE_HANDLER handler)
{
	_handler = std::make_pair(target, handler);
}

void render::Scheduler::setHandler(const SCHEDULER_FUNC& func)
{
	_func = func;
}

void render::Scheduler::setDelayTime(float time)
{
	_delayTime = time;
}

void render::Scheduler::setIntervalTime(float time)
{
	_intervalTime = time;
}

void render::Scheduler::setTotalTime(float time)
{
	_totalTime = time;
}
