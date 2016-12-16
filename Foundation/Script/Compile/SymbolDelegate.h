#pragma once

#include <string>

#include "macros.h"

namespace script
{
	// 符号解析
	class SymbolDelegate
	{
	public:
		SymbolDelegate();
		virtual ~SymbolDelegate();
	public:
		// 获取符号
		const char* getSymbol();
		// 设置符号
		void setSymbol(const char* symbol);
		// 获取表达式
		const char* getExpression();
		// 设置表达式
		void setExpression(const char* text);
		// 优先级
		int getPriorityLevel();
		// 优先级
		void setPriorityLevel(int level);
		/**
		*	匹配解析
		*	@param expression 输入表达式
		*	@param offset 解析成功后的偏移值
		*	@reurn bool 是否解析成功
		*/
		virtual bool match(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset) = 0;
	protected:
		// 符号
		std::string m_strSymbol;
		// 表达式
		std::string m_strExpression;
		// 优先级
		int m_nPriorityLevel;
	};
}