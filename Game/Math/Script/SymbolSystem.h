#pragma once

#include <string>

namespace math
{
	// 符号系统
	class SymbolSystem
	{
	public:
		SymbolSystem();
		virtual ~SymbolSystem();
	public:
		// 添加符号
		void addSymbol(const char* value);
		// 移除符号
		void removeSymbol(const char* value);
		// 是否定义了符号
		bool hasSymbol(const char* value);
		// 清除所有符号
		void clearAllSymbols();
	protected:
	private:
	};
}