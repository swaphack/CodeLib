#include "HttpCommand.h"

#include "system.h"

using namespace web;


HttpCommand::HttpCommand()
{
	_msg = "";
	_bHttpFormat = true;
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

bool HttpCommand::isHttpFormat()
{
	return _bHttpFormat;
}

void HttpCommand::setHttpFormat(bool status)
{
	_bHttpFormat = status;
}
