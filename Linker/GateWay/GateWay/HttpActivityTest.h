#include "web.h"
#include "system.h"

using namespace sys;
using namespace web;

// http 应答
class HttpActivityTest : public web::HttpActivity
{
protected:
	// 接收请求处理
	virtual void doGet(sys::HttpRequest* request);
	// http 请求
	virtual void doHttpGet(sys::HttpRequest* request);
	// socket 请求
	virtual void doSocketGet(sys::HttpRequest* request);
private:
	// 获取请求的页面
	void handUrlMethod(sys::String& inString, std::string& outString);
	// 获取上传的参数
	// for url param(?xx=xx) and post body(body)
	void handParamMethod(sys::String& inString, std::map<std::string, std::string>& outParams);
};