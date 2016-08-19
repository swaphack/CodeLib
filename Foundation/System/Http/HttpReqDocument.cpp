#include "HttpRequest.h"
#include "HttpConstant.h"
#include "../Type/import.h"

using namespace sys;

HttpReqDocument::HttpReqDocument()
{

}

HttpReqDocument::~HttpReqDocument()
{

}

bool HttpReqDocument::parseRequest(const char* msg, int size)
{
	if (msg == nullptr || size <= 0)
	{
		return false;
	}

	String line = msg;

	if (!(line.startWith(HttpRequestConstant::HTTP_REQ_GET)
		|| line.startWith(HttpRequestConstant::HTTP_REQ_POST)
		|| line.startWith(HttpRequestConstant::HTTP_REQ_HEAD)
		|| line.startWith(HttpRequestConstant::HTTP_REQ_PUT)
		|| line.startWith(HttpRequestConstant::HTTP_REQ_DELETE)
		|| line.startWith(HttpRequestConstant::HTTP_REQ_TRACE)
		|| line.startWith(HttpRequestConstant::HTTP_REQ_CONNECT)
		|| line.startWith(HttpRequestConstant::HTTP_REQ_OPTIONS)))
	{
		return false;
	}

	return parse(msg, size);
}

const char* HttpReqDocument::getMethod()
{
	return getStatus(0);
}

void HttpReqDocument::setMethod(const char* method)
{
	setStatus(0, method);
}

const char* HttpReqDocument::getUrl()
{
	return getStatus(1);
}

void HttpReqDocument::setUrl(const char* url)
{
	setStatus(1, url);
}

const char* HttpReqDocument::getHttpVersion()
{
	return getStatus(2);
}

void HttpReqDocument::setHttpVersion(const char* version)
{
	setStatus(2, version);
}