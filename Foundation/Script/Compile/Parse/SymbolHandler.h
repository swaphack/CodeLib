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
		SymbolDelegate* getSymbolDelegate(const std::string& name);
		// 加载配置文件
		bool load(const char* filepath);
	private:
		typedef std::map<std::string, SymbolDelegate*> SymbolDelegates;
		// 符号处理委托
		SymbolDelegates m_mSymbolDelegates;
		// 内联开始符号处理委托
		SymbolDelegates m_mEmbedBeginSymbolDelegates;
		// 内联结束符号处理委托
		SymbolDelegates m_mEmbedEndSymbolDelegates;
	};
}