#pragma once

#include "IDataBase.h"

#include <map>

namespace user
{
	
	class DataBase : public IDataBase
	{
	public:
		DataBase(long type, const char* url);
		virtual ~DataBase();
	public:
		virtual long getType();

		virtual const char* getUrl();

		virtual void load();

		virtual void save();

		virtual void addRecord(long id, IDBRecord* record);

		virtual void removeRecord(long id);

		virtual IDBRecord* getRecord(long id);

		virtual void flush();
	private:
		long _type;
		std::string _url;

		std::map<long, IDBRecord*> _records;
	};
}