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
		// 抽象语法树
		AbstractSyntaxTree* getAST();
		// 解析
		bool read(Token::const_iterator begin, Token::const_iterator end);
	protected:
	private:
		// 抽象语法树
		AbstractSyntaxTree* m_pAST;
	};
}