#include "DataQueue.h"

using namespace sys;


DataQueue::DataQueue()
{
	_datas = std::queue<NetData*>();
}

DataQueue::~DataQueue()
{
	this->dispose();
}

void DataQueue::pushData( NetData* data )
{
	if (data == nullptr)
	{
		return;
	}
	_datas.push(data);
}

NetData* DataQueue::popData()
{
	if (this->empty())
	{
		return nullptr;
	}

	NetData* top = _datas.front();
	_datas.pop();

	return top;
}

NetData* DataQueue::topData()
{
	if (this->empty())
	{
		return nullptr;
	}

	return _datas.front();
}

int DataQueue::count()
{
	return _datas.size();
}

bool DataQueue::empty()
{
	return _datas.empty();
}

void DataQueue::dispose()
{
	while (!_datas.empty())
	{
		NetData* data = this->popData();
		SAFE_DELETE(data);
	}
}
