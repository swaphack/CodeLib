#include "Expression.h"
#include "AbstractSyntaxTree.h"

using namespace script;

Expression::Expression()
{
	m_pAST = new AbstractSyntaxTree();
}

Expression::~Expression()
{
	delete m_pAST;
}

AbstractSyntaxTree* Expression::getAST()
{
	return m_pAST;
}

bool Expression::read(Token::const_iterator begin, Token::const_iterator end)
{
	return false;
}

