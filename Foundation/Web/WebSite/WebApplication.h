#pragma once

#include "system.h"


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
		virtual void init();
		virtual void update();
		virtual void dispose(); 
	protected:
		// 初始化网络
		void initNet();
		// 销毁网络
		void disposeNet();
		// 解析数据
		void parseData(int id, sys::DataQueue& dataQueue);
	private:
		// 解析数据
		virtual	void onParseData(int id, sys::DataQueue& dataQueue);
	protected:
		// 端口
		int _port;
		// ip
		std::string _ip;
		// 最大等待数
		int _maxWaitCount;
		// 服务器
		sys::Server* _server;
	};
}