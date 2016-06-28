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
	_params.clear();
	sys::StringStream* ss = new sys::StringStream(_msg.c_str());
	std::string line;
	int index;
	while (!ss->readEnd())
	{
		line = ss->readLine();
		line = line.substr(0, line.size() - 2);
		LOG("line message %s\n", line.c_str());
		int len = strlen(line.c_str());
		LOG("line length %s\n", len);
	}
}
