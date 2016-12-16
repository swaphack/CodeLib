#include "SymbolHandler.h"

using namespace script;


SymbolHandler::SymbolHandler()
{

}

SymbolHandler::~SymbolHandler()
{
	this->removeAllParsers();
}

SymbolHandler* SymbolHandler::getInstance()
{
	static SymbolHandler* s_OperatorHandler = nullptr;
	if (s_OperatorHandler == nullptr)
	{
		s_OperatorHandler = new SymbolHandler();
	}

	return s_OperatorHandler;
}

void SymbolHandler::addParser(SymbolDelegate* opeartor)
{
	if (opeartor == nullptr)
	{
		return;
	}

	m_mOperatorParsers.push_back(opeartor);
}

void SymbolHandler::removeParser(SymbolDelegate* opeartor)
{
	if (opeartor == nullptr)
	{
		return;
	}

	for (int i = 0; i < m_mOperatorParsers.size(); i++)
	{
		if (m_mOperatorParsers[i] == opeartor)
		{
			delete opeartor;
			m_mOperatorParsers.erase(m_mOperatorParsers.begin() + i);
			return;
		}
	}
}

void SymbolHandler::removeAllParsers()
{
	for (int i = 0; i < m_mOperatorParsers.size(); i++)
	{
		delete m_mOperatorParsers[i];
	}

	m_mOperatorParsers.clear();
}

bool SymbolHandler::match(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset)
{
	for (int i = 0; i < m_mOperatorParsers.size(); i++)
	{
		if (m_mOperatorParsers[i]->match(begin, end, offset))
		{
			return true;
		}
	}

	return false;
}