#include "Parser.h"

using namespace script;

Parser::Parser()
{
	m_pSyntaxAnalysis = new SyntaxAnalysis();
}

Parser::~Parser()
{
	delete m_pSyntaxAnalysis;
}

bool Parser::parse(Token::const_iterator begin, Token::const_iterator end)
{


	return false;
}
