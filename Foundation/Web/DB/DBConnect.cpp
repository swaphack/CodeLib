#include "DBConnect.h"
#include "SQLite.h"

using namespace web;

DBConnect::DBConnect()
{

}

DBConnect::~DBConnect()
{

}

DBConnect* DBConnect::getInstance()
{
	static DBConnect* s_DBConnect = nullptr;
	if (s_DBConnect == nullptr)
	{
		s_DBConnect = new DBConnect();
	}

	return s_DBConnect;
}

SQLite* DBConnect::createSQLite(const char* url)
{
	if (url == nullptr)
	{
		return nullptr;
	}
	SQLite* db = new SQLite();
	if (db == nullptr)
	{
		return nullptr;
	}

	if (!db->connect(url))
	{
		delete db;
		return nullptr;
	}

	return db;
}
