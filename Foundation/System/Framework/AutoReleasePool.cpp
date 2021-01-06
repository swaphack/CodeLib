#include "AutoReleasePool.h"
#include "Object.h"
#include <vector>
#include <thread>

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

	setCheckState(true);
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
	if (_threadCount != 0)
	{
		return;
	}

	if (!_bCheckPool) return;
	_bCheckPool = false;

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
		(*roIter)->dispose();
		roIter++;
	}
}

void sys::AutoReleasePool::setCheckState(bool checked)
{
	_bCheckPool = checked;
}

void AutoReleasePool::startThread(const std::function<void()>& func)
{
	if (func == nullptr)
	{
		return;
	}

	_threadCount++;
	auto task = std::thread([func, this]() {
		func();
		endThread();
	});

	task.detach();
}

void AutoReleasePool::endThread()
{
	_threadCount--;
}
