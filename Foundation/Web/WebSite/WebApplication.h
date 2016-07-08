#pragma once

#include "system.h"


#include <map>

namespace web
{
	#define WAIT_LISTEN_COUNT 1024

	// web Ӧ��
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
		// ��ʼ������
		void initNet();
		// ��������
		void disposeNet();
		// ��������
		void parseData(int id, sys::DataQueue& dataQueue);
	private:
		// ��������
		virtual	void onParseData(int id, sys::DataQueue& dataQueue);
	protected:
		// �˿�
		int _port;
		// ip
		std::string _ip;
		// ���ȴ���
		int _maxWaitCount;
		// ������
		sys::Server* _server;
	};
}