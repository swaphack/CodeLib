#include "SymbolDelegate.h"

using namespace script;


SymbolDelegate::SymbolDelegate()
{
	m_strSymbol = "";
	m_strExpression = "";
	m_nPriorityLevel = 0;
}

SymbolDelegate::~SymbolDelegate()
{

}

const char* SymbolDelegate::getSymbol()
{
	return m_strSymbol.c_str();
}

void SymbolDelegate::setSymbol(const char* symbol)
{
	if (symbol)
	{
		m_strSymbol = symbol;
	}
}

const char* SymbolDelegate::getExpression()
{
	return m_strExpression.c_str();
}

void SymbolDelegate::setExpression(const char* text)
{
	if (text)
	{
		m_strExpression = text;
	}
}

int SymbolDelegate::getPriorityLevel()
{
	return m_nPriorityLevel;
}

void SymbolDelegate::setPriorityLevel(int level)
{
	m_nPriorityLevel = level;
}