#pragma once

#include "IDBRecord.h"

namespace user
{
	class IDataBase
	{
	public:
		virtual long getType() = 0;

		virtual const char* getUrl() = 0;

		virtual void load() = 0;

		virtual void save() = 0;

		virtual void addRecord(long id, IDBRecord* record) = 0;

		virtual void removeRecord(long id) = 0;

		virtual IDBRecord* getRecord(long id) = 0;
	};
}