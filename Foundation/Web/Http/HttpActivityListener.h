#pragma once

#include "system.h"

#include "HttpRecvHandler.h"

#include "Listener/IActivityListener.h"

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
		void addRecvHandler(sys::Object* target, HTTP_RECV_REQUEST_HANDLER handler);
		// �Ƴ��������ݴ���
		void removeRecvHandler(sys::Object* target, HTTP_RECV_REQUEST_HANDLER handler);

		// ��ӽ������ݴ���
		void addRecvHandler(sys::Object* target, HTTP_RECV_RESPONE_HANDLER handler);
		// �Ƴ��������ݴ���
		void removeRecvHandler(sys::Object* target, HTTP_RECV_RESPONE_HANDLER handler);

		virtual bool onDispatch(const std::string& sessionID, sys::DataQueue& dataQueue, int& packetSize);
	protected:
		// ����������
		void onRecvHander(sys::HttpRequest* data);
		// ����������
		void onRecvHander(sys::HttpResponse* data);
		// �ӽ��յ������д���http���󣬲���ɾ������ɵ�����
		sys::HttpRequest* createRequest(const std::string& sessionID, sys::DataQueue& dataQueue, int& packetSize);
		// �ӽ��յ������д���http���󣬲���ɾ������ɵ�����
		sys::HttpResponse* createResponse(const std::string& sessionID, sys::DataQueue& dataQueue, int& packetSize);
	private:
		// ����http������
		std::vector<HttpRecvRequestHandler> _recvRequestHandlers;
		// ����http��������
		std::vector<HttpRecvResponseHandler> _recvResponseHandlers;
		// http��������ĵ�
		sys::HttpReqDocument* _httpReqDoc;
		// http���������ĵ�
		sys::HttpRespDocument* _httpRespDoc;
	};
}