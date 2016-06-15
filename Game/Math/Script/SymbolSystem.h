#pragma once

#include <string>

#include "Symbol.h"

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
		void addSymbol(Symbol* value);
		// 移除符号
		void removeSymbol(Symbol* value);
		// 是否定义了符号
		bool hasSymbol(Symbol* value);
		// 清除所有符号
		void clearAllSymbols();
	protected:
	private:
	};
}