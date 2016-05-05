#pragma once

#include "ILoggerRecord.h"

namespace user
{
	class ILogger
	{
	public:
		virtual long getType() = 0;

		virtual const char* getUrl() = 0;

		virtual void load() = 0;

		virtual void save() = 0;


		virtual const ILoggerRecord* getTopRecord() = 0;

		virtual void addRecord(ILoggerRecord* record) = 0;

		virtual void removeTopRecord() = 0;
	};
}