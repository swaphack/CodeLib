#include "DBWarehouse.h"

using namespace db;

DBWarehouse::DBWarehouse()
{

}

DBWarehouse::~DBWarehouse()
{
	this->removeAllSheets();
}

void DBWarehouse::addSheet( const char* name, DBSheet* sheet )
{
	if (name == nullptr || sheet == nullptr)
	{
		return;
	}
	
	ASSERT(_sheets[name] == nullptr);

	_sheets[name] = sheet;
}

void DBWarehouse::removeSheet( const char* name )
{
	if (name == nullptr)
	{
		return;
	}

	std::map<std::string, DBSheet*>::iterator iter = _sheets.find(name);
	if (iter != _sheets.end())
	{
		delete iter->second;
		_sheets.erase(iter);
	}
}

DBSheet* DBWarehouse::getSheet( const char* name )
{
	if (name == nullptr)
	{
		return nullptr;
	}

	std::map<std::string, DBSheet*>::iterator iter = _sheets.find(name);
	if (iter != _sheets.end())
	{
		return iter->second;
	}

	return nullptr;
}

void DBWarehouse::removeAllSheets()
{
	std::map<std::string, DBSheet*>::iterator iter = _sheets.begin();
	while (iter != _sheets.end())
	{
		delete iter->second;
		iter++;
	}

	_sheets.clear();
}

void DBWarehouse::truncate()
{
	std::map<std::string, DBSheet*>::iterator iter = _sheets.begin();
	while (iter != _sheets.end())
	{
		iter->second->clear();
		iter++;
	}
}
