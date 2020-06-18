#include "Scheduler.h"

using namespace render;

Scheduler::Scheduler()
{

}

Scheduler::~Scheduler()
{

}

void Scheduler::update(float interval)
{
	if (!isRunning())
	{
		return;
	}
	if (_handler.first != nullptr && _handler.second != nullptr)
	{
		(_handler.first->*_handler.second)(interval);
	}
	
	if (_func)
	{
		_func(interval);
	}
}

void Scheduler::setHandler(Node* target, SCHEDULER_DELEGATE_HANDLER handler)
{
	_handler.first = target;
	_handler.second = handler;
}

void render::Scheduler::setHandler(SCHEDULER_FUNC func)
{
	_func = func;
}
