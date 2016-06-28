#include "HttpResponse.h"

using namespace web;

HttpResponse::HttpResponse()
:_destID(0)
{

}

HttpResponse::~HttpResponse()
{

}

void HttpResponse::setDestID(int id)
{
	_destID = id;
}

int HttpResponse::getDestID()
{
	return _destID;
}