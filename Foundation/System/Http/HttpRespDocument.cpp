#include "HttpResponse.h"
#include "Base/macros.h"
#include "HttpConstant.h"
#include "Type/import.h"
#include "Resource/IResource.h"

#define DEFAULT_HTTP_HEADER "HTTP"

using namespace sys;

HttpRespDocument::HttpRespDocument()
{
	_resource = nullptr;
}

HttpRespDocument::~HttpRespDocument()
{

}

bool HttpRespDocument::parseResponse(const char* msg, int32_t size)
{
	if (msg == nullptr || size <= 0)
	{
		return false;
	}

	String line(msg, size);

	if (!(line.startWith(DEFAULT_HTTP_HEADER)))
	{
		return false;
	}

	return parse(std::string(msg, size));
}

const std::string& HttpRespDocument::getHttpVersion() const
{
	return getStatus(0);
}

void HttpRespDocument::setHttpVersion(const std::string& version)
{
	setStatus(0, version);
}

const std::string& HttpRespDocument::getResponseCode() const
{
	return getStatus(1);
}

void HttpRespDocument::setResponseCode(const std::string& code)
{
	setStatus(1, code);
}

void HttpRespDocument::setResponseCode(int32_t code)
{
	setResponseCode(getCString("%d", code));
}

const std::string& HttpRespDocument::getDescribe() const
{
	return getStatus(2);
}

void HttpRespDocument::setDescribe(const std::string& desc)
{
	setStatus(2, desc);
}

void HttpRespDocument::setContentType(const std::string& value)
{
	this->setHeader(HttpResponeField::CONTENT_TYPE, value);
}

void HttpRespDocument::setContentLength(int32_t value)
{
	this->setIntegerHeader(HttpResponeField::CONTENT_LENGTH, value);
}

void HttpRespDocument::writeContentString(const std::string& value)
{
	this->setBody(value);

	this->setContentLength(value.size());
}

void HttpRespDocument::writeContentFile(const std::string& filename)
{
	if (filename.empty())
	{
		return;
	}

	if (getResource())
	{
		getResource()->loadFileData(filename, [this](const std::string& data)
		{
			this->writeContentString(data);
		});
	}
	else
	{
		this->writeContentString("");
	}
}

void HttpRespDocument::setResource(IResource* pResource)
{
	_resource = pResource;
}

IResource* HttpRespDocument::getResource() const
{
	return _resource;
}