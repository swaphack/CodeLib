#include "DBSheet.h"
#include "DBStorage.h"

using namespace db;


DBSheet::DBSheet( )
{
}

DBSheet::~DBSheet()
{
	this->clear();
}

void DBSheet::addRecord(DBRecord* record)
{
	if (record == nullptr)
	{
		return;
	}

	_records.push_back(record);
}

void DBSheet::removeRecord(DBRecord* record)
{
	if (record == nullptr)
	{
		return;
	}

	std::vector<DBRecord*>::iterator iter = _records.begin();

	while (iter != _records.end())
	{
		if (*iter == record)
		{
			SAFE_DELETE(*iter);
			_records.erase(iter);
			break;
		}
		iter++;
	}
}

void DBSheet::removeRecord(int index)
{
	int size = _records.size();
	if (index < 0 || index >= size)
	{
		return;
	}

	_records.erase(_records.begin() + index);
}

DBRecord* DBSheet::getRecord(int index)
{
	int size = _records.size();
	if (index < 0 || index >= size)
	{
		return nullptr;
	}

	return _records[index];
}

int DBSheet::count()
{
	return _records.size();
}

void DBSheet::clear()
{
	std::vector<DBRecord*>::iterator iter = _records.begin();
	if (iter != _records.end())
	{
		SAFE_DELETE(*iter);
		iter++;
	}

	_records.clear();
}


