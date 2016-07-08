#include "HttpResponse.h"

#include "system.h"

#include "HttpTime.h"
#include "HttpConstant.h"

#include "../WebSite/WebApplication.h"

#define G_RESOURCE WebApplication::getInstance()->getResource()

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
	_responseParams[HTTP_RESPONSE_VERSION] = DEFAULT_HTTP_VERSION;
	_responseParams[HTTP_RESPONSE_STATUS] = DEFAULT_HTTP_STATUS;
	_responseParams[HTTP_RESPONSE_DESCRIBE] = DEFAULT_HTTP_DESCRIBE;
}

HttpResponse::~HttpResponse()
{

}

void HttpResponse::setResponse(const char* key, const char* value)
{
	if (key == nullptr)
	{
		return;
	}

	_responseParams[key] = value;
}

void HttpResponse::setHeader(const char* key, const char* value)
{
	if (key == nullptr)
	{
		return;
	}

	_headParams[key] = value;
}

void HttpResponse::setDateHeader(const char* key, sys::Time* value)
{
	sys::String strTime = HttpTime::getRFC822Time(value);

	this->setHeader(key, strTime.getString());
}

void HttpResponse::setIntegerHeader(const char* key, int value)
{
	sys::String strTime;
	strTime.make("%d", value);

	this->setHeader(key, strTime.getString());
}

void HttpResponse::setContentType(const char* value)
{
	this->setHeader(HttpResponeField::CONTENT_TYPE, value);
}

void HttpResponse::setContentLength(int value)
{
	this->setIntegerHeader(HttpResponeField::CONTENT_LENGTH, value);
}

void HttpResponse::setBody(const char* value)
{
	_body = value;
}

void HttpResponse::writeString(const char* value)
{
	if (value == nullptr)
	{
		return;
	}

	this->setBody(value);

	this->setContentLength(strlen(value));
}

void HttpResponse::writeFile(const char* filename)
{
	std::string data = G_RESOURCE->loadFile(filename);

	this->setBody(data.c_str());

	this->setContentLength(data.size());
}

void HttpResponse::makeMessage()
{
	_msg.clear();

	sys::String line;
	sys::StringStream ss;

	line.concat(_responseParams[HTTP_RESPONSE_VERSION].c_str());
	line.concat(" ");
	line.concat(_responseParams[HTTP_RESPONSE_STATUS].c_str());
	line.concat(" ");
	line.concat(_responseParams[HTTP_RESPONSE_DESCRIBE].c_str());

	ss.writeLine(line.getString());

	std::map<std::string, std::string>::const_iterator it = _headParams.begin();
	while (it != _headParams.end())
	{
		line = "";
		line.concat(it->first.c_str());
		line.concat(": ");
		line.concat(it->second.c_str());

		ss.writeLine(line.getString());

		it++;
	}

	ss.writeLine();
	ss.writeLine(_body.c_str());

	this->setMessage(ss.getData(), ss.getLength());
}
