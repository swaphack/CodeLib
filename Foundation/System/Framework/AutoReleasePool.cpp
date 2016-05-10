#include "AutoReleasePool.h"

#include <vector>

using namespace sys;


AutoReleasePool::AutoReleasePool()
{

}

AutoReleasePool::~AutoReleasePool()
{

}

void AutoReleasePool::addObject( Object* object )
{
	if (object == nullptr)
	{
		return;
	}

	_objects.insert(object);
}

void AutoReleasePool::removeObject( Object* object )
{
	std::set<Object*>::iterator it = _objects.find(object);

	if (it != _objects.end())
	{
		_objects.erase(it);
	}
}

void AutoReleasePool::clear()
{
	_objects.clear();
}

void AutoReleasePool::checkAutoRelease()
{
	std::vector<Object*> removeObjects;

	std::set<Object*>::iterator it = _objects.begin();

	while (it != _objects.end())
	{
		if ((*it)->RetainCount == 1)
		{
			removeObjects.push_back((*it));
		}
		it++;
	}

	std::vector<Object*>::iterator roIter = removeObjects.begin();

	while (roIter != removeObjects.end())
	{
		(*roIter)->disponse();
		roIter++;
	}
}