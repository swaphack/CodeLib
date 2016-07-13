#include "web.h"
#include "system.h"
#include <ctime>
#include <windows.h>

#include "HttpActivityTest.h"

using namespace sys;
using namespace web;

const char* WEB_IP = "127.0.0.1";
int WEB_PORT = 9547;

int main(int argc, char** argv)
{
	std::string websit;
	sys::Directory::getCurrentDirectory(websit);
	websit = websit + "/WebSite";

	WebApplication* web = new WebApplication(WEB_IP, WEB_PORT, 10000);
	web->getResource()->setResourcePath(websit.c_str());
	new HttpActivityTest();

	while (true)
	{
		Sleep(100);
		web->update();
	}

	return 0;
};