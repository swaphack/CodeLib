#pragma once

#include "macros.h"

#include <vector>

namespace script
{
	class ASTNode;
	/**
	*	语法分析
	*	a * (1 + a) / (c[3] - 2)
	*	*(+/[-
	*/
	class Parser
	{
	private:
		typedef std::vector<Token> TokenAry;
	public:
		Parser();
		~Parser();
	public:
		// 单行和嵌套
		bool parse(Token::const_iterator begin, Token::const_iterator end, std::vector<ASTNode*>& nodeAry);
	protected:
		/**
		*	解析单一节点
		*/
		ASTNode* parseSingleNode(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset);
		/**
		*	解析并生成单一节点的语法树
		*	使用vector存储解析数据
		*	vector每一层数据存储AST结构，以左节点，符号，右节点的顺序存储
		*	如果包含嵌套的话，嵌套从右节点扩展
		*/
		bool parseSingleASTNode(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset, TokenAry& tokenStack);
		/**
		*	根据语法树，生成AST节点
		*/
		bool makeSingleAstNode(TokenAry::const_reverse_iterator tokenAryBegin, TokenAry::const_reverse_iterator tokenAryEnd, ASTNode* pNode);
	};
}
