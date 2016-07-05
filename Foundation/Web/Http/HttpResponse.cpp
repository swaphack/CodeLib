#include "HttpResponse.h"

#include "system.h"

using namespace web;

#define DEFAULT_HTTP_VERSION "HTTP/1.1"
#define DEFAULT_HTTP_STATUS "200"
#define DEFAULT_HTTP_DESCRIBE "OK"

const char* HttpResponse::HTTP_RESPONSE_VERSION = "VERSION";
const char* HttpResponse::HTTP_RESPONSE_STATUS = "STATUS";
const char* HttpResponse::HTTP_RESPONSE_DESCRIBE = "DESCRIBE";

//////////////////////////////////////////////////////////////////////////

HttpResponse::HttpResponse()
{
	_lineParams[HTTP_RESPONSE_VERSION] = DEFAULT_HTTP_VERSION;
	_lineParams[HTTP_RESPONSE_STATUS] = DEFAULT_HTTP_STATUS;
	_lineParams[HTTP_RESPONSE_DESCRIBE] = DEFAULT_HTTP_DESCRIBE;
}

HttpResponse::~HttpResponse()
{

}

void HttpResponse::setStatusParam(const char* key, const char* value)
{
	if (key == nullptr)
	{
		return;
	}

	_lineParams[key] = value;
}

void HttpResponse::setHeadParam(const char* key, const char* value)
{
	if (key == nullptr)
	{
		return;
	}

	_headParams[key] = value;
}

void HttpResponse::setExtMessage(const char* value)
{
	_extMessage = value;
}

void HttpResponse::makeMessage()
{
	_msg.clear();

	sys::String line;
	sys::StringStream ss;

	line.concat(_lineParams[HTTP_RESPONSE_VERSION].c_str());
	line.concat(" ");
	line.concat(_lineParams[HTTP_RESPONSE_STATUS].c_str());
	line.concat(" ");
	line.concat(_lineParams[HTTP_RESPONSE_DESCRIBE].c_str());

	ss.writeLine(line.getString());

	std::map<std::string, std::string>::const_iterator it = _headParams.begin();
	while (it != _headParams.end())
	{
		line = "";
		line.concat(it->first.c_str());
		line.concat(": ");
		line.concat(it->second.c_str());

		ss.writeLine(line.getString());
	}

	ss.writeLine();
	ss.writeLine(_extMessage.c_str());

	this->setMessage(ss.getData(), ss.getLength());
}
