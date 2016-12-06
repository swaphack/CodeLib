#pragma once

#include "IDataSheet.h"
#include "IDBString.h"

namespace sys
{
	class IDataBase
	{
	public:
		virtual ~IDataBase() {}
	public:
		// ------------------ 数据库连接操作 ------------------ 
		// 连接数据库
		virtual bool connect(const char* url, const char* username = nullptr, const char* password = nullptr) = 0;
		// 断开数据库连接
		virtual bool disconnect() = 0;
		// 执行sql语句
		virtual bool executeSQL(const char* sqlExpression, IDataSheet* pDataSheet = nullptr) = 0;
		// 获取db操纵语句
		virtual IDBString* getDBString() = 0;
	};
}