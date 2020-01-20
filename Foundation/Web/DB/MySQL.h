#pragma once

#include "system.h"

struct st_mysql;

namespace web
{
	// MySQL 数据
	class MySQL : public sys::IDataBase
	{
	public:
		MySQL();
		virtual ~MySQL();
	public:
		// 连接数据库
		virtual bool connect(const sys::Author& info);
		// 断开数据库连接
		virtual bool disconnect();
		// 执行sql语句
		virtual bool executeSQL(const std::string& sqlExpression, sys::IDataSheet* pDataSheet = nullptr);
		// 获取db操纵
		virtual sys::IDBString* getDBString();
	private:
		st_mysql* _instance;
		sys::IDBString* _dbString;
	};
}