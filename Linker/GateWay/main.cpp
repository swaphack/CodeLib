#include "web.h"
#include "system.h"
#include <ctime>
#include <windows.h>

#include "HttpActivityTest.h"

using namespace sys;
using namespace web;

const char* WEB_IP = "127.0.0.1";
int WEB_PORT = 9547;

const char* WEB_SITE_URL = "F:/WebCat/sqlite-doc-3130000";

//#define USE_DEFAULT_WEBSITE

int main(int argc, char** argv)
{
	std::string websit;
#ifdef USE_DEFAULT_WEBSITE
	sys::Directory::getCurrentDirectory(websit);
	websit = websit + "/WebSite";
#else
	websit = WEB_SITE_URL;
#endif

	WebApplication* web = new WebApplication(WEB_IP, WEB_PORT, 10000);
	web->getResourceMgr()->setUrl(websit.c_str());
	new HttpActivityTest();

	while (true)
	{
		Sleep(100);
		web->update();
	}

	return 0;
};