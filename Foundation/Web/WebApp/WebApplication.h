#pragma once

#include "system.h"
#include "macros.h"
#include "WebServer.h"
#include <map>

namespace web
{
	#define WAIT_LISTEN_COUNT 1024

	// web 应用
	class WebApplication : public sys::Application
	{
	public:
		WebApplication(const char* ip, int port, int maxWaitCount = WAIT_LISTEN_COUNT);
		virtual ~WebApplication();
	public:
		// 获取应用实例
		static WebApplication* getInstance();
		// 获取服务器
		WebServer* getServer();
		// 获取资源
		sys::ResourceMgr* getResourceMgr();
	public:
		virtual void init();
		virtual void update();
		virtual void dispose(); 
	protected:
		// 解析数据
		void parseData(int id, sys::DataQueue& dataQueue);
	protected:
		// 端口
		int _port;
		// ip
		std::string _ip;
		// 最大等待数
		int _maxWaitCount;
		// 服务器
		WebServer* _server;
		// 资源管理
		sys::ResourceMgr* _resource;
	};
}