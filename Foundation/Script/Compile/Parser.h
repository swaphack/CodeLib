#pragma once

#include "macros.h"

#include <stack>

namespace script
{
	/**
	*	�﷨����
	*/
	class Parser
	{
	public:
		Parser();
		~Parser();
	public:
		bool parse(Token::const_iterator begin, Token::const_iterator end);
	};
}
