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
		std::string data = "Hello world";

		HttpResponse response;
		response.setMessage(data.c_str(), data.size());
		this->doPost(&response);
	}
};

int main(int argc, char** argv)
{
	WebApplication* web = new WebApplication(WEB_IP, WEB_PORT, 10000);
	web->init();

	new HttpActivityTest();

	while (true)
	{
		Sleep(100);
		web->update();
	}

	return 0;
};