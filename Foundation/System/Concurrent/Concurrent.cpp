#include "Concurrent.h"
#include "Thread/Thread.h"
#include "Base/macros.h"

using namespace sys;

Concurrent::Concurrent()
	:_readFunc(nullptr)
	, _writeFunc(nullptr)
	, _bRunning(false)
{
	this->init();
}

Concurrent::~Concurrent()
{
}

bool Concurrent::read(char* data, int offset, int size, ReadDataCallback callback)
{
	if (data == nullptr || offset < 0)
	{
		return false;
	}
	_mutex.lock("Begin Concurrent::Read Data\n");
	_eventQueue.push(new ReadData(data, offset, size, callback));
	_mutex.unlock("End Concurrent::Read Data\n");

	return true;
}

bool Concurrent::write(const char* data, int size)
{
	if (data == nullptr || size <= 0)
	{
		return false;
	}
	_mutex.lock("Begin Concurrent::Write Data\n");
	_eventQueue.push(new WriteData(data, size));
	_mutex.unlock("End Concurrent::Write Data\n");

	return true;
}

void Concurrent::finish()
{
	_mutex.lock();
	_eventQueue.push(new FinishData());
	_mutex.unlock();

	return;
}

void Concurrent::setReadFunc(ReadFunc func)
{
	_readFunc = func;
}

void Concurrent::setWriteFunc(WriteFunc func)
{
	_writeFunc = func;
}

bool Concurrent::isSetReadFunc()
{
	return _readFunc != nullptr;
}

bool Concurrent::isSetWriteFunc()
{
	return _writeFunc != nullptr;
}

void Concurrent::init()
{
	Thread th;
	th.start([this](){
		bool bRet = true;
		while (bRet)
		{	
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			if (!_mutex.tryLock("Begin Concurrent::Try Parser Data\n"))
			{
				continue;
			}

			if (_eventQueue.empty())
			{
				_mutex.unlock("End Concurrent::Try Parser Data Because Of Empty\n");
				continue;
			}

			Data* data = _eventQueue.front();
			if (data->type == EET_READ)
			{
				if (_readFunc)
				{
					ReadData* target = (ReadData*)data;
					_readFunc(target);
					target->callback(target->data, target->size);
				}
			}
			else if (data->type == EET_WRITE)
			{
				if (_writeFunc)
				{
					_writeFunc((WriteData*)data);
				}
			}
			else if (data->type == EET_FINISH)
			{
				bRet = false;
			}
			_eventQueue.pop();
			delete data;
			_mutex.unlock("End Concurrent::Try Parser Data\n");
		}
	});
	th.detach();
}
