#pragma once

#include "DBExpression.h"
#include "DBResult.h"

namespace db
{
	class DBQuery
	{
	public:
		virtual ~DBQuery() {}
	public:
		virtual DBResult query(DBExpression& expression) = 0;
	protected:
	private:
	};
}