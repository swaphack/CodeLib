#include "EventCenter.h"
#include "Event.h"

sys::EventCenter::EventCenter()
{
}

sys::EventCenter::~EventCenter()
{
}

void sys::EventCenter::addEventListener(const std::string& name, const Object* target, const EventFunc& func)
{
	if (target == nullptr || func == nullptr)
	{
		return;
	}

	_eventFuncs[name].insert(std::make_pair((Object*)target, func));
}

void sys::EventCenter::removeEventListener(const std::string& name)
{
	for (auto& item : _targetEvents)
	{
		auto it = item.second.find(name);
		if (it != item.second.end())
		{
			item.second.erase(it);
		}
	}

	{
		auto it = _eventFuncs.find(name);
		if (it != _eventFuncs.end())
		{
			_eventFuncs.erase(it);
		}
	}
}

void sys::EventCenter::removeEventListener(const Object* target, const std::string& name)
{
	if (target == nullptr)
	{
		return;
	}

	auto it = _targetEvents.find((Object*)target);
	if (it != _targetEvents.end())
	{
		auto it1 = it->second.find(name);
		if (it1 != it->second.end())
		{
			it->second.erase(it1);
		}
	}

	{
		auto it1 = _eventFuncs.find(name);
		if (it1 != _eventFuncs.end())
		{
			auto it2 = it1->second.find((Object*)target);
			if (it2 != it1->second.end())
			{
				it1->second.erase(it2);
			}
		}
	}
}

void sys::EventCenter::removeEventListener(const Object* target)
{
	auto it = _targetEvents.find((Object*)target);
	if (it != _targetEvents.end())
	{
		for (auto item : it->second)
		{
			auto it1 = _eventFuncs.find(item);
			if (it1 != _eventFuncs.end())
			{
				auto it2 = it1->second.find((Object*)target);
				if (it2 != it1->second.end())
				{
					it1->second.erase(it2);
				}
			}
		}

		_targetEvents.erase(it);
	}
}

void sys::EventCenter::addEventListener(EventProtocol* func)
{
	if (func == nullptr)
	{
		return;
	}

	_eventProtocols.insert(func);
}

void sys::EventCenter::removeEventListener(EventProtocol* func)
{
	if (func == nullptr)
	{
		return;
	}

	_eventProtocols.erase(func);
}

void sys::EventCenter::removeAllEventListeners()
{
	_eventProtocols.clear();
	_eventFuncs.clear();
}

void sys::EventCenter::dispatch(const Event* evt)
{
	if (evt == nullptr)
	{
		return;
	}
	for (auto item : _eventProtocols)
	{
		item->onDispatch(evt);
	}
	std::string name = evt->getName();
	auto it = _eventFuncs.find(name);
	if (it != _eventFuncs.end())
	{
		for (auto& item : it->second)
		{
			item.second(evt);
		}
	}
}
