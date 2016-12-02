#pragma once

#include "macros.h"

namespace script
{
	// 语法书节点
	struct ASTNode
	{
		// 节点值
		std::string vale;
		// 左节点
		ASTNode* left;
		// 右节点
		ASTNode* right;

		ASTNode() :left(nullptr), right(nullptr){}
	};

	// 抽象语法树
	class AbstractSyntaxTree
	{
	public:
		AbstractSyntaxTree();
		~AbstractSyntaxTree();
	public:
		bool load(Token::const_iterator begin, Token::const_iterator end);
	private:
		// 根节点
		ASTNode* m_pRoot;
	};
}