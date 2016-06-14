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

void DataQueue::push( NetData* data )
{
	if (data == nullptr)
	{
		return;
	}
	_datas.push(data);
}

NetData* DataQueue::pop()
{
	if (this->empty())
	{
		return nullptr;
	}

	NetData* top = _datas.front();
	_datas.pop();

	return top;
}

NetData* DataQueue::top()
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
		NetData* data = this->pop();
		SAFE_DELETE(data);
	}
}
