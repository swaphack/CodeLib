#pragma once

#include <vector>

#include "SymbolDelegate.h"

namespace script
{
	// 操作符处理
	class SymbolHandler
	{
	private:
		SymbolHandler();
		~SymbolHandler();
	public:
		static SymbolHandler* getInstance();
		// 添加解析
		void addParser(SymbolDelegate* opeartor);
		// 移除解析
		void removeParser(SymbolDelegate* opeartor);
		// 移除所有解析
		void removeAllParsers();
		// 匹配解析
		bool match(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset);
	private:
		std::vector<SymbolDelegate*> m_mOperatorParsers;
	};
}