#include "DBSheet.h"
#include "DBStorage.h"

using namespace db;


DBSheet::DBSheet( DBTable* table )
{
	_table = table;
}

DBSheet::~DBSheet()
{
	this->clear();
}

void DBSheet::reloadStruct( DBTable* table )
{

}

const DBTable* DBSheet::getTable() const
{
	return _table;
}

void DBSheet::addRecord( int key, DBRecord* record )
{
	if (record == nullptr)
	{
		return;
	}

	ASSERT(_records[key] == nullptr);

	_records[key] = record;
}

void DBSheet::addRecord(DBRecord* record)
{
	int key = DBStorage::getHashKey(getTable(), record, _records.size() + 1);
	this->addRecord(key, record);
}

void DBSheet::removeRecord( int key )
{
	std::map<int, DBRecord*>::iterator iter = _records.find(key);
	if (iter != _records.end())
	{
		SAFE_DELETE(iter->second);
		_records.erase(iter);
	}
}

DBRecord* DBSheet::getRecord( int key )
{
	std::map<int, DBRecord*>::iterator iter = _records.find(key);
	if (iter != _records.end())
	{
		return iter->second;
	}

	return nullptr;
}

std::map<int, DBRecord*>::const_iterator DBSheet::beginRecord() const
{
	return _records.begin();
}

std::map<int, DBRecord*>::const_iterator DBSheet::endRecord() const
{
	return _records.end();
}

void DBSheet::clear()
{
	std::map<int, DBRecord*>::iterator iter = _records.begin();
	if (iter != _records.end())
	{
		SAFE_DELETE(iter->second);
		iter++;
	}
}


