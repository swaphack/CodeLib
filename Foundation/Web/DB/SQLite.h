#pragma once

#include "IDataBase.h"

struct sqlite3;

namespace web
{
	// mysql 数据
	class SQLite : public IDataBase
	{
	public:
		SQLite();
		virtual ~SQLite();
	public:
		// 连接数据库
		virtual bool connect(const char* url, int port = 0, const char* username = nullptr, const char* password = nullptr);
		// 断开数据库连接
		virtual bool disconnect();
		// 执行sql语句
		virtual bool exec_sql(const char* sqlExpression, IDataSheet* pDataSheet = nullptr);
	private:
		sqlite3* _instance;
	};
}