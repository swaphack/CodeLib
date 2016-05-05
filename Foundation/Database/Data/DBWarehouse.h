#pragma once

#include "system.h"
#include "DBSheet.h"

#include <map>
#include <string>

namespace db
{
	// 数据仓库
	class DBWarehouse
	{
	public:
		DBWarehouse();
		virtual ~DBWarehouse();
	public:
		// 添加表
		void addSheet(const char* name, DBSheet* sheet);
		// 移除表
		void removeSheet(const char* name);
		// 获取表
		DBSheet* getSheet(const char* name);
		// 清空表
		void removeAllSheets();
		// 清除表数据
		void truncate();
	protected:
		// 表
		std::map<std::string, DBSheet*> _sheets;
	};
}