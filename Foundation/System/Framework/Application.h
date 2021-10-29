#pragma once

#include "Object.h"

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
		void checkAutoReleasePool();

		// ���һ��Э�����
		void addProtocolManager(const std::string& protocolName, Object* protocolManager);
		// �Ƴ�һ��Э�����
		void removeProtocolManager(const std::string& protocolName);
		// ��ȡһ��Э�����
		Object* getProtocolManager(const std::string& protocolName);
		// �������Э�����
		void clearProtocolManagers();
		// ��ȡһ��Э�����
		template<typename T>
		T* getProtocolManager(const std::string& protocolName);
		// ��ȡһ��Э�����
		template<typename T>
		T* getProtocolManager();
	private:
		std::map<std::string, Object*> _protocolManagers;
	};

	template<typename T>
	T* Application::getProtocolManager( const std::string& protocolName )
	{
		Object* manager = this->getProtocolManager(protocolName);
		if (manager == nullptr)
		{
			return nullptr;
		}

		return manager->as<T>();
	}

	template<typename T>
	T* Application::getProtocolManager()
	{
		T* t = nullptr;

		std::map<std::string, Object*>::iterator iter = _protocolManagers.begin();

		while (iter != _protocolManagers.end())
		{
			t = iter->second->as<T>();
			if (t != nullptr)
			{
				return t;
			}
			iter++;
		}
		return nullptr;
	}
}