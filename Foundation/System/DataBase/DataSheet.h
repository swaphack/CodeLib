#pragma once

#include "IDataSheet.h"
#include <vector>

namespace sys
{
	class DataSheet : public IDataSheet
	{
	public:
		DataSheet();
		virtual ~DataSheet();
	public:
		// 创建一条记录
		virtual IDataRecord* create();
		// 记录个数
		virtual int count();
		// 重置读取游标
		virtual void reset();
		// 读取下一条记录
		virtual IDataRecord* next();
		// 清除所有记录
		virtual void clear();
	private:
		// 游标
		int _cursor;
		// 记录数据
		std::vector<IDataRecord*> _records;
	};
}