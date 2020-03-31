#include "HttpResponse.h"
#include "Base/macros.h"

using namespace sys;

#define DEFAULT_HTTP_VERSION "HTTP/1.1"
#define DEFAULT_HTTP_STATUS "200"
#define DEFAULT_HTTP_DESCRIBE "OK"

#define HTTP_CHUNKED_SIZE 1024

//////////////////////////////////////////////////////////////////////////

HttpResponse::HttpResponse()
:_chunkedSize(HTTP_CHUNKED_SIZE)
{
	_document = new HttpRespDocument();
	_document->setHttpVersion(DEFAULT_HTTP_VERSION);
	_document->setResponseCode(DEFAULT_HTTP_STATUS);
	_document->setDescribe(DEFAULT_HTTP_DESCRIBE);
}

HttpResponse::~HttpResponse()
{
	SAFE_DELETE(_document);
}

HttpRespDocument* HttpResponse::getDocument()
{
	return _document;
}

void HttpResponse::setDocument(HttpRespDocument* doc)
{
	if (doc == nullptr)
	{
		return;
	}

	SAFE_DELETE(_document);
	_document = doc;
}

void HttpResponse::makeMessage()
{
	std::string data;
	_document->save(data);
	this->setMessage(data.c_str(), data.size());
}