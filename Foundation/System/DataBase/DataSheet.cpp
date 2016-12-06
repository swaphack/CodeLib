#include "DataSheet.h"
#include "DataRecord.h"

using namespace sys;

DataSheet::DataSheet()
{
	this->reset();
}

DataSheet::~DataSheet()
{
	this->clear();
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

int DataSheet::count()
{
	return _records.size();
}

void DataSheet::reset()
{
	_cursor = 0;
}

IDataRecord* DataSheet::next()
{
	if (_cursor >= this->count())
	{
		return nullptr;
	}

	IDataRecord* record = _records[_cursor];
	_cursor++;

	return record;
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
}