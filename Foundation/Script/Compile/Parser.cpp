#include "Parser.h"
#include "ASTNode.h"
#include "SymbolHandler.h"
#include <stack>

using namespace script;

Parser::Parser()
{
}

Parser::~Parser()
{
}

bool Parser::parse(Token::const_iterator begin, Token::const_iterator end)
{
	std::stack<ASTNode*> sASTNode;

	Token::const_iterator iter = begin;
	while (iter != end)
	{
		if ()
		{
		}
		iter++;
	}
	return false;
}
