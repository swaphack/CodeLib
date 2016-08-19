#include "HttpRequest.h"

using namespace sys;

#define DEFAULT_HTTP_METHOD "GET"
#define DEFAULT_HTTP_URL "/"
#define DEFAULT_HTTP_VERSION "HTTP/1.1"

//////////////////////////////////////////////////////////////////////////
HttpRequest::HttpRequest()
{
	_document = new HttpReqDocument();
	_document->setMethod(DEFAULT_HTTP_METHOD);
	_document->setUrl(DEFAULT_HTTP_URL);
	_document->setHttpVersion(DEFAULT_HTTP_VERSION);
}

HttpRequest::~HttpRequest()
{
	SAFE_DELETE(_document);
}

HttpReqDocument* HttpRequest::getDocument()
{
	return _document;
}

void HttpRequest::setDocument(HttpReqDocument* doc)
{
	if (doc == nullptr)
	{
		return;
	}

	SAFE_DELETE(_document);
	_document = doc;
}

void HttpRequest::makeMessage()
{
	std::string data;
	_document->save(data);
	this->setMessage(data.c_str(), data.size());
}

/*
void HttpRequest::makeMessage()
{
	_msg.clear();

	String line;
	StringStream ss;

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
	StringStream* ss = new StringStream(msg, size);
	String line;
	std::vector<String> dest;

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
*/


