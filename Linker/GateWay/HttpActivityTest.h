#include "web.h"
#include "system.h"

using namespace sys;
using namespace web;

// http Ӧ��
class HttpActivityTest : public HttpActivity
{
protected:
	// ����������
	virtual void doGet(HttpRequest* request);
	// http ����
	virtual void doHttpGet(HttpRequest* request);
	// socket ����
	virtual void doSocketGet(HttpRequest* request);
private:
	// ��ȡ�����ҳ��
	void handUrlMethod(sys::String& inString, std::string& outString);
	// ��ȡ�ϴ��Ĳ���
	// for url param(?xx=xx) and post body(\r\n body)
	void handParamMethod(sys::String& inString, std::map<std::string, std::string>& outParams);
};