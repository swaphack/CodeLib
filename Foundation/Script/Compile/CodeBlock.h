#pragma once

#include <string>
#include <vector>

namespace script
{
	class Expression;

	// �����
	class CodeBlock
	{
	public:
	protected:
	private:
		typedef std::vector<Expression*> Expressions;
		// ���ʽ
		Expressions m_pExpressions;
	};
}