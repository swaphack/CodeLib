#pragma once

#include "../Core/import.h"
#include <map>

namespace business
{
	class FinanceRecord;
	// 财务
	class Finance
	{
	public:
		Finance();
		virtual ~Finance();
	public:
		// 添加记录
		void addRecord(const FinanceRecord* pRecord);
		// 移除记录
		void removeRecord(uint64_t nRecordID);
		// 清除
		void clear();
		// 查找记录
		const FinanceRecord* getRecord(uint64_t nRecordID);
		// 获取所有记录
		const std::map<uint64_t, FinanceRecord*>& getRecords();
	private:
		// 记录信息
		std::map<uint64_t, FinanceRecord*> m_mapRecords;
	};
}