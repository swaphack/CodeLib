#include "HttpRequest.h"
#include "system.h"

using namespace web;

const char* HttpRequest::HTTP_REQUEST_METHOD = "METHOD";
const char* HttpRequest::HTTP_REQUEST_PARAM = "PARAM";
const char* HttpRequest::HTTP_REQUEST_VERSION = "VERSION";

//////////////////////////////////////////////////////////////////////////
HttpRequest::HttpRequest()
{
	this->reset();
}

HttpRequest::~HttpRequest()
{

}

void HttpRequest::setMessage(const char* msg, int size)
{
	HttpCommand::setMessage(msg, size);

	this->parseMessage();
}

const char* HttpRequest::getLineParam(const char* key)
{
	if (key == nullptr)
	{
		return nullptr;
	}

	std::map<std::string, std::string>::const_iterator it = _lineParams.find(key);
	if (it != _lineParams.end())
	{
		return it->second.c_str();
	}

	return nullptr;
}

const char* HttpRequest::getHeadParam(const char* key)
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

const char* HttpRequest::getExtMessage()
{
	return _extMessage.c_str();
}

void HttpRequest::parseMessage()
{
	sys::StringStream* ss = new sys::StringStream(_msg.c_str());
	sys::String line;
	std::vector<sys::String> dest;

	this->reset();

	int index = 0;
	while (!ss->readEnd())
	{
		line = ss->readLine();
		if (index == 0)	// 请求行
		{
			this->parseLine(line.getString());
		}
		else if (index == -1) // 可选的消息体
		{
			this->parseMessage(line.getString());
		}
		else
		{
			if (line.empty()) // 下一行
			{
				index = -1;
				continue;
			}
			else // 消息报头
			{
				dest.clear();
				line.split(": ", dest);
				if (dest.size() == 2)
				{
					this->parseHead(dest[0].getString(), dest[1].getString());
				}
			}
		}
		index++;
	}

	dest.clear();
}


void HttpRequest::parseLine(const char* line)
{
	sys::String method = line;
	std::vector<sys::String> dest;

	method.split(' ', dest);

	_lineParams[HTTP_REQUEST_METHOD] = dest[0].getString();
	_lineParams[HTTP_REQUEST_PARAM] = dest[1].getString();
	_lineParams[HTTP_REQUEST_VERSION] = dest[2].getString();
}

void HttpRequest::parseHead(const char* key, const char* value)
{
	_headParams[key] = value;
}

void HttpRequest::parseMessage(const char* msg)
{
	_extMessage = msg;
}

void HttpRequest::reset()
{
	_lineParams.clear();
	_headParams.clear();
	_extMessage = "";
}
