#include "Notify.h"
using namespace render;

Notify::Notify()
{

}

Notify::~Notify()
{

}

void Notify::addListen(int k, NotifyDelegate handler)
{
	if (handler == nullptr)
	{
		return;
	}

	_notifyEvent[k].push_back(handler);
}

void Notify::addMark(int k)
{
	_notifyMark.insert(k);
}

void Notify::notify()
{
	if (_notifyMark.size() == 0)
	{
		return;
	}

	std::set<int>::const_iterator citer = _notifyMark.begin();

	while (citer != _notifyMark.end())
	{
		notify(*citer);
		
		citer++;
	}

	_notifyMark.clear();
}

void Notify::notify(int k)
{
	if (_notifyEvent.find(k) == _notifyEvent.end())
	{
		return;
	}

	std::vector<NotifyDelegate>::iterator iter = _notifyEvent[k].begin();
	while (iter != _notifyEvent[k].end())
	{
		(*iter)();
		iter++;
	}
}

void Notify::clear()
{
	_notifyEvent.clear();
	_notifyMark.clear();
}