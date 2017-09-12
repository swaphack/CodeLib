#pragma once

#include "system.h"

namespace web
{
	// db ���
	class DBString : public sys::IDBString
	{
	public:
		DBString(sys::IDataBase* db);
		virtual ~DBString();
	public:
		virtual bool excuteSQL(const char* sqlExpression, sys::IDataSheet* pDataSheet = nullptr);
	private:
		sys::IDataBase* _db;
	};
}