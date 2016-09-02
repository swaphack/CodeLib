#include "web.h"
#include "system.h"

using namespace sys;
using namespace web;

// http Ӧ��
class HttpActivityTest : public web::HttpActivity
{
protected:
	// ����������
	virtual void doGet(sys::HttpRequest* request);
	// http ����
	virtual void doHttpGet(sys::HttpRequest* request);
	// socket ����
	virtual void doSocketGet(sys::HttpRequest* request);
private:
	// ��ȡ�����ҳ��
	void handUrlMethod(sys::String& inString, std::string& outString);
	// ��ȡ�ϴ��Ĳ���
	// for url param(?xx=xx) and post body(body)
	void handParamMethod(sys::String& inString, std::map<std::string, std::string>& outParams);
};