#pragma once

#include "system.h"
#include "macros.h"
#include <map>

namespace web
{
	#define WAIT_LISTEN_COUNT 1024

	// web Ӧ�÷�����
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
		// ��ȡӦ��ʵ��
		static WebApplication* getInstance();
		// ��ȡ������
		WebServer* getServer();
		// ��ȡ�ͻ���
		WebClient* getClient();
		// ��ȡ��Դ
		sys::ResourceMgr* getResourceMgr();

		// http ����
		HttpActivityListener* getHttpListener();
		// packet ����
		PacketActivityListener* getPacketListener();

		// ������Ŀ��
		void postResponse(const char* sessionID, sys::NetData* data);
		// Ŀ��id
		void postResponse(int clientID, sys::NetData* data);
		// �㲥
		void postBroadcast(sys::NetData* data);
		// ��ȡsocket ID
		int getSocketID(const char* sessionID);
	public:
		virtual void init();
		virtual void update();
		virtual void dispose(); 
	protected:
		// �������յ�������������
		void parseReceiveServerData(int id, sys::DataQueue& dataQueue);
		// �������յ��ͻ��˵�����
		void parseReceiveClientData(int id, sys::DataQueue& dataQueue);
		// �������յ�������
		void parseReceiveData(int id, sys::DataQueue& dataQueue, int tag);
		// �رտͻ��˴���
		void closeClient(int id);
	protected:
		// �˿�
		int _port;
		// ip
		std::string _ip;
		// ���ȴ���
		int _maxWaitCount;
		// �����
		WebServer* _server;
		// �ͻ���
		WebClient* _client;
		// ��Դ����
		sys::ResourceMgr* _resource;
		// Http����
		int _httpListenerID;
		// ���ļ���
		int _packetListenerID;
		// ������
		ListenerPool* _listenerPool;
		// �ͻ�����Ϣ
		Sessions* _session;
	};
}