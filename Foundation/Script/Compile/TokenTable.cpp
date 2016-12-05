#include "TokenTable.h"

using namespace  script;

TokenTable::TokenTable()
{

}

TokenTable::~TokenTable()
{

}

void TokenTable::addToken(const char* token)
{
	if (token == nullptr)
	{
		return;
	}

	m_vWords.push_back(token);
}

void TokenTable::removeAllTokens()
{
	m_vWords.clear();
}
