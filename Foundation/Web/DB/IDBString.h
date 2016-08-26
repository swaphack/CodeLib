#pragma once

#include <string>
#include <vector>

namespace sys
{
	class IDataSheet;
}

namespace web
{
	// 数据库操作语句
	class IDBString
	{
	public:
		virtual ~IDBString() {}
	public:
		// 创建数据库
		virtual bool createDataBase(const char* name) = 0;
		// 删除数据库
		virtual bool deleteDataBase(const char* name) = 0;
		// 创建新表
		virtual bool createTable(const char* name, const std::vector<TableMember>& members) = 0;
		// 删除表
		virtual bool deleteTable(const char* name) = 0;
		// 查询表
		virtual bool selectTable(const char* name, sys::IDataSheet* pDataSheet = nullptr) = 0;
	};
}