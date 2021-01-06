#include "HttpDocument.h"
#include "Base/macros.h"
#include "HttpTime.h"
#include "Type/String.h"

#include "Time/DateTime.h"
#include "Stream/StringStream.h"

#define STATUS_KEY_VALUE_SIGN " "
#define HEADER_KEY_VALUE_SIGN ": "

using namespace sys;


HttpDocument::HttpDocument()
{
	_stream = new StringStream();

	this->resetStatusSection();
}

HttpDocument::~HttpDocument()
{
	SAFE_DELETE(_stream);
}

bool HttpDocument::parse(const std::string& msg)
{
	_stream->initWithData(msg);
	_stream->setCursor(0);
	do 
	{
		if (!readStatusSection())
		{
			return false;
		}
		if (!readHeaderSection())
		{
			return false;
		}
		if (!readBodySection())
		{
			return false;
		}
	} while (0);

	return true;
}

bool HttpDocument::save(std::string& msg)
{
	StringStream ss;

	std::vector<std::string>::const_iterator iter = _statusSection.begin();
	while (true)
	{
		ss.writeString(*iter);

		iter++;

		if (iter == _statusSection.end()) break;

		ss.writeString(STATUS_KEY_VALUE_SIGN);
	}
	ss.writeLine();

	std::map<std::string, std::string>::const_iterator iter2 = _headerSection.begin();
	while (iter2 != _headerSection.end())
	{
		ss.writeString(iter2->first);
		ss.writeString(HEADER_KEY_VALUE_SIGN);
		ss.writeString(iter2->second);
		ss.writeLine();

		iter2++;
	}
	ss.writeLine();

	ss.writeLine(_bodySection);

	msg = std::string(ss.getData(), ss.getLength());

	return true;
}

std::string HttpDocument::getStatus(int32_t index)
{
	if (index < 0 || index >= _headerSection.size())
	{
		return "";
	}

	return _statusSection[index];
}

void HttpDocument::setStatus(int32_t index, const std::string& value)
{
	if (index < 0 || index >= _statusSection.size() || value.empty())
	{
		return;
	}

	_statusSection[index] = value;
}

std::string HttpDocument::getHeader(const std::string& key)
{
	if (key.empty())
	{
		return "";
	}

	std::map<std::string, std::string>::const_iterator it = _headerSection.find(key);
	if (it != _headerSection.end())
	{
		return it->second;
	}

	return "";
}

bool HttpDocument::getIntegerHeader(const std::string& key, int32_t& value)
{
	const std::string& data = getHeader(key);
	if (data.empty())
	{
		return false;
	}

	value = atoi(data.c_str());

	return true;
}

void HttpDocument::removeHeader(const std::string& key)
{
	if (key.empty())
	{
		return;
	}

	if (_headerSection.find(key) == _headerSection.end())
	{
		return;
	}

	_headerSection.erase(key);
}

void HttpDocument::setHeader(const std::string& key, const std::string& value)
{
	if (key.empty())
	{
		return;
	}

	_headerSection[key] = value;
}

void HttpDocument::setDateHeader(const std::string& key, DateTime* value)
{
	std::string strTime = HttpTime::getRFC822Time(value);

	this->setHeader(key, strTime);
}

void HttpDocument::setIntegerHeader(const std::string& key, int32_t value)
{
	this->setHeader(key, getCString("%d", value));
}

void HttpDocument::setBody(const std::string& value)
{
	_bodySection = value;
}

const std::string& HttpDocument::getBody()
{
	return _bodySection;
}

int32_t HttpDocument::getBodySize()
{
	return _bodySection.size();
}

int32_t HttpDocument::getStreamSize()
{
	return _stream->getCursor();
}

bool HttpDocument::readStatusSection()
{
	if (_stream->readEnd())
	{
		return false;
	}

	this->resetStatusSection();

	std::string text;	
	String line;

	_stream->readLine(text);
	line = text;
	if (!line.isLine())
	{
		return false;
	}
	line = line.subString(0, line.getSize() - strlen(LINE_MARK));
	if (line.empty())
	{
		return false;
	}

	std::vector<String> dest;
	line.split(STATUS_KEY_VALUE_SIGN, dest);

	if (dest.size() != 3)
	{
		return false;
	}

	int32_t offset = dest[0].getSize() + dest[1].getSize() + 2;
	_statusSection[0] = dest[0].getString();
	_statusSection[1] = dest[1].getString();
	_statusSection[2] = line.subString(offset, line.getSize() - offset).getString();
	return true;
}

bool HttpDocument::readHeaderSection()
{
	if (_stream->readEnd())
	{
		return false;
	}

	_headerSection.clear();

	std::string text;
	String line;
	int32_t offset;
	std::string key;
	std::string value;
	do 
	{
		_stream->readLine(text);
		line = text;
		if (!line.isLine())
		{
			return false;
		}
		line = line.subString(0, line.getSize() - strlen(LINE_MARK));
		if (line.empty())
		{
			if (_headerSection.empty()) 
				return false;
			break;
		}
		offset = line.findFirstOf(HEADER_KEY_VALUE_SIGN);
		key = line.subString(0, offset).getString();
		offset = offset + strlen(HEADER_KEY_VALUE_SIGN);
		value = line.subString(offset, line.getSize() - offset).getString();
		_headerSection[key] = value;
	} while (true);

	return true;
}

bool HttpDocument::readBodySection()
{
	_bodySection.clear();
	if (_stream->readEnd())
	{
		return true;
	}

	_stream->readRemain(_bodySection);
	return true;
}

void HttpDocument::resetStatusSection()
{
	_statusSection.clear();
	_statusSection.push_back("");
	_statusSection.push_back("");
	_statusSection.push_back("");
}