#pragma once

#include <string>
#include <vector>


namespace sys
{
	class IDataSheet;
}

namespace web
{
	class TableMember;

	// 数据库操作语句
	class IDBString
	{
	public:
		virtual ~IDBString() {}
	public:
		// 查询表
		virtual bool excuteSQL(const char* name, sys::IDataSheet* pDataSheet = nullptr) = 0;
	};
}