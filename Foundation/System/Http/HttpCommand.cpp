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

void HttpCommand::setSessionID(const std::string& id)
{
	if (id.empty())
	{
		return;
	}

	_sessionID = id;
}

const std::string& HttpCommand::getSessionID()
{
	return _sessionID;
}

void HttpCommand::setMessage(const std::string& msg, int32_t size)
{
	_msg = std::string(msg, size);
}

void HttpCommand::makeMessage()
{

}

const std::string& HttpCommand::getMessage()
{
	return _msg;
}

int32_t HttpCommand::getMessageSize()
{
	return _msg.size();
}

bool HttpCommand::isMessageEmpty()
{
	return _msg.empty();
}