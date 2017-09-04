#pragma once

#include "IDataRecord.h"

#include <map>
#include <string>

namespace sys
{
	class IDataSheet
	{
	public:
		virtual ~IDataSheet() {}
	public:
		// 创建一条记录
		virtual IDataRecord* create() = 0;
		// 记录个数
		virtual int count() = 0;
		// 重置游标
		virtual void reset() = 0;
		// 清空数据
		virtual void clear() = 0;
		// 读取下一条记录
		virtual IDataRecord* next() = 0;
	};
}