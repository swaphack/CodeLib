#include "WorkFlow.h"
#include "Task.h"
using namespace sys;

WorkFlow::WorkFlow()
{

}

WorkFlow::~WorkFlow()
{
	this->removeAllTasks();
}

void WorkFlow::addTask(Task* task)
{
	if (task == nullptr)
	{
		return;
	}
	SAFE_RETAIN(task);
	_tasks.push_back(task);
}

void WorkFlow::removeTask(Task* task)
{
	if (task == nullptr)
	{
		return;
	}
	SAFE_RELEASE(task);

	auto it = std::find(_tasks.begin(), _tasks.end(), task);
	if (it != _tasks.end())
	{
		_tasks.erase(it);
	}
}

void WorkFlow::removeAllTasks()
{
	for (auto item : _tasks)
	{
		SAFE_RELEASE(item);
	}

	_tasks.clear();
}

void WorkFlow::update()
{

}

