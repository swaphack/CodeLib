#include "HttpResponse.h"

using namespace sys;

#define DEFAULT_HTTP_VERSION "HTTP/1.1"
#define DEFAULT_HTTP_STATUS "200"
#define DEFAULT_HTTP_DESCRIBE "OK"

//////////////////////////////////////////////////////////////////////////

HttpResponse::HttpResponse()
{
	_document = new HttpRespDocument();
	_document->setHttpVersion(DEFAULT_HTTP_VERSION);
	_document->setResponseCode(DEFAULT_HTTP_STATUS);
	_document->setDescribe(DEFAULT_HTTP_DESCRIBE);
}

HttpResponse::~HttpResponse()
{
	SAFE_DELETE(_document);
}

HttpRespDocument* HttpResponse::getDocument()
{
	return _document;
}

void HttpResponse::setDocument(HttpRespDocument* doc)
{
	if (doc == nullptr)
	{
		return;
	}

	SAFE_DELETE(_document);
	_document = doc;
}

void HttpResponse::makeMessage()
{
	std::string data;
	_document->save(data);
	this->setMessage(data.c_str(), data.size());
}

/*
void HttpResponse::makeMessage()
{
	_msg.clear();

	String line;
	StringStream ss;

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
	StringStream* ss = new StringStream(msg, size);
	String line;
	std::vector<String> dest;

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
*/