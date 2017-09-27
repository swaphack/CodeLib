#include "HttpCommand.h"

#include "HttpTime.h"
#include "Type/import.h"

using namespace sys;


HttpCommand::HttpCommand()
{
}

HttpCommand::~HttpCommand()
{

}

void HttpCommand::setSessionID(const char* id)
{
	if (id == nullptr)
	{
		return;
	}

	_sessionID = id;
}

const char* HttpCommand::getSessionID()
{
	return _sessionID.c_str();
}

void HttpCommand::setMessage(const char* msg, int size)
{
	_msg = std::string(msg, size);
}

void HttpCommand::makeMessage()
{

}

const char* HttpCommand::getMessage()
{
	return _msg.c_str();
}

int HttpCommand::getMessageSize()
{
	return _msg.size();
}

bool HttpCommand::isMessageEmpty()
{
	return _msg.empty();
}