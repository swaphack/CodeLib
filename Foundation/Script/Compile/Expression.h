#pragma once

#include "macros.h"

namespace script
{
	class AbstractSyntaxTree;
	// 表达式
	class Expression
	{
	public:
		Expression();
		~Expression();
	public:
		// 解析
		Token::const_iterator read(Token::const_iterator begin, Token::const_iterator end);
	};
}