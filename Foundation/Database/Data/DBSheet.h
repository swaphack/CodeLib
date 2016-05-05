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
		DBSheet(DBTable* table);
		virtual ~DBSheet();
	public:
		// 重新加载表结构，结构同步
		// 表结构发生修改，表数据也要修改
		void reloadStruct(DBTable* table);
		// 获取表结构
		const DBTable* getTable() const;

		void addRecord(DBRecord* record);
		// 添加纪录
		void addRecord(int key, DBRecord* record);
		// 移除纪录
		void removeRecord(int key);
		// 获取纪录
		DBRecord* getRecord(int key);

		// 纪录迭代器
		std::map<int, DBRecord*>::const_iterator beginRecord() const;
		std::map<int, DBRecord*>::const_iterator endRecord() const;

		// 清除记录
		void clear();
	protected:
		// 表结构(指针引用)
		DBTable* _table;
		// 表数据
		std::map<int, DBRecord*> _records;
	};
}