#pragma once

#include <string>
#include <map>
#include <set>
#include "Base/Tuple.h"
#include "EventProtocol.h"

namespace sys
{
	class Object;
	class EventProtocol;
	/**
	*	事件中心
	*/
	class EventCenter
	{
	public:
		EventCenter();
		virtual ~EventCenter();
	public:
		/**
		*	添加事件监听
		*/
		void addEventListener(const std::string& name, const Object* target, const EventFunc& func);
		/**
		*	移除事件监听
		*/
		void removeEventListener(const std::string& name);
		/**
		*	移除事件监听
		*/
		void removeEventListener(const Object* target, const std::string& name);
		/**
		*	移除事件监听
		*/
		void removeEventListener(const Object* target);
	public:
		/**
		*	添加事件监听
		*/
		void addEventListener(EventProtocol* func);
		/**
		*	移除事件监听
		*/
		void removeEventListener(EventProtocol* func);
	public:
		/**
		*	移除所有事件监听
		*/
		void removeAllEventListeners();
	public:
		/**
		*	派发事件
		*/
		void dispatch(const Event* evt) const;
	private:
		// 事件接口
		std::set<EventProtocol*> _eventProtocols;
		// 事件
		std::map<std::string, std::map<Object*, EventFunc>> _eventFuncs;
		// 对象事件
		std::map<Object*, std::set<std::string>> _targetEvents;
	};
}
