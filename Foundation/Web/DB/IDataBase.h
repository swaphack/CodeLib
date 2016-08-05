#pragma once

#include "IDataSheet.h"

namespace web
{
	class IDataBase
	{
	public:
		virtual ~IDataBase() {}
	public:
		// ------------------ 数据库连接操作 ------------------ 
		// 连接数据库
		virtual bool connect(const char* url, int port = 0, const char* username = nullptr, const char* password = nullptr) = 0;
		// 断开数据库连接
		virtual bool disconnect() = 0;
		// 执行sql语句
		virtual bool exec_sql(const char* sqlExpression, IDataSheet* pDataSheet = nullptr) = 0;
	};
}