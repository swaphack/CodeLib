#include "ListenerPool.h"

using namespace web;


ListenerPool::ListenerPool()
:_increaseID(0)
{
}

ListenerPool::~ListenerPool()
{
	this->clear();
}

int ListenerPool::addListener(IActivityListener* listener)
{
	if (listener == nullptr)
	{
		return -1;
	}

	int id = ++_increaseID;

	_listeners[id] = listener;

	return id;
}

IActivityListener* ListenerPool::getListener(int id)
{
	std::map<int, IActivityListener*>::iterator iter = _listeners.find(id);

	if (iter != _listeners.end())
	{
		return iter->second;
	}

	return nullptr;
}

void ListenerPool::clear()
{
	std::map<int, IActivityListener*>::iterator iter = _listeners.begin();

	while (iter != _listeners.end())
	{
		delete iter->second;
		iter++;
	}

	_listeners.clear();
}

bool ListenerPool::onDispatch(const std::string& sessionID, sys::DataQueue& dataQueue)
{
	std::map<int, IActivityListener*>::iterator iter = _listeners.begin();

	bool bRet = false;
	int size = 0;

	while (iter != _listeners.end())
	{
		if (iter->second->onDispatch(sessionID, dataQueue, size))
		{
			bRet = true;
			break;
		}
		iter++;
	}

	if (bRet)
	{
		sys::NetData* netData = dataQueue.topData();

		int cursor = netData->pos + size;
		if (cursor == netData->getSize())
		{// 刚好解析完毕
			delete netData;
			dataQueue.popData();
		}
		else
		{
			if (dataQueue.count() > 1)
			{// 保留到下一条数据
				dataQueue.popData();
				sys::NetData* nextData = dataQueue.topData();
				nextData->insert(netData->getCursorPtr(), netData->getRemainSize());
				delete netData;
			}
			else
			{
				netData->pos += size;
			}
		}
	}
	else if (dataQueue.count() > 1)
	{
		sys::NetData* netData = dataQueue.popData();
		dataQueue.topData()->insert(netData->getPtr(), netData->getSize());
		delete netData;
	}

	return bRet;
}