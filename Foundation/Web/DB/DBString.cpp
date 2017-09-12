#include "DBString.h"

using namespace web;


DBString::DBString(sys::IDataBase* db)
:_db(db)
{

}

DBString::~DBString()
{

}

bool DBString::excuteSQL(const char* sqlExpression, sys::IDataSheet* pDataSheet /*= nullptr*/)
{
	if (_db	 == nullptr || sqlExpression == nullptr)
	{
		return false;
	}

	return _db->executeSQL(sqlExpression, pDataSheet);
}
