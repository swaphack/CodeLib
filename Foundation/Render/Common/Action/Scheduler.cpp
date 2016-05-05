#include "Scheduler.h"

using namespace render;

Scheduler::Scheduler()
:_handler(nullptr)
{

}

Scheduler::~Scheduler()
{

}

void Scheduler::update(float interval)
{
	if (_target == nullptr || _handler == nullptr)
	{
		return;
	}

	if (!isRunning())
	{
		return;
	}

	(_target->*_handler)(interval);
}

void Scheduler::setHandler(const ACTION_UPDATE handler)
{
	_handler = handler;
}