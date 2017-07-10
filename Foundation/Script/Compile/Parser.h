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
	public:
		Parser();
		~Parser();
	public:
		// 单行和嵌套
		bool parse(Token::const_iterator begin, Token::const_iterator end);
		// 语法树组
		const std::vector<ASTNode*>& getASTNodeList() { return m_pASTNodeList; }
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
		ASTNode* parseSingleASTNode(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset);
	private:
		// 语法树组
		std::vector<ASTNode*> m_pASTNodeList;
	};
}
