#pragma once

#include "IActivityListener.h"

#include <map>

namespace web
{
	// 监听池
	class ListenerPool
	{
	public:
		ListenerPool();
		~ListenerPool();
	public:
		// 添加一个监听
		int addListener(IActivityListener* listener);		
		// 获取一个监听
		IActivityListener* getListener(int id);
		// 清除所有监听
		void clear();
		// 派发
		virtual bool onDispatch(const char* sessionID, sys::DataQueue& dataQueue);
	private:
		// 监听器
		std::map<int, IActivityListener*> _listeners;
		// 递增id
		int _increaseID;
	};
}