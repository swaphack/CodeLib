#pragma once

#include "macros.h"

namespace script
{
	// 符号信息
	struct SymbolInformation
	{
		// 符号
		std::string name;
		// 表达式
		std::string expression;
		// 优先级
		int priorityLevel;

		// 是否内嵌
		bool embed;
		// 符号
		std::string begin;
		// 表达式
		std::string end;

		SymbolInformation()
			:name(""), expression(""), priorityLevel(0)
			, embed(false), begin(""), end(""){}
	};
}