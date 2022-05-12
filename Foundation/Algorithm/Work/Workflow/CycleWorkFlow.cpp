#include "CycleWorkFlow.h"
#include "Work/Task/Task.h"

alg::work::CycleWorkFlow::CycleWorkFlow()
{
}

alg::work::CycleWorkFlow::~CycleWorkFlow()
{
}

void alg::work::CycleWorkFlow::onUpdate(float dt)
{
	if (_tasks.size() == 0)
	{
		this->finish();
		return;
	}

	auto front = _tasks.front();
	if (front)
	{
		front->update(dt);
		if (front->isOver())
		{
			front->reset();
			removeTask(front);
			addTask(front);
		}
	}
	if (_tasks.size() == 0)
	{
		this->finish();
	}
}
