#include "MySQL.h"
#include "DBAuthor.h"
#include "DBString.h"

#ifndef USE_MYSQL
#define USE_MYSQL
#include "third_party.h"
#endif

using namespace web;

//////////////////////////////////////////////////////////////////////////

MySQL::MySQL()
:_instance(nullptr)
{
	_dbString = new DBString(this);
}

MySQL::~MySQL()
{
	this->disconnect();
	SAFE_DELETE(_dbString);
}

bool MySQL::connect(const sys::Author& info)
{
	this->disconnect();

	_instance = mysql_init(nullptr);
	if (_instance == nullptr)
	{
		return false;
	}
	const DBAuthor& dbInfo = (const DBAuthor&)info;

	_instance = mysql_real_connect(_instance, dbInfo.host.c_str(), dbInfo.username.c_str(), dbInfo.password.c_str(), dbInfo.dbname.c_str(), dbInfo.port, nullptr, 0);
	if (_instance == nullptr)
	{
		return false;
	}	
	if (mysql_select_db(_instance, dbInfo.dbname.c_str()) != 0)
	{
		return false;
	}
	return true;
}

bool MySQL::disconnect()
{
	if (_instance == nullptr)
	{
		return false;
	}
	mysql_close(_instance);
	_instance = nullptr;

	return true;
}

bool MySQL::executeSQL(const std::string& sqlExpression, sys::IDataSheet* pDataSheet /*= nullptr*/)
{
	if (sqlExpression.empty())
	{
		return false;
	}
	int result = mysql_real_query(_instance, sqlExpression.c_str(), strlen(sqlExpression.c_str()));
	if (result != 0)
	{
		return false;
	}
	if (pDataSheet == nullptr)
	{
		return true;
	}

	MYSQL_RES* res = mysql_store_result(_instance);
	if (res == nullptr)
	{
		return false;
	}

	MYSQL_FIELD* field = mysql_fetch_fields(res);
	if (field == nullptr)
	{
		return false;
	}

	MYSQL_ROW row = nullptr;
	int count = mysql_num_fields(res);
	std::string key = pDataSheet->getKey();
	while (row = mysql_fetch_row(res))
	{
		sys::IDataRecord* pRecord = pDataSheet->create();
		if (pDataSheet == nullptr)
		{
			return false;
		}	
		for (int i = 0; i < count ; i++)
		{
			pRecord->setValue(field[i].name, row[i]);
			if (key.compare(field[i].name) == 0)
			{
				std::string value = row[i];
				pDataSheet->setRecord(value, pRecord);
			}
		}
	}

	mysql_free_result(res);
	return true;
}

sys::IDBString* MySQL::getDBString()
{
	return _dbString;
}
