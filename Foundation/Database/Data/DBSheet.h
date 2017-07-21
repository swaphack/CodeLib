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
		// 移除记录
		void removeRecord(int index);
		// 获取纪录
		DBRecord* getRecord(int index);
		// 是否有改记录
		bool findRecord(DBRecord* record);
		// 记录数
		int count();
		// 清除记录
		void clear();
	protected:
		// 表数据
		std::vector<DBRecord*> _records;
	};
}