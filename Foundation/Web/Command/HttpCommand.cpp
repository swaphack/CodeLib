#include "HttpCommand.h"

using namespace web;


HttpCommand::HttpCommand()
{
	_msg = "";
}

HttpCommand::~HttpCommand()
{

}

void HttpCommand::setMessage( const char* msg, int size )
{
	_msg = std::string(msg, size);
}

char* HttpCommand::getMessage()
{
	return (char*)_msg.c_str();
}

int HttpCommand::size()
{
	return _msg.size();
}

bool HttpCommand::empty()
{
	return _msg.empty();
}

//////////////////////////////////////////////////////////////////////////
HttpRequest::HttpRequest()
:_srcID(0)
{

}

HttpRequest::~HttpRequest()
{
	
}

void HttpRequest::setSrcID( int id )
{
	_srcID = id;
}

int HttpRequest::getSrcID()
{
	return _srcID;
}

//////////////////////////////////////////////////////////////////////////
HttpResponse::HttpResponse()
:_destID(0)
{

}

HttpResponse::~HttpResponse()
{

}

void HttpResponse::setDestID( int id )
{
	_destID = id;
}

int HttpResponse::getDestID()
{
	return _destID;
}
