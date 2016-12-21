#pragma once

#include "SymbolDelegate.h"

namespace script
{
	// = µÈÓÚºÅ
	class SymbolEqual : public SymbolDelegate
	{
	public:
		SymbolEqual()
		{
			m_strSymbol = "=";
			m_strExpression = "1=0";
		}

		virtual bool makeASTNode(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset)
		{
			offset = begin;
			while (offset != end)
			{
				if ()
				{
				}
			}
		}
	};
}