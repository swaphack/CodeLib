#include "HttpRequest.h"

using namespace sys;

#define DEFAULT_HTTP_METHOD "GET"
#define DEFAULT_HTTP_URL "/"
#define DEFAULT_HTTP_VERSION "HTTP/1.1"

//////////////////////////////////////////////////////////////////////////
HttpRequest::HttpRequest()
{
	_document = new HttpReqDocument();
	_document->setMethod(DEFAULT_HTTP_METHOD);
	_document->setUrl(DEFAULT_HTTP_URL);
	_document->setHttpVersion(DEFAULT_HTTP_VERSION);
}

HttpRequest::~HttpRequest()
{
	SAFE_DELETE(_document);
}

HttpReqDocument* HttpRequest::getDocument()
{
	return _document;
}

void HttpRequest::setDocument(HttpReqDocument* doc)
{
	if (doc == nullptr)
	{
		return;
	}

	SAFE_DELETE(_document);
	_document = doc;
}

void HttpRequest::makeMessage()
{
	std::string data;
	_document->save(data);
	this->setMessage(data.c_str(), data.size());
}