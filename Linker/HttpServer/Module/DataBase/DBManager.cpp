#include "DBManager.h"

using namespace hs;

DBManager::DBManager()
{

}

DBManager::~DBManager()
{
	clearDataSheets();
}

DBManager* DBManager::getInstance()
{
	static DBManager* s_DBManager = nullptr;
	if (s_DBManager == nullptr)
	{
		s_DBManager = new DBManager();
	}

	return s_DBManager;
}

bool DBManager::init(const sys::Author& info, std::vector<std::string> readTableNames)
{
	_db = web::DBConnect::getInstance()->create<web::SQLite>(info);
	if (_db	 == nullptr)
	{
		return false;
	}

	sys::IDBString* pDBString = _db->getDBString();

	std::vector<std::string>::const_iterator iter = readTableNames.begin();
	while (iter != readTableNames.end())
	{
		const char* pSqlString = getCString("select * from %s", (*iter).c_str());
		sys::DataSheet* pDataSheet = new sys::DataSheet();
		if (!pDBString->excuteSQL(pSqlString, pDataSheet))
		{
			PRINT("Read Table %s Error!\n", (*iter).c_str());
		}
		addDataSheet((*iter).c_str(), pDataSheet);
		iter++;
	}

	return true;
}

bool DBManager::update(const char* tableName, const std::map<std::string, std::string>& keys, const std::map<std::string, std::string>& values)
{
	if (tableName == nullptr)
	{
		return false;
	}

	bool bRet = updateDataBase(tableName, keys, values);
	if (bRet == false)
	{
		return false;
	}

	bRet = updateMemory(tableName, keys, values);

	return bRet;
}

bool DBManager::insert(const char* tableName, const std::map<std::string, std::string>& values)
{
	if (tableName == nullptr)
	{
		return false;
	}

	bool bRet = insertDataBase(tableName, values);
	if (bRet == false)
	{
		return false;
	}

	if (getDataSheet(tableName) == nullptr)
	{
		addDataSheet(tableName, new sys::DataSheet());
	}

	bRet = insertMemory(tableName, values);

	return bRet;
}

sys::IDataRecord* DBManager::find(const char* tableName, const std::map<std::string, std::string>& values)
{
	if (tableName == nullptr)
	{
		return nullptr;
	}

	sys::DataSheet* pSheet = getDataSheet(tableName);
	if (pSheet == nullptr)
	{
		return nullptr;
	}

	pSheet->reset();

	sys::IDataRecord* pRecord = nullptr;
	bool bFind = false;
	while (pRecord = pSheet->next())
	{
		bFind = true;
		for (std::map<std::string, std::string>::const_iterator cit = values.begin();
			cit != values.end();
			cit++)
		{
			if (cit->second.compare(pRecord->getValue(cit->first.c_str())) != 0)
			{
				bFind = false;
				break;
			}
		}

		if (bFind)
		{
			pSheet->reset();
			return pRecord;
		}
	}

	pSheet->reset();
	return nullptr;
}

void DBManager::addDataSheet(const char* tableName, sys::DataSheet* pDataSheet)
{
	if (tableName == nullptr || pDataSheet == nullptr)
	{
		return;
	}

	removeDataSheet(tableName);

	_tableSheet[tableName] = pDataSheet;
}

void DBManager::removeDataSheet(const char* tableName)
{
	if (tableName == nullptr )
	{
		return;
	}

	if (_tableSheet.find(tableName) == _tableSheet.end())
	{
		return;
	}

	delete _tableSheet[tableName];
	_tableSheet.erase(tableName);

}

sys::DataSheet* DBManager::getDataSheet(const char* tableName)
{
	if (tableName == nullptr)
	{
		return nullptr;
	}

	if (_tableSheet.find(tableName) == _tableSheet.end())
	{
		return nullptr;
	}

	return _tableSheet[tableName];
}

void DBManager::clearDataSheets()
{
	std::map<std::string, sys::DataSheet*>::iterator iter = _tableSheet.begin();
	while (iter != _tableSheet.end())
	{
		delete iter->second;
		iter++;
	}

	_tableSheet.clear();
}

bool DBManager::updateMemory(const char* tableName, const std::map<std::string, std::string>& keys, const std::map<std::string, std::string>& values)
{
	sys::DataSheet* pDataSheet = getDataSheet(tableName);
	if (pDataSheet == nullptr)
	{
		return false;
	}

	pDataSheet->reset();

	std::map<std::string, std::string>::const_iterator iter = keys.begin();

	sys::IDataRecord* pDataRecord = nullptr;
	bool bFind = true;
	const char* keyValue = nullptr;
	while ((pDataRecord == pDataSheet->next()))
	{
		bFind = true;
		while (iter != keys.end())
		{
			keyValue = pDataRecord->getValue(iter->first.c_str());
			if ((keyValue == nullptr)
				|| (strcmp(keyValue, iter->second.c_str()) != 0))
			{
				bFind = false;
				break;
			}
			iter++;
		}

		if (bFind == true)
		{
			iter = values.begin();
			while (iter != values.end())
			{
				pDataRecord->setValue(iter->first.c_str(), iter->second.c_str());
				iter++;
			}
		}
	}

	return true;
}

bool DBManager::insertMemory(const char* tableName, const std::map<std::string, std::string>& values)
{
	sys::DataSheet* pDataSheet = getDataSheet(tableName);
	if (pDataSheet == nullptr)
	{
		return false;
	}

	sys::IDataRecord* pDataRecord = pDataSheet->create();

	std::map<std::string, std::string>::const_iterator iter = values.begin();
	while (iter != values.end())
	{
		pDataRecord->setValue(iter->first.c_str(), iter->second.c_str());
		iter++;
	}

	return true;
}


bool DBManager::updateDataBase(const char* tableName, const std::map<std::string, std::string>& keys, const std::map<std::string, std::string>& values)
{
	std::string conditionValues = "";
	std::string changedValues = "";

	std::map<std::string, std::string>::const_iterator iter = keys.begin();
	while (iter != keys.end())
	{
		conditionValues.append(iter->first);
		conditionValues.append("=");
		conditionValues.append(iter->second);
		iter++;

		if (iter != keys.end())
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

		if (iter != keys.end())
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

	sys::IDBString* pDBString = _db->getDBString();
	bool result = pDBString->excuteSQL(pSqlString.c_str());
	if (result == false)
	{
		return false;
	}

	return true;
}

bool DBManager::insertDataBase(const char* tableName, const std::map<std::string, std::string>& values)
{
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
	sys::IDBString* pDBString = _db->getDBString();
	bool result = pDBString->excuteSQL(pSqlString.c_str());
	if (result == false)
	{
		return false;
	}

	return true;
}
