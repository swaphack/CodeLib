#pragma once

#include "Object.h"
#include "../Base/import.h"

#include <map>
#include <string>

namespace sys
{
	// app 接口
	class IApplication
	{
	public:
		// 初始化
		virtual void init() = 0;
		// 定时更新
		virtual void update() = 0;
		// 销毁
		virtual void dispose() = 0;
	};

	// app 接口管理
	class Application : public Object, public IApplication
	{
	public:
		Application();
		virtual ~Application();
	public:
		// 检查自动释放池
		void checkAutoRealsePool();

		// 添加一个协议管理
		void addProtocolManager(const char* protocolName, Object* protocolManager);
		// 移除一个协议管理
		void removeProtocolManager(const char* protocolName);
		// 获取一个协议管理
		Object* getProtocolManager(const char* protocolName);
		// 清除所有协议管理
		void clearProtocolManagers();
		// 获取一个协议管理
		template<typename T>
		T* getProtocolManager(const char* protocolName);
		// 获取一个协议管理
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