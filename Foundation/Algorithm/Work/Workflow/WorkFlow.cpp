#include "WorkFlow.h"

alg::work::WorkFlow::WorkFlow()
{

}

alg::work::WorkFlow::~WorkFlow()
{
	this->removeAllTasks();
}

void alg::work::WorkFlow::addTask(Task* task)
{
	if (task == nullptr)
	{
		return;
	}
	SAFE_RETAIN(task);
	task->setWorkFlow(this);
	_tasks.push_back(task);
}

void alg::work::WorkFlow::removeTask(Task* task)
{
	if (task == nullptr)
	{
		return;
	}
	SAFE_RELEASE(task);
	task->setWorkFlow(nullptr);
	_tasks.remove(task);
}

void alg::work::WorkFlow::removeAllTasks()
{
	for (auto item : _tasks)
	{
		item->setWorkFlow(nullptr);
		SAFE_RELEASE(item);
	}

	_tasks.clear();
}

alg::work::WorkDataMap* alg::work::WorkFlow::getSharedData()
{
	return &_sharedData;
}

void alg::work::WorkFlow::onUpdate(float dt)
{

}

