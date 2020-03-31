#pragma once

namespace sys
{
	class IDataSheet;

	// 数据库操作语句
	class IDBString
	{
	public:
		virtual ~IDBString() {}
	public:
		// 查询表
		virtual bool excuteSQL(const std::string& sqlExpression, sys::IDataSheet* pDataSheet = nullptr) = 0;
	};
}