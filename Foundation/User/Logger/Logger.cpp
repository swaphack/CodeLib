#include "Logger.h"

using namespace user;


Logger::Logger( long type, const char* url)
:_type(type)
,_url(url)
{ 
	
}

Logger::~Logger()
{

}

long Logger::getType()
{
	return _type;
}

const char* Logger::getUrl()
{
	return _url.c_str();
}

void Logger::load()
{

}

void Logger::save()
{

}

ILoggerRecord* Logger::getTopRecord()
{
	if (_records.size() == 0)
	{
		return nullptr;
	}

	return _records.front();
}

void Logger::addRecord( ILoggerRecord* record )
{
	if (record == nullptr)
	{
		return;
	}

	_records.push(record);
}

void Logger::removeTopRecord()
{
	if (_records.size() == 0)
	{
		return;
	}

	ILoggerRecord* record = this->getTopRecord();

	_records.pop();

	delete record;
}

void Logger::flush()
{
	this->save();

	while (!_records.empty())
	{
		ILoggerRecord* record = _records.front();
		delete record;

		_records.pop();
	}
}
