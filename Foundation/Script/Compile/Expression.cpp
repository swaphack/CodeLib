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
	return begin;
}

