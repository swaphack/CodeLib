#include "DBContent.h"
#include <vector>
using namespace db;

DBContent::DBContent()
{

}

DBContent::~DBContent()
{

}


void DBContent::addTable( const DBTable& dbTable )
{
	if (dbTable.getName().empty())
	{
		return;
	}
	_dbTables[dbTable.getName()] = dbTable;
}

void DBContent::removeTable( const std::string& tableName )
{
	if (tableName.empty())
	{
		return;
	}
	_dbTables.erase(tableName);
}

const DBTable* DBContent::getTable( const std::string& tableName )
{
	if (tableName.empty())
	{
		return nullptr;
	}

	std::map<std::string, DBTable>::const_iterator iter = _dbTables.find(tableName);

	if (iter != _dbTables.end())
	{
		return &iter->second;
	}

	return nullptr;
}

const std::map<std::string, DBTable>& DBContent::getTables() const
{
	return _dbTables;
}

void DBContent::removeAllTables()
{
	_dbTables.clear();
}


