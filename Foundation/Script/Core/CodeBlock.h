#pragma once

#include <vector>

namespace script
{
	class Variable;
	class Expression;
	// �����
	class CodeBlock
	{
	public:
		CodeBlock();
		virtual ~CodeBlock();
	public:
		// ��ӱ��ʽ
		void addExpression(Expression* expression);
		// �Ƴ����б��ʽ
		void removeAllExpressions();
		// ִ�д����߼�
		bool run(std::vector<Variable*>& inputs, std::vector<Variable*>& outputs);
	private:
		typedef std::vector<Expression*>  Expressions;

		// ���ʽ
		Expressions m_pExpressions;
	};
}