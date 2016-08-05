#include "HttpCommand.h"

#include "system.h"
#include "HttpTime.h"

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

const char* HttpCommand::getHeader(const char* key)
{
	if (key == nullptr)
	{
		return nullptr;
	}

	std::map<std::string, std::string>::const_iterator it = _headParams.find(key);
	if (it != _headParams.end())
	{
		return it->second.c_str();
	}

	return nullptr;
}

bool HttpCommand::getIntegerHeader(const char* key, int& value)
{
	const char* data = getHeader(key);
	if (data == nullptr)
	{
		return false;
	}

	value = atoi(data);

	return true;
}

void HttpCommand::setHeader(const char* key, const char* value)
{
	if (key == nullptr || value == nullptr)
	{
		return;
	}

	_headParams[key] = value;
}

void HttpCommand::setDateHeader(const char* key, sys::Time* value)
{
	sys::String strTime = HttpTime::getRFC822Time(value);

	this->setHeader(key, strTime.getString());
}

void HttpCommand::setIntegerHeader(const char* key, int value)
{
	this->setHeader(key, getCString("%d", value));
}

void HttpCommand::setBody(const char* value, int size)
{
	_body = std::string(value, size);
}

const char* HttpCommand::getBody()
{
	return _body.c_str();
}

int HttpCommand::getBodySize()
{
	return _body.size();
}

void HttpCommand::makeMessage()
{

}

int HttpCommand::tryParseMessage(const char* msg, int size)
{
	return 0;
}

void HttpCommand::reset()
{
	_firstHeader.clear();
	_headParams.clear();
	_body = "";
}
