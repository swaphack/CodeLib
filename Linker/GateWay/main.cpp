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
		HttpResponse response;
		response.setContentType(request->getHeader(HttpRequestField::ACCEPT));

		std::string url;
		sys::String method = request->getRequest(HttpRequest::HTTP_REQUEST_METHOD);
		sys::String params = request->getRequest(HttpRequest::HTTP_REQUEST_PARAM);
		sys::String body = request->getBody();

		if (method.compare(HttpRequestConstant::HTTP_REQ_GET)) 
		{// get
			if (params.compare("/"))
			{
				url = "/index.html";
			}
			else
			{
				url = params.getString();
			}
		}
		else if (method.compare(HttpRequestConstant::HTTP_REQ_POST))
		{// post

		}
		
		response.writeFile(url.c_str());
		this->doPost(&response);
	}
};

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