#include "SequenceWorkFlow.h"
#include "Work/Task/Task.h"

alg::work::SequenceWorkFlow::SequenceWorkFlow()
{
}

alg::work::SequenceWorkFlow::~SequenceWorkFlow()
{
}

void alg::work::SequenceWorkFlow::onUpdate(float dt)
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
			removeTask(front);
		}
	}

	if (_tasks.size() == 0)
	{
		this->finish();
	}
}
