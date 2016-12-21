#pragma once

#include "macros.h"

#include "ASTNode.h"

#include "SymbolInformation.h"

namespace script
{	
	// 符号解析
	class SymbolDelegate
	{
	public:
		SymbolDelegate();
		virtual ~SymbolDelegate();
	public:
		// 符号信息
		inline SymbolInformation& getSymbolInformation() { return m_rSymbolInformation; }
		// 语法书节点模板
		inline const ASTNode& getASTTemplate() { return m_rASTTemplate; }

		// 生成语法节点
		bool makeASTNode();
		// 是否匹配格式
		bool match(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset);
		/**
		*	创建语法节点
		*	@param begin 输入表达式开始位置
		*	@param end 输入表达式结束位置
		*	@param offset 解析成功后的偏移值
		*	@return ASTNode 是否解析成功,解析成功返回语法节点，否则返回空
		*/
		ASTNode* makeASTNode(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset);
	protected:
		bool isFormat();
		// 设置索引
		ASTNode* setValue(ASTNode* pNode, char value);
		// 设置符号
		ASTNode* setValue(ASTNode* pNode, const char* value);
		// 遍历节点
		ASTNode* ergodicNode(ASTNode* pNode, Token::const_iterator iter);
	protected:
		// 语法节点模板
		ASTNode m_rASTTemplate;
		// 符号信息
		SymbolInformation m_rSymbolInformation;
	};
}