#include "DBString.h"

using namespace web;


DBString::DBString(sys::IDataBase* db)
:_db(db)
{

}

DBString::~DBString()
{

}

bool DBString::excuteSQL(const std::string& sqlExpression, sys::IDataSheet* pDataSheet /*= nullptr*/)
{
	if (_db == nullptr || sqlExpression.empty())
	{
		return false;
	}

	return _db->executeSQL(sqlExpression, pDataSheet);
}
