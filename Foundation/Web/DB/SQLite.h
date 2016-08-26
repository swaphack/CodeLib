#pragma once

#include "system.h"
#include "IDBString.h"

struct sqlite3;

namespace web
{
	class SQLiteString : public IDBString
	{
	public:
		SQLiteString(IDataBase* db);
		virtual ~SQLiteString();
	public:
		virtual bool createDataBase(const char* name);

		virtual bool deleteDataBase(const char* name);

		virtual bool createTable(const char* name, const std::vector<TableMember>& members);

		virtual bool deleteTable(const char* name);

		virtual bool selectTable(const char* name, sys::IDataSheet* pDataSheet = nullptr);
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
		virtual bool exec_sql(const char* sqlExpression, IDataSheet* pDataSheet = nullptr);

		const IDBString* getDBString();
	private:
		sqlite3* _instance;
		IDBString* _dbString;
	};
}