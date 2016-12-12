#include "Expression.h"
#include "AbstractSyntaxTree.h"

#include <stack>

using namespace script;

Expression::Expression()
{
}

Expression::~Expression()
{
}

Token::const_iterator Expression::read(Token::const_iterator begin, Token::const_iterator end)
{
	std::stack<>
	Token::const_iterator iter = begin;
	while (iter != end)
	{
		

		iter++;
	}
	return begin;
}

