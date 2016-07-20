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

void HttpRequest::setMessage(const char* msg, int size, int& offset)
{
	HttpCommand::setMessage(msg, size);

	offset = this->parseMessage();
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

int HttpRequest::parseMessage()
{
	sys::StringStream* ss = new sys::StringStream(_msg.c_str());
	sys::String line;
	std::vector<sys::String> dest;

	this->reset();

	// 解析顺序 请求行->头信息->消息体
	HttpRequestParseOrder order = EHRPO_BEGIN;

	while (!ss->readEnd())
	{
		line = ss->readLine();
		if (!line.isLine())
		{
			break;
		}
		line = line.subString(0, line.getSize() - strlen(LINE_MARK));
		if (order == EHRPO_BEGIN)	// 请求行
		{
			if (line.startWith(HttpRequestConstant::HTTP_REQ_GET)
				|| line.startWith(HttpRequestConstant::HTTP_REQ_POST)
				|| line.startWith(HttpRequestConstant::HTTP_REQ_HEAD)
				|| line.startWith(HttpRequestConstant::HTTP_REQ_PUT)
				|| line.startWith(HttpRequestConstant::HTTP_REQ_DELETE)
				|| line.startWith(HttpRequestConstant::HTTP_REQ_TRACE)
				|| line.startWith(HttpRequestConstant::HTTP_REQ_CONNECT)
				|| line.startWith(HttpRequestConstant::HTTP_REQ_OPTIONS))
			{
				this->parseRequest(line.getString());
				order = EHRPO_HEADER;
			}
			else
			{
				this->setHttpFormat(false);
				break;
			}
		}
		else if (order == EHRPO_BODY) // 可选的消息体
		{
			this->parseBody(line.getString());
			order = EHRPO_END;
		}
		else if (order == EHRPO_HEADER)
		{
			if (line.empty()) // 下一行
			{
				order = EHRPO_BODY;
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
				else
				{
					break;
				}
			}
		}
	}

	dest.clear();

	int offset = 0;
	if (!(order == EHRPO_END || order == EHRPO_BODY) && this->isHttpFormat())
	{
		this->setFullCommand(false);
	}
	else
	{
		offset = ss->getCursor() - 1;
	}

	delete ss;

	return offset;
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
