#pragma once

#include "macros.h"

#include "SyntaxAnalysis.h"

namespace script
{
	/**
	*	”Ô∑®∑÷Œˆ
	*/
	class Parser
	{
	public:
		Parser();
		~Parser();
	public:
		bool parse(Token::const_iterator begin, Token::const_iterator end);
	private:
		SyntaxAnalysis* m_pSyntaxAnalysis;
	};
}
