#include "HttpRequest.h"
#include "system.h"
#include "HttpConstant.h"

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
		if (index == 0)	// 请求行
		{
			if (line.startWith(HttpRequestConstant::HTTP_REQ_GET)
				|| line.startWith(HttpRequestConstant::HTTP_REQ_POST)
				|| line.startWith(HttpRequestConstant::HTTP_REQ_HEAD)
				|| line.startWith(HttpRequestConstant::HTTP_REQ_PUT)
				|| line.startWith(HttpRequestConstant::HTTP_REQ_DELETE)
				|| line.startWith(HttpRequestConstant::HTTP_REQ_TRACE)
				|| line.startWith(HttpRequestConstant::HTTP_REQ_CONNECT)
				|| line.startWith(HttpRequestConstant::HTTP_REQ_OPTIONS)
				)
			{
				this->parseRequest(line.getString());
			}
			else
			{
				index++;
			}
		}
		else if (index == -1) // 可选的消息体
		{
			this->parseBody(line.getString());
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

	// 验证是否是标准请求  
	if (dest.size() != 3)
	{
		return;
	}
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
