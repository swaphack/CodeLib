#pragma once

#include <string>
#include <vector>

namespace script
{
	class Expression;

	// 代码块
	class CodeBlock
	{
	public:
	protected:
	private:
		typedef std::vector<Expression*> Expressions;
		// 表达式
		Expressions m_pExpressions;
	};
}