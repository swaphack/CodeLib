#pragma once

#include <vector>
#include <map>
#include <string>

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
		void addSymbolDelegate(SymbolDelegate* opeartor);
		// 移除解析
		void removeSymbolDelegate(SymbolDelegate* opeartor);
		// 移除所有解析
		void removeAllSymbolDelegates();
		// 查找解析
		SymbolDelegate* getSymbolDelegate(const char* name);
		// 匹配解析
		ASTNode* match(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset);
		// 加载配置文件
		bool load(const char* filepath);
	private:
		typedef std::map<std::string, SymbolDelegate*> SymbolDelegates;
		// 符号处理委托
		SymbolDelegates m_mSymbolDelegates;
	};
}