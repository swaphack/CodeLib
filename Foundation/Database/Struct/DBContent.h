#pragma once

#include "DBTable.h"

#include <string>
#include <map>

namespace db
{
	// 数据库目录
	class DBContent
	{
	public:
		DBContent();
		~DBContent();
	public:
		// 添加表结构
		void addTable(const DBTable& dbTable);
		// 移除表结构
		void removeTable(const char* tableName);
		// 获取表结构
		const DBTable* getTable(const char* tableName);
		// 移除所有表结构
		void removeAllTables();
		// 获取所有表
		const std::map<std::string, DBTable>& getTables() const;
	private:
		// 表集合
		std::map<std::string, DBTable> _dbTables;
	};
}