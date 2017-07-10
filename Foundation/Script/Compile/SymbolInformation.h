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
		// 开始符号
		std::string begin;
		// 结束符号
		std::string end;

		SymbolInformation()
			:name(""), expression(""), priorityLevel(0)
			, embed(false), begin(""), end(""){}

		// 是否是开始符号
		bool isBegin(const char* value) const {
			return begin == value;
		}

		// 是否是结束符号
		bool isEnd(const char* value) const {
			return end == value;
		}
	};
}