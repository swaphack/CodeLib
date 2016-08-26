#pragma once

#include <string>

namespace web
{
	enum DataType
	{
		EDT_TEXT,		// 文本
		EDT_REAL,		// 实数
	};

	// 表成员
	struct TableMember
	{
		// 名称
		std::string Name;
		// 类型
		int DataType;
		// 长度
		int Length;
		// 默认值
		std::string Default;
		// 是否关键字
		bool PrimaryKey;
	};
}