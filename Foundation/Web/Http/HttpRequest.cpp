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

	this->parseRequest();
}

const char* HttpRequest::getRequest(const char* key)
{
	if (key == nullptr)
	{
		return nullptr;
	}

	std::map<std::string, std::string>::const_iterator it = _requestParams.find(key);
	if (it != _requestParams.end())
	{
		return it->second.c_str();
	}

	return nullptr;
}

const char* HttpRequest::getHeader(const char* key)
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

const char* HttpRequest::getBody()
{
	return _body.c_str();
}

void HttpRequest::parseRequest()
{
	sys::StringStream* ss = new sys::StringStream(_msg.c_str());
	sys::String line;
	std::vector<sys::String> dest;

	this->reset();

	int index = 0;
	while (!ss->readEnd())
	{
		line = ss->readLine();
		if (index == 0)	// ������
		{
			this->parseRequest(line.getString());
		}
		else if (index == -1) // ��ѡ����Ϣ��
		{
			this->parseBody(line.getString());
		}
		else
		{
			if (line.empty()) // ��һ��
			{
				index = -1;
				continue;
			}
			else // ��Ϣ��ͷ
			{
				dest.clear();
				line.split(": ", dest);
				if (dest.size() == 2)
				{
					this->parseHeader(dest[0].getString(), dest[1].getString());
				}
			}
		}
		index++;
	}

	dest.clear();
}


void HttpRequest::parseRequest(const char* line)
{
	sys::String method = line;
	std::vector<sys::String> dest;

	method.split(' ', dest);

	_requestParams[HTTP_REQUEST_METHOD] = dest[0].getString();
	_requestParams[HTTP_REQUEST_PARAM] = dest[1].getString();
	_requestParams[HTTP_REQUEST_VERSION] = dest[2].getString();
}

void HttpRequest::parseHeader(const char* key, const char* value)
{
	_headParams[key] = value;
}

void HttpRequest::parseBody(const char* msg)
{
	_body = msg;
}

void HttpRequest::reset()
{
	_requestParams.clear();
	_headParams.clear();
	_body = "";
}
