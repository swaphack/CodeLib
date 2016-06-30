#include "HttpCommand.h"

#include "system.h"

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
	this->parseMessage();
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

void HttpCommand::parseMessage()
{
	
}
