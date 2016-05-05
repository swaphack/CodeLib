#pragma once

#include "ILogger.h"

#include <string>
#include <queue>

namespace user
{
	class Logger : public ILogger
	{
	public:
		Logger(long type, const char* url);
		virtual ~Logger();
	public:
		virtual long getType();

		virtual const char* getUrl();

		virtual void load();

		virtual void save();

		virtual ILoggerRecord* getTopRecord();

		virtual void addRecord(ILoggerRecord* record);

		virtual void removeTopRecord();

		virtual void flush();
	private:
		long _type;
		std::string _url;
		std::queue<ILoggerRecord*> _records;
	};
}