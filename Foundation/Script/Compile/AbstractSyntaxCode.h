#pragma once

#include <string>

namespace script
{
	// 语法书节点
	struct ASTNode
	{
		std::string vale;
		ASTNode* left;
		ASTNode* right;
	};

	// 抽象语法树
	class AbstractSyntaxCode
	{
	public:
		AbstractSyntaxCode();
		~AbstractSyntaxCode();
	public:
		bool load(Token::const_iterator begin, Token::const_iterator end);
	protected:
	private:
	};
}