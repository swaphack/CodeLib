#pragma once

#include "Symbol.h"

namespace math
{
	// 符号定义
	class SymbolDefine
	{
	public:
		SymbolDefine();
		virtual ~SymbolDefine();
	public:
		// 导入符号定义字符串
		bool loadString(const char* value);

		const Symbol* getSymbol();
	protected:
	private:
		// 符号
		Symbol* _symbol;
		// 传入变量个数
		int _inputVarCount;
		// 传入变量值
		float* _inputValue;
		// 传出变量个数
		int _outputVarCount;
		// 传出变量值
		float* _outputValue;
	};
}