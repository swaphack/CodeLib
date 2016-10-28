#include "CodeBlock.h"
#include "Expression.h"

using namespace script;

CodeBlock::CodeBlock()
{

}

CodeBlock::~CodeBlock()
{

}

void CodeBlock::addExpression(Expression* expression)
{
	if (expression == nullptr)
	{
		return;
	}

	m_pExpressions.push_back(expression);
}

void CodeBlock::removeAllExpressions()
{
	Expressions::iterator iter = m_pExpressions.begin();
	while (iter != m_pExpressions.end())
	{
		delete *iter;
		iter++;
	}

	m_pExpressions.clear();
}

bool CodeBlock::run(std::vector<Variable*>& inputs, std::vector<Variable*>& outputs)
{
	Expressions::iterator iter = m_pExpressions.begin();
	while (iter != m_pExpressions.end())
	{
		bool result = (*iter)->run(inputs, outputs);
		if (!result)
		{
			return false;
		}
		iter++;
	}

	return true;
}
