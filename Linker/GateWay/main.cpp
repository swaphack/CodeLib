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
		std::string data = request->getMessage();

		HttpResponse response;
		response.setExtMessage(data.c_str());
		this->doBroadCast(&response);
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