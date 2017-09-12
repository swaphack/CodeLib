#include "SQLite.h"
#include "DBString.h"

#ifndef USE_SQLITE
#define USE_SQLITE
#include "third_party.h"
#endif

using namespace web;

//////////////////////////////////////////////////////////////////////////
SQLite::SQLite()
:_instance(nullptr)
, _dbString(nullptr)
{
	_dbString = new DBString(this);
}

SQLite::~SQLite()
{
	this->disconnect();
	SAFE_DELETE(_dbString);
}

bool SQLite::connect(const sys::Author& info)
{
	if (info.host.empty())
	{
		return false;
	}

	this->disconnect();

	int result = sqlite3_open(info.host.c_str(), &_instance);
	if (result != SQLITE_OK)
	{
		return false;
	}
	
	return true;
}

bool SQLite::disconnect()
{
	if (_instance == nullptr)
	{
		return false;
	}
	int result = sqlite3_close(_instance);
	bool bRet = result == SQLITE_OK;
	if (bRet )
	{
		_instance = nullptr;
	}

	return bRet;
}

int onExecCallback(void* inParams, int argc, char** argv, char** colName)
{
	if (inParams == nullptr)
	{
		return 0;
	}

	sys::IDataSheet* pSheet = static_cast<sys::IDataSheet*>(inParams);

	sys::IDataRecord* pRecord = pSheet->create();
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

bool SQLite::executeSQL(const char* sqlExpression, sys::IDataSheet* pDataSheet)
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

sys::IDBString* SQLite::getDBString()
{
	return _dbString;
}
