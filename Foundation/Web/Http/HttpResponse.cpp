#include "HttpResponse.h"

#include "system.h"

#include "HttpTime.h"
#include "HttpConstant.h"

#include "../Resource/import.h"
#include "../WebApp/WebApplication.h"

#define G_RESOURCE WebApplication::getInstance()->getResourceMgr()->getResource()

using namespace web;

#define DEFAULT_HTTP_HEADER "HTTP"
#define DEFAULT_HTTP_VERSION "HTTP/1.1"
#define DEFAULT_HTTP_STATUS "200"
#define DEFAULT_HTTP_DESCRIBE "OK"

const char* HttpResponse::HTTP_RESPONSE_VERSION = "VERSION";
const char* HttpResponse::HTTP_RESPONSE_STATUS = "STATUS";
const char* HttpResponse::HTTP_RESPONSE_DESCRIBE = "DESCRIBE";

//////////////////////////////////////////////////////////////////////////

HttpResponse::HttpResponse()
{
	_firstHeader[HTTP_RESPONSE_VERSION] = DEFAULT_HTTP_VERSION;
	_firstHeader[HTTP_RESPONSE_STATUS] = DEFAULT_HTTP_STATUS;
	_firstHeader[HTTP_RESPONSE_DESCRIBE] = DEFAULT_HTTP_DESCRIBE;
}

HttpResponse::~HttpResponse()
{

}

void HttpResponse::setResponse(const char* key, const char* value)
{
	if (key == nullptr)
	{
		return;
	}

	_firstHeader[key] = value;
}

void HttpResponse::setContentType(const char* value)
{
	this->setHeader(HttpResponeField::CONTENT_TYPE, value);
}

void HttpResponse::setContentLength(int value)
{
	this->setIntegerHeader(HttpResponeField::CONTENT_LENGTH, value);
}

void HttpResponse::writeString(const char* value)
{
	if (value == nullptr)
	{
		return;
	}

	this->setBody(value, strlen(value));

	this->setContentLength(strlen(value));
}

void HttpResponse::writeFile(const char* filename)
{
	if (filename == nullptr)
	{
		return;
	}

	std::string data;

	G_RESOURCE->loadFileData(filename, data);

	this->setBody(data.c_str(), data.size());

	this->setContentLength(data.size());
}

void HttpResponse::makeMessage()
{
	_msg.clear();

	sys::String line;
	sys::StringStream ss;

	line.concat(_firstHeader[HTTP_RESPONSE_VERSION].c_str());
	line.concat(" ");
	line.concat(_firstHeader[HTTP_RESPONSE_STATUS].c_str());
	line.concat(" ");
	line.concat(_firstHeader[HTTP_RESPONSE_DESCRIBE].c_str());

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

int HttpResponse::tryParseMessage(const char* msg, int size)
{
	sys::StringStream* ss = new sys::StringStream(msg, size);
	sys::String line;
	std::vector<sys::String> dest;

	this->reset();

	// 解析顺序 请求行->头信息->消息体
	HttpRequestParseOrder order = EHRPO_BEGIN;

	while (!ss->readEnd())
	{
		if (order == EHRPO_BODY) // 可选的消息体
		{
			this->setBody(ss->getData() + ss->getCursor(), strlen(ss->getData() + ss->getCursor()));
			ss->setCursor(ss->getLength());
			order = EHRPO_END;
			break;
		}
		line = ss->readLine();
		if (!line.isLine())
		{
			break;
		}
		line = line.subString(0, line.getSize() - strlen(LINE_MARK));
		if (order == EHRPO_BEGIN)	// 请求行
		{
			if (line.startWith(DEFAULT_HTTP_HEADER))
			{
				this->parseResponse(line.getString());
				order = EHRPO_HEADER;
			}
			else
			{
				this->setHttpFormat(false);
				break;
			}
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
	{// 解析的偏移量
		offset = ss->getCursor() - 1;
	}

	delete ss;

	return offset;
}

void HttpResponse::parseResponse(const char* line)
{
	sys::String method = line;
	std::vector<sys::String> dest;

	method.split(' ', dest);

	// 验证是否是标准请求  
	if (dest.size() != 3)
	{
		return;
	}
	_firstHeader[HTTP_RESPONSE_VERSION] = dest[0].getString();
	_firstHeader[HTTP_RESPONSE_STATUS] = dest[1].getString();
	_firstHeader[HTTP_RESPONSE_DESCRIBE] = dest[2].getString();
}
