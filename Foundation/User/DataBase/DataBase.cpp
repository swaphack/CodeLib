#include "DataBase.h"

using namespace user;

DataBase::DataBase( long type, const char* url )
	:_type(type)
	,_url(url)
{

}

DataBase::~DataBase()
{

}


long DataBase::getType()
{
	return _type;
}


const char* DataBase::getUrl()
{
	return _url.c_str();
}


void DataBase::load()
{

}


void DataBase::save()
{

}

void DataBase::addRecord( long id, IDBRecord* record )
{
	_records[id] = record;
}

void DataBase::removeRecord( long id )
{
	if (_records.find(id) != _records.end())
	{
		IDBRecord* record = _records[id];
		_records.erase(id);
		delete record;
	}
}

IDBRecord* DataBase::getRecord( long id )
{
	if (_records.find(id) != _records.end())
	{
		return _records[id];
	}

	return nullptr;
}

void DataBase::flush()
{
	this->save();

	std::map<long, IDBRecord*>::iterator it = _records.begin();

	while (it != _records.end())
	{
		delete it->second;

		it++;
	}

	_records.clear();
}