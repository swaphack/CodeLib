#include "web.h"
#include "system.h"

using namespace sys;
using namespace web;

namespace gw
{
	// http 应答
	class HttpActivityReceiver : public web::HttpActivity
	{
	protected:
		// 接收请求处理
		virtual void doGetRequest(sys::HttpRequest* request);
		virtual void doGetResponse(sys::HttpResponse* response);
	private:
		// 是否网站服务器
		bool isHttpServer();
	};
}