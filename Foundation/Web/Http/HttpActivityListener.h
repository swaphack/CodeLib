#pragma once

#include "system.h"

#include "HttpRecvHandler.h"

#include "../Listener/IActivityListener.h"

namespace web
{
	// http����
	class HttpActivityListener : public IActivityListener
	{
	public:
		HttpActivityListener();
		virtual ~HttpActivityListener();
	public:
		// ��ӽ������ݴ���
		void addRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler);
		// �Ƴ��������ݴ���
		void removeRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler);

		virtual bool onDispatch(const char* sessionID, sys::DataQueue& dataQueue, int& packetSize);
	protected:
		// ����������
		void onRecvHander(sys::HttpRequest* data);
		// �ӽ��յ������д���http���󣬲���ɾ������ɵ�����
		sys::HttpRequest* createRequest(const char* sessionID, sys::DataQueue& dataQueue, int& packetSize);
		// ��http����ת����������
		sys::NetData* createResponseData(sys::HttpResponse* response);
	private:
		// http���ܴ���
		std::vector<HttpRecvHandler> _recvHandlers;
		sys::HttpReqDocument* _httpReqDoc;
	};
}