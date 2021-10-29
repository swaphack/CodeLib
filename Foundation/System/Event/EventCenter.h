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
	*	�¼�����
	*/
	class EventCenter
	{
	public:
		EventCenter();
		virtual ~EventCenter();
	public:
		/**
		*	����¼�����
		*/
		void addEventListener(const std::string& name, const Object* target, const EventFunc& func);
		/**
		*	�Ƴ��¼�����
		*/
		void removeEventListener(const std::string& name);
		/**
		*	�Ƴ��¼�����
		*/
		void removeEventListener(const Object* target, const std::string& name);
		/**
		*	�Ƴ��¼�����
		*/
		void removeEventListener(const Object* target);
	public:
		/**
		*	����¼�����
		*/
		void addEventListener(EventProtocol* func);
		/**
		*	�Ƴ��¼�����
		*/
		void removeEventListener(EventProtocol* func);
	public:
		/**
		*	�Ƴ������¼�����
		*/
		void removeAllEventListeners();
	public:
		/**
		*	�ɷ��¼�
		*/
		void dispatch(const Event* evt) const;
	private:
		// �¼��ӿ�
		std::set<EventProtocol*> _eventProtocols;
		// �¼�
		std::map<std::string, std::map<Object*, EventFunc>> _eventFuncs;
		// �����¼�
		std::map<Object*, std::set<std::string>> _targetEvents;
	};
}
