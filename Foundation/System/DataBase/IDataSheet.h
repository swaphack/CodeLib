#pragma once

#include "IDataRecord.h"

#include "Base/Types.h"

namespace sys
{
	class IDataSheet
	{
	public:
		virtual ~IDataSheet() {}
	public:
		// 设置关键字
		virtual void setKey(const std::string& key) = 0;
		// 查找关键字
		virtual const char* getKey() = 0;
		// 创建一条带主键的记录
		virtual IDataRecord* create() = 0;
		// 索引记录
		virtual const IDataRecord* operator[](int32 index) { return nullptr; }
		// 按照主键设置记录
		virtual void setRecord(const std::string& key, const IDataRecord* record) = 0;
		// 按照主键查找
		virtual const IDataRecord* getRecord(const std::string& key) = 0;
		// 记录个数
		virtual int32 count() = 0;
		// 清空数据
		virtual void clear() = 0;
	};
}