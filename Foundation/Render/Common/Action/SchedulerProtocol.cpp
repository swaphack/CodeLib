#include "SchedulerProtocol.h"
#include "Common/Action/Scheduler.h"

render::SchedulerProtocol::SchedulerProtocol()
{
	_scheduler = CREATE_OBJECT(Scheduler);
	SAFE_RETAIN(_scheduler);
}

render::SchedulerProtocol::~SchedulerProtocol()
{
	this->unscheduleUpdate();
	SAFE_RELEASE(_scheduler);
}

void render::SchedulerProtocol::start()
{
	this->scheduleUpdate();
}

void render::SchedulerProtocol::pause()
{
	if (_scheduler)
	{
		_scheduler->pause();
	}
}

void render::SchedulerProtocol::resume()
{
	if (_scheduler)
	{
		_scheduler->resume();
	}
}

void render::SchedulerProtocol::stop()
{
	this->unscheduleUpdate();
}

render::Scheduler* render::SchedulerProtocol::getScheduler() const
{
	return _scheduler;
}

void render::SchedulerProtocol::scheduleUpdate()
{
}

void render::SchedulerProtocol::unscheduleUpdate()
{
}

