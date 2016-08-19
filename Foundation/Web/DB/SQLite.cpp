#include "SQLite.h"

#ifndef USE_SQLITE
#define USE_SQLITE
#endif
#include "third_party.h"

using namespace sys;

SQLite::SQLite()
:_instance(nullptr)
{

}

SQLite::~SQLite()
{

}

bool SQLite::connect(const char* url, const char* username /*= nullptr*/, const char* password /*= nullptr*/)
{
	if (url == nullptr)
	{
		return false;
	}

	int result = sqlite3_open(url, &_instance);
	return result == SQLITE_OK;
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

bool SQLite::exec_sql(const char* sqlExpression, IDataSheet* pDataSheet)
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
