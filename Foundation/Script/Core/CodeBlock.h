#pragma once

#include <vector>

namespace script
{
	class Variable;
	class Expression;
	// 代码块
	class CodeBlock
	{
	public:
		CodeBlock();
		virtual ~CodeBlock();
	public:
		// 添加表达式
		void addExpression(Expression* expression);
		// 移除所有表达式
		void removeAllExpressions();
		// 执行代码逻辑
		bool run(std::vector<Variable*>& inputs, std::vector<Variable*>& outputs);
	private:
		typedef std::vector<Expression*>  Expressions;

		// 表达式
		Expressions m_pExpressions;
	};
}