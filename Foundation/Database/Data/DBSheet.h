#pragma once

#include "../Struct/DBTable.h"
#include "DBRecord.h"
#include "system.h"

#include <string>
#include <map>

namespace db
{
	// 数据表
	class DBSheet
	{
	public:
		DBSheet();
		virtual ~DBSheet();
	public:
		// 添加纪录
		void addRecord(DBRecord* record);
		// 移除纪录
		void removeRecord(DBRecord* record);
		void removeRecord(int index);
		// 获取纪录
		DBRecord* getRecord(int index);
		bool findRecord(DBRecord* record);

		int count();

		// 清除记录
		void clear();
	protected:
		// 表数据
		std::vector<DBRecord*> _records;
	};
}