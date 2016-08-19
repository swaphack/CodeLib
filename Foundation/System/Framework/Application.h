#pragma once

#include "Object.h"
#include "../Base/import.h"

#include <map>
#include <string>

namespace sys
{
	// app �ӿ�
	class IApplication
	{
	public:
		// ��ʼ��
		virtual void init() = 0;
		// ��ʱ����
		virtual void update() = 0;
		// ����
		virtual void dispose() = 0;
	};

	// app �ӿڹ���
	class Application : public Object, public IApplication
	{
	public:
		Application();
		virtual ~Application();
	public:
		// ����Զ��ͷų�
		void checkAutoRealsePool();

		// ���һ��Э�����
		void addProtocolManager(const char* protocolName, Object* protocolManager);
		// �Ƴ�һ��Э�����
		void removeProtocolManager(const char* protocolName);
		// ��ȡһ��Э�����
		Object* getProtocolManager(const char* protocolName);
		// �������Э�����
		void clearProtocolManagers();
		// ��ȡһ��Э�����
		template<typename T>
		T* getProtocolManager(const char* protocolName);
		// ��ȡһ��Э�����
		template<typename T>
		T* getProtocolManager();
	private:
		std::map<std::string, Object*> _protocolManagers;
	};

	template<typename T>
	T* Application::getProtocolManager( const char* protocolName )
	{
		Object* manager = this->getProtocolManager(protocolName);
		if (manager == nullptr)
		{
			return nullptr;
		}

		return dynamic_cast<T*>(manager);
	}

	template<typename T>
	T* Application::getProtocolManager()
	{
		T* t = nullptr;

		std::map<std::string, Object*>::iterator iter = _protocolManagers.begin();

		while (iter != _protocolManagers.end())
		{
			t = dynamic_cast<T*>(iter->second);
			if (t != nullptr)
			{
				return t;
			}
			iter++;
		}
		return nullptr;
	}
}