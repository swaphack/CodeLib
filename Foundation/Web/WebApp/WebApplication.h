#pragma once

#include "system.h"
#include "macros.h"
#include <map>

namespace web
{
	#define WAIT_LISTEN_COUNT 1024

	// web 应用服务器
	class WebApplication : public sys::Application
	{
	protected:
		enum SockType
		{
			EST_SERVER,
			EST_CLIENT,
		};
	public:
		WebApplication(const char* ip, int port, int maxWaitCount = WAIT_LISTEN_COUNT);
		virtual ~WebApplication();
	public:
		// 获取应用实例
		static WebApplication* getInstance();
		// 获取服务器
		WebServer* getServer();
		// 获取客户端
		WebClient* getClient();
		// 获取资源
		sys::ResourceMgr* getResourceMgr();

		// http 监听
		HttpActivityListener* getHttpListener();
		// packet 监听
		PacketActivityListener* getPacketListener();

		// 反馈给目标
		void postResponse(const char* sessionID, sys::NetData* data);
		// 目标id
		void postResponse(int clientID, sys::NetData* data);
		// 广播
		void postBroadcast(sys::NetData* data);
		// 获取socket ID
		int getSocketID(const char* sessionID);
	public:
		virtual void init();
		virtual void update();
		virtual void dispose(); 
	protected:
		// 解析接收到服务器的数据
		void parseReceiveServerData(int id, sys::DataQueue& dataQueue);
		// 解析接收到客户端的数据
		void parseReceiveClientData(int id, sys::DataQueue& dataQueue);
		// 解析接收到的数据
		void parseReceiveData(int id, sys::DataQueue& dataQueue, int tag);
		// 关闭客户端处理
		void closeClient(int id);
	protected:
		// 端口
		int _port;
		// ip
		std::string _ip;
		// 最大等待数
		int _maxWaitCount;
		// 服务端
		WebServer* _server;
		// 客户端
		WebClient* _client;
		// 资源管理
		sys::ResourceMgr* _resource;
		// Http监听
		int _httpListenerID;
		// 报文监听
		int _packetListenerID;
		// 监听池
		ListenerPool* _listenerPool;
		// 客户端信息
		Sessions* _session;
	};
}