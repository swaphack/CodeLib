#pragma once

#include "IDataSheet.h"
#include <vector>
#include <cstdint>
#include <map>
#include <string>

namespace sys
{
	class DataSheet : public IDataSheet
	{
	public:
		DataSheet();
		virtual ~DataSheet();
	public:
		// 设置关键字
		virtual void setKey(const std::string& key);
		// 查找关键字
		virtual const std::string& getKey();
		// 创建一条带主键的记录
		virtual IDataRecord* create();
		// 索引记录
		virtual const IDataRecord* operator[](int32_t index);
		// 按照主键设置记录
		virtual void setRecord(const std::string& key, const IDataRecord* record);
		// 按照主键查找
		virtual const IDataRecord* getRecord(const std::string& key);
		// 记录个数
		virtual int32_t count();
		// 清除所有记录
		virtual void clear();
	private:
		// 主键
		std::string _key;
		// 顺序记录数据
		std::vector<IDataRecord*> _records;
		// 主键记录数据
		std::map<std::string, IDataRecord*> _keyRecords;
	};
}