#include "web.h"
#include "system.h"

using namespace sys;
using namespace web;

namespace gw
{
	// http Ӧ��
	class HttpActivityReceiver : public web::HttpActivity
	{
	protected:
		// ����������
		virtual void doGetRequest(sys::HttpRequest* request);
		virtual void doGetResponse(sys::HttpResponse* response);
	private:
		// �Ƿ���վ������
		bool isHttpServer();
	};
}