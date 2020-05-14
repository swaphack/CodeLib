#include "Task.h"

using namespace sys;

Task::Task()
{

}

Task::~Task()
{

}

void Task::start()
{

}

void Task::update()
{
	if (_func)
	{
		_func();
	}

	if (_event)
	{
		_event->doEvent();
	}
}

void Task::finish()
{
	_func = nullptr;
	_event = nullptr;
}

bool Task::isOver()
{
	return true;
}

void Task::setTaskFunc(const TaskFunc& func)
{
	_func = func;
}

void Task::setTaskEvent(const ITaskEvent* pEvt)
{
	_event = (ITaskEvent*)pEvt;
}
