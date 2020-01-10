#include "HttpDocument.h"
#include "Type/import.h"
#include "HttpTime.h"

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

bool HttpDocument::parse(const char* msg, int32_t size)
{
	_stream->initWithText(msg, size);
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
		ss.writeString((*iter).c_str(), (*iter).size());

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

const char* HttpDocument::getStatus(int32_t index)
{
	if (index < 0 || index >= _headerSection.size())
	{
		return nullptr;
	}

	return _statusSection[index].c_str();
}

void HttpDocument::setStatus(int32_t index, const char* value)
{
	if (index < 0 || index >= _statusSection.size() || value == nullptr)
	{
		return;
	}

	_statusSection[index] = value;
}

const char* HttpDocument::getHeader(const char* key)
{
	if (key == nullptr)
	{
		return nullptr;
	}

	std::map<std::string, std::string>::const_iterator it = _headerSection.find(key);
	if (it != _headerSection.end())
	{
		return it->second.c_str();
	}

	return nullptr;
}

bool HttpDocument::getint32egerHeader(const char* key, int32_t& value)
{
	const char* data = getHeader(key);
	if (data == nullptr)
	{
		return false;
	}

	value = atoi(data);

	return true;
}

void HttpDocument::removeHeader(const char* key)
{
	if (key == nullptr )
	{
		return;
	}

	if (_headerSection.find(key) == _headerSection.end())
	{
		return;
	}

	_headerSection.erase(key);
}

void HttpDocument::setHeader(const char* key, const char* value)
{
	if (key == nullptr || value == nullptr)
	{
		return;
	}

	_headerSection[key] = value;
}

void HttpDocument::setDateHeader(const char* key, Time* value)
{
	String strTime = HttpTime::getRFC822Time(value);

	this->setHeader(key, strTime.getString());
}

void HttpDocument::setint32egerHeader(const char* key, int32_t value)
{
	this->setHeader(key, getCString("%d", value));
}

void HttpDocument::setBody(const char* value, int32_t size)
{
	_bodySection = std::string(value, size);
}

const char* HttpDocument::getBody()
{
	return _bodySection.c_str();
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