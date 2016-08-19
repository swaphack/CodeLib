#include "HttpResponse.h"

#include "HttpConstant.h"
#include "../Type/import.h"

#define DEFAULT_HTTP_HEADER "HTTP"

using namespace sys;

HttpRespDocument::HttpRespDocument()
{
	_resource = nullptr;
}

HttpRespDocument::~HttpRespDocument()
{

}

bool HttpRespDocument::parseResponse(const char* msg, int size)
{
	if (msg == nullptr || size <= 0)
	{
		return false;
	}

	String line = msg;

	if (!(line.startWith(DEFAULT_HTTP_HEADER)))
	{
		return false;
	}

	return parse(msg, size);
}

const char* HttpRespDocument::getHttpVersion()
{
	return getStatus(0);
}

void HttpRespDocument::setHttpVersion(const char* version)
{
	setStatus(0, version);
}

const char* HttpRespDocument::getResponseCode()
{
	return getStatus(1);
}

void HttpRespDocument::setResponseCode(const char* code)
{
	setStatus(1, code);
}

const char* HttpRespDocument::getDescribe()
{
	return getStatus(2);
}

void HttpRespDocument::setDescribe(const char* desc)
{
	setStatus(2, desc);
}

void HttpRespDocument::setContentType(const char* value)
{
	this->setHeader(HttpResponeField::CONTENT_TYPE, value);
}

void HttpRespDocument::setContentLength(int value)
{
	this->setIntegerHeader(HttpResponeField::CONTENT_LENGTH, value);
}

void HttpRespDocument::writeString(const char* value)
{
	if (value == nullptr)
	{
		return;
	}

	this->setBody(value, strlen(value));

	this->setContentLength(strlen(value));
}

void HttpRespDocument::writeFile(const char* filename)
{
	if (filename == nullptr)
	{
		return;
	}

	std::string data;

	if (getResource())
	{
		getResource()->loadFileData(filename, data);

		this->setBody(data.c_str(), data.size());

		this->setContentLength(data.size());
	}
}

void HttpRespDocument::setResource(IResource* pResource)
{
	_resource = pResource;
}

IResource* HttpRespDocument::getResource()
{
	return _resource;
}