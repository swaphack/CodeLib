#pragma once

#include "system.h"

struct sqlite3;

namespace web
{
	// SQLite 数据
	class SQLite : public sys::IDataBase
	{
	public:
		SQLite();
		virtual ~SQLite();
	public:
		// 连接数据库
		virtual bool connect(const sys::Author& info);
		// 断开数据库连接
		virtual bool disconnect();
		// 执行sql语句
		virtual bool executeSQL(const char* sqlExpression, sys::IDataSheet* pDataSheet = nullptr);
		// 获取db操纵
		virtual sys::IDBString* getDBString();
	private:
		sqlite3* _instance;
		sys::IDBString* _dbString;
	};
}