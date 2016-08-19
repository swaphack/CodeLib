#pragma once

#include "macros.h"

#include <map>
#include <set>
#include <string>

namespace chem
{
	// 元素信息 {元素id,元素个数}
	typedef std::map<int, int> Elements;

	/**
	*	化学结构(一类物质的符号标识)
	*/
	class Constitution
	{
	public:
		Constitution();
		virtual ~Constitution();
	public:
		// 设置表达式
		virtual void setExpression(const char* expression);
		// 获取表达式
		const char* getExpression();
	protected:// 表达式
		std::string _expression;
	};
}