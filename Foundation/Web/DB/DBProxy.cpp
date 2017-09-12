#include "DBProxy.h"
using namespace web;


DBProxy::DBProxy(sys::IDataBase* db)
{
	_db = db;
}

DBProxy::~DBProxy()
{
	SAFE_DELETE(_db);
}

bool DBProxy::load(const std::vector<std::string>& readTableNames, std::map<std::string, sys::DataSheet*>& tableSheet)
{
	if (_db == nullptr || readTableNames.size() == 0)
	{
		return false;
	}
	tableSheet.clear();

	sys::IDBString* pDBString = _db->getDBString();
	if (pDBString == nullptr)
	{
		return false;
	}

	std::vector<std::string>::const_iterator iter = readTableNames.begin();
	while (iter != readTableNames.end())
	{
		const char* pSqlString = getCString("select * from %s", (*iter).c_str());
		sys::DataSheet* pDataSheet = new sys::DataSheet();
		if (!pDBString->excuteSQL(pSqlString, pDataSheet))
		{
			PRINT("Read Table %s Error!\n", (*iter).c_str());
			delete pDataSheet;
			iter++;
			continue;
		}
		tableSheet[(*iter).c_str()] = pDataSheet;
		iter++;
	}
	
	return true;
}

bool DBProxy::insert(const char* tableName, const std::map<std::string, std::string>& values)
{
	if (_db == nullptr || tableName == nullptr || values.size() == 0)
	{
		return false;
	}

	std::string conditionValues = "";
	std::string changedValues = "";

	std::map<std::string, std::string>::const_iterator iter = values.begin();
	while (iter != values.end())
	{
		conditionValues.append(iter->first);
		changedValues.append(iter->second);
		iter++;

		if (iter != values.end())
		{
			conditionValues.append(",");
			changedValues.append(",");
		}
	}

	std::string pSqlString = getCString("insert into %s (%s) values (%s);", tableName, conditionValues.c_str(), changedValues.c_str());

	return exec(pSqlString.c_str());
}

bool DBProxy::del(const char* tableName, const std::map<std::string, std::string>& conditions)
{
	if (_db == nullptr || tableName == nullptr || conditions.size() == 0)
	{
		return false;
	}

	std::string conditionValues = "";

	std::map<std::string, std::string>::const_iterator iter = conditions.begin();
	while (iter != conditions.end())
	{
		conditionValues.append(iter->first);
		conditionValues.append("=");
		conditionValues.append(iter->second);
		iter++;

		if (iter != conditions.end())
		{
			conditionValues.append(",");
		}
	}

	std::string pSqlString = "";
	if (conditionValues.empty())
	{
		pSqlString = getCString("delete from %s;", tableName);
	}
	else
	{
		pSqlString = getCString("delete from %s where %s;", tableName, conditionValues.c_str());
	}

	return exec(pSqlString.c_str());
}

bool DBProxy::update(const char* tableName, const std::map<std::string, std::string>& conditions, const std::map<std::string, std::string>& values)
{
	if (_db == nullptr || tableName == nullptr || values.size() == 0)
	{
		return false;
	}

	std::string conditionValues = "";
	std::string changedValues = "";

	std::map<std::string, std::string>::const_iterator iter = conditions.begin();
	while (iter != conditions.end())
	{
		conditionValues.append(iter->first);
		conditionValues.append("=");
		conditionValues.append(iter->second);
		iter++;

		if (iter != conditions.end())
		{
			conditionValues.append(",");
		}
	}

	iter = values.begin();
	while (iter != values.end())
	{
		changedValues.append(iter->first);
		changedValues.append("=");
		changedValues.append(iter->second);
		iter++;

		if (iter != values.end())
		{
			changedValues.append(",");
		}
	}

	std::string pSqlString = "";
	if (conditionValues.empty())
	{
		pSqlString = getCString("update %s %s;", tableName, changedValues.c_str());
	}
	else
	{
		pSqlString = getCString("update %s %s where %s;", tableName, changedValues.c_str(), conditionValues.c_str());
	}

	return exec(pSqlString.c_str());
}

bool DBProxy::exec(const char* strSQL, sys::IDataSheet* pDataSheet)
{
	if (_db == nullptr || strSQL == nullptr)
	{
		return false;
	}
	sys::IDBString* pDBString = _db->getDBString();
	if (pDBString == nullptr)
	{
		return false;
	}
	bool result = pDBString->excuteSQL(strSQL, pDataSheet);
	if (result == false)
	{
		return false;
	}

	return true;
}
