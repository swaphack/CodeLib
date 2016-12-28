#pragma once

#include "macros.h"

#include <stack>

namespace script
{
	/**
	*	语法分析
	*/
	class Parser
	{
	public:
		Parser();
		~Parser();
	public:
		bool parse(Token::const_iterator begin, Token::const_iterator end);
	protected:
		// 判断格式是否正确
		bool isRightFormat(Token::const_iterator begin, Token::const_iterator end);
		// 判断是否可以生成抽象语法树
		bool isASTFormat(Token::const_iterator begin, Token::const_iterator end);
	};
}
