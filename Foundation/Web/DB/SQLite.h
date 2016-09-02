#pragma once

#include "system.h"
#include "IDBString.h"

struct sqlite3;

namespace web
{
	// sqlite 语句
	class SQLiteString : public IDBString
	{
	public:
		SQLiteString(IDataBase* db);
		virtual ~SQLiteString();
	public:
		virtual bool excuteSQL(const char* sqlExpression, sys::IDataSheet* pDataSheet = nullptr);
	private:
		IDataBase* _db;
	};

	// mysql 数据
	class SQLite : public sys::IDataBase
	{
	public:
		SQLite();
		virtual ~SQLite();
	public:
		// 连接数据库
		virtual bool connect(const char* url, const char* username = nullptr, const char* password = nullptr);
		// 断开数据库连接
		virtual bool disconnect();
		// 执行sql语句
		virtual bool executeSQL(const char* sqlExpression, IDataSheet* pDataSheet = nullptr);

		const IDBString* getDBString();
	private:
		sqlite3* _instance;
		IDBString* _dbString;
	};
}