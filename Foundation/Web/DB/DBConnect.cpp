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