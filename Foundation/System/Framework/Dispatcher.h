#pragma once

#include "Object.h"
#include "IHandler.h"

#include <map>

namespace sys
{
	// 收到信息后派发和处理
	// 自动释放资源
	template<class T>
	class Dispatcher
	{
	public:
		Dispatcher();
		~Dispatcher();
	public:
		// 添加派发事件
		void addDispatcher(long commandID, T* handler);
		// 移除派发事件
		void removeDispatcher(long commanID);
		// 接收到消息，派发
		bool dispatch(Object* command);
		// 接收到消息，广播
		void broadcast(Object* command);
		// 清空所有派发处理
		void clear();
	private:
		std::map<long, T*> _handlers;
	};

	template<typename T>
	Dispatcher<T>::Dispatcher()
	{

	}

	template<typename T>
	Dispatcher<T>::~Dispatcher()
	{
		this->clear();
	}

	template<typename T>
	void Dispatcher<T>::addDispatcher( long commandID, T* handler )
	{
		if (_handlers[commandID] != nullptr)
		{
			delete _handlers[commandID];
		}

		_handlers[commandID] = handler;
	}

	template<typename T>
	void Dispatcher<T>::removeDispatcher( long commanID )
	{
		if (_handlers.find(commanID) == _handlers.end())
		{
			return;
		}

		delete _handlers[commanID];

		_handlers.erase(commanID);
	}

	template<typename T>
	bool Dispatcher<T>::dispatch( Object* command )
	{
		if (command == nullptr)
		{
			return false;
		}

		command->retain();

		std::map<long, T*>::iterator it = _handlers.find(command->getID());
		if (it != _handlers.end())
		{
			it->second->hand(command);
			command->release();
			return true;
		}

		command->release();
		return false;
	}

	template<typename T>
	void Dispatcher<T>::broadcast( Object* command )
	{
		if (command == nullptr)
		{
			return;
		}

		command->retain();

		for (std::map<long, T*>::iterator it = _handlers.begin();
			it != _handlers.end();
			it++)
		{
			it->second->hand(command);
		}

		command->release();
	}

	template<typename T>
	void Dispatcher<T>::clear()
	{
		std::map<long, T*>::iterator it = _handlers.begin();

		while (it != _handlers.end())
		{
			delete it->second;
			it++;
		}

		_handlers.clear();
	}

}