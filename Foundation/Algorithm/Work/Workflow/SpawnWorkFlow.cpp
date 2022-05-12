#include "SpawnWorkFlow.h"
#include "Work/Task/Task.h"

alg::work::SpawnWorkFlow::SpawnWorkFlow()
{
}

alg::work::SpawnWorkFlow::~SpawnWorkFlow()
{
}

void alg::work::SpawnWorkFlow::onUpdate(float dt)
{
	if (_tasks.size() == 0)
	{
		this->finish();
		return;
	}

	std::list<Task*> removeTasks;
	for (auto& item : _tasks)
	{
		item->update(dt);
		if (item->isOver())
		{
			removeTasks.push_back(item);
		}
	}
	for (auto& item : removeTasks)
	{
		removeTask(item);
	}

	if (_tasks.size() == 0)
	{
		this->finish();
	}
}
