#pragma once

#include "macros.h"
#include "ASTNode.h"

#include <stack>

namespace script
{
	// 抽象语法树
	class AbstractSyntaxTree
	{
	public:
		AbstractSyntaxTree();
		~AbstractSyntaxTree();
	public:
		bool load(Token::const_iterator begin, Token::const_iterator end);
	protected:
		// 创建表达式
		bool createExpression(ASTNode* node, Token::const_iterator& iter, Token::const_iterator& end);
		// 创建代码块
		bool createBlock(ASTNode* node, Token::const_iterator& iter, Token::const_iterator& end);
	private:
		// 根节点
		ASTNode* m_pRoot;
	};
}