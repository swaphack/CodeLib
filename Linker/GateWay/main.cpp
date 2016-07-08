#include "web.h"
#include "system.h"
#include <ctime>
#include <windows.h>

using namespace sys;
using namespace web;

const char* WEB_IP = "127.0.0.1";
int WEB_PORT = 9547;

class HttpActivityTest : public HttpActivity
{
protected:
	virtual void doGet(HttpRequest* request)
	{
		std::string respData = "Hello";

		Time* now = Time::getGM();

		HttpResponse response;
		response.setContentType("text/html");
		response.setContentLength(respData.size());
		response.setDateHeader(HttpResponeField::DATE, now);
		response.setDateHeader(HttpResponeField::LAST_MODIFIED, now);
		response.setHeader(HttpResponeField::SERVER, "Windows");
		response.setHeader(HttpResponeField::CONNECTION, "close");
		response.setBody(respData.c_str());

		this->doPost(&response);
	}
};

int main(int argc, char** argv)
{
	HttpApplication* web = new HttpApplication(WEB_IP, WEB_PORT, 10000);
	web->init();

	new HttpActivityTest();

	while (true)
	{
		Sleep(100);
		web->update();
	}

	return 0;
};