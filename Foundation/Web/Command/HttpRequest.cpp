#include "HttpRequest.h"

using namespace web;

HttpRequest::HttpRequest()
:_srcID(0)
{

}

HttpRequest::~HttpRequest()
{

}

void HttpRequest::setSrcID(int id)
{
	_srcID = id;
}

int HttpRequest::getSrcID()
{
	return _srcID;
}