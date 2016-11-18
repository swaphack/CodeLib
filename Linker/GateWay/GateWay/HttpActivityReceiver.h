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
		virtual void doGet(sys::HttpRequest* request);
		// http 请求
		virtual void doHttpGet(sys::HttpRequest* request);
	private:
		// 获取请求的页面
		void handUrlMethod(sys::String& inString, std::string& outString);
		// 获取上传的参数
		// for url get param(?xx=xx)
		void handGetParamMethod(sys::String& inString, std::map<std::string, std::string>& outParams);
		// for url get param(?xx=xx)
		void handPostParamMethod(sys::String& inString, std::map<std::string, std::string>& outParams);
	};
}