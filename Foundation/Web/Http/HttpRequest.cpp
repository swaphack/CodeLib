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

const char* HttpRequest::getRequest(const char* key)
{
	if (key == nullptr)
	{
		return nullptr;
	}

	std::map<std::string, std::string>::const_iterator it = _firstHeader.find(key);
	if (it != _firstHeader.end())
	{
		return it->second.c_str();
	}

	return nullptr;
}

void HttpRequest::makeMessage()
{
	_msg.clear();

	sys::String line;
	sys::StringStream ss;

	line.concat(_firstHeader[HTTP_REQUEST_METHOD].c_str());
	line.concat(" ");
	line.concat(_firstHeader[HTTP_REQUEST_PARAM].c_str());
	line.concat(" ");
	line.concat(_firstHeader[HTTP_REQUEST_VERSION].c_str());

	ss.writeLine(line.getString(), line.getSize());

	std::map<std::string, std::string>::const_iterator it = _headParams.begin();
	while (it != _headParams.end())
	{
		line = "";
		line.concat(it->first.c_str());
		line.concat(": ");
		line.concat(it->second.c_str());

		ss.writeLine(line.getString(), line.getSize());

		it++;
	}

	ss.writeLine();
	ss.writeString(_body.c_str(), _body.size());

	this->setMessage(ss.getData(), ss.getLength());
}

int HttpRequest::tryParseMessage(const char* msg, int size)
{
	sys::StringStream* ss = new sys::StringStream(msg, size);
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
			this->setBody(line.getString(), line.getSize());
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
					this->setHeader(dest[0].getString(), dest[1].getString());
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
	_firstHeader[HTTP_REQUEST_METHOD] = dest[0].getString();
	_firstHeader[HTTP_REQUEST_PARAM] = dest[1].getString();
	_firstHeader[HTTP_REQUEST_VERSION] = dest[2].getString();
}