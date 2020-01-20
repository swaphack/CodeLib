#pragma once

#include "IDataSheet.h"
#include "IDBString.h"
#include "Security/Author.h"

namespace sys
{
	class IDataBase
	{
	public:
		virtual ~IDataBase() {}
	public:
		// ------------------ 数据库连接操作 ------------------ 
		// 连接数据库
		virtual bool connect(const Author& info) = 0;
		// 断开数据库连接
		virtual bool disconnect() = 0;
		// 执行sql语句
		virtual bool executeSQL(const std::string& sqlExpression, IDataSheet* pDataSheet = nullptr) = 0;
		// 获取db操纵语句
		virtual IDBString* getDBString() = 0;
	};
}