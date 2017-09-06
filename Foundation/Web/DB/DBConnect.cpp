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

sys::IDataBase* DBConnect::create(const sys::Author& info, DBType type)
{
	if (type == DBType::SQLITT)
	{
		return create<SQLite>(info);
	}
	else
	{
		return nullptr;
	}
}
