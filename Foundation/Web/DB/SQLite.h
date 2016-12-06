#pragma once

#include "system.h"

struct sqlite3;

namespace web
{
	// sqlite 语句
	class SQLiteString : public sys::IDBString
	{
	public:
		SQLiteString(sys::IDataBase* db);
		virtual ~SQLiteString();
	public:
		virtual bool excuteSQL(const char* sqlExpression, sys::IDataSheet* pDataSheet = nullptr);
	private:
		sys::IDataBase* _db;
	};

	// SQLite 数据
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
		virtual bool executeSQL(const char* sqlExpression, sys::IDataSheet* pDataSheet = nullptr);
		// 获取db操纵
		virtual sys::IDBString* getDBString();
	private:
		sqlite3* _instance;
		sys::IDBString* _dbString;
	};
}