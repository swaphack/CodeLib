#include "DataSheet.h"
#include "DataRecord.h"

using namespace sys;

DataSheet::DataSheet()
{
}

DataSheet::~DataSheet()
{
	this->clear();
}

void DataSheet::setKey(const std::string& key)
{
	_key = key;
}

const std::string& DataSheet::getKey() const
{
	return _key;
}

IDataRecord* DataSheet::create()
{
	IDataRecord* record = new DataRecord();
	if (record)
	{
		_records.push_back(record);
	}

	return record;
}

const IDataRecord* DataSheet::operator[](int32_t index)
{
	if (index < 0 || index >= count())
	{
		return nullptr;
	}

	return _records[index];
}

void DataSheet::setRecord(const std::string& key, const IDataRecord* record)
{
	_keyRecords[key] = (IDataRecord*)record;
}

const IDataRecord* DataSheet::getRecord(const std::string& key) const 
{
	auto it = _keyRecords.find(key);
	if (it == _keyRecords.end())
	{
		return nullptr;
	}

	return it->second;
}


int32_t DataSheet::count()const
{
	return _records.size();
}

void DataSheet::clear()
{
	std::vector<IDataRecord*>::iterator iter = _records.begin();

	while (iter != _records.end())
	{
		delete (*iter);
		iter++;
	}

	_records.clear();
	_keyRecords.clear();
}