#include "SQLite.h"

#ifndef USE_SQLITE
#define USE_SQLITE
#include "third_party.h"
#endif


using namespace web;
using namespace sys;

SQLiteString::SQLiteString(IDataBase* db)
:_db(db)
{
	ASSERT(db != nullptr);
}

SQLiteString::~SQLiteString()
{

}

bool SQLiteString::excuteSQL(const char* sqlExpression, sys::IDataSheet* pDataSheet /*= nullptr*/)
{
	if (sqlExpression == nullptr)
	{
		return false;
	}
	return _db->executeSQL(sqlExpression, pDataSheet);
}

//////////////////////////////////////////////////////////////////////////
SQLite::SQLite()
:_instance(nullptr)
, _dbString(nullptr)
{

}

SQLite::~SQLite()
{
	this->disconnect();
	SAFE_DELETE(_dbString);
}

bool SQLite::connect(const char* url, const char* username /*= nullptr*/, const char* password /*= nullptr*/)
{
	if (url == nullptr)
	{
		return false;
	}

	int result = sqlite3_open(url, &_instance);
	if (result == SQLITE_OK)
	{
		SAFE_DELETE(_dbString);
		_dbString = new SQLiteString(this);
		return true;
	}

	return false;
}

bool SQLite::disconnect()
{
	int result = sqlite3_close(_instance);
	return result == SQLITE_OK;
}

int onExecCallback(void* inParams, int argc, char** argv, char** colName)
{
	if (inParams = nullptr)
	{
		return 0;
	}

	IDataSheet* pSheet = static_cast<IDataSheet*>(inParams);

	IDataRecord* pRecord = pSheet->create();
	if (pSheet == nullptr)
	{
		return 0;
	}

	for (int i = 0; i < argc; i++)
	{
		pRecord->setValue(colName[i], argv[i]);
	}

	return 0;
}

bool SQLite::executeSQL(const char* sqlExpression, IDataSheet* pDataSheet)
{
	int result;
	if (pDataSheet)
	{
		result = sqlite3_exec(_instance, sqlExpression, onExecCallback, pDataSheet, nullptr);
	}
	else
	{
		result = sqlite3_exec(_instance, sqlExpression, nullptr, nullptr, nullptr);
	}

	return result == SQLITE_OK;
}

IDBString* SQLite::getDBString()
{
	return _dbString;
}
