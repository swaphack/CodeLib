#include "Concurrents.h"
#include "Concurrent.h"

using namespace sys;

Concurrents::Concurrents()
{

}

Concurrents::~Concurrents()
{
	this->removeAllConcurrents();
}

void Concurrents::addConcurrent(Concurrent* task)
{
	if (task == nullptr)
	{
		return;
	}

	this->removeConcurrent(task);

	_set.insert(task);
}

void Concurrents::removeConcurrent(Concurrent* task)
{
	if (task == nullptr)
	{
		return;
	}

	auto it = _set.find(task);
	if (it != _set.end())
	{
		(*it)->finish();
		_set.erase(it);
	}
}

void Concurrents::removeAllConcurrents()
{
	for (auto item : _set)
	{
		item->finish();
	}

	_set.clear();
}
