#pragma once

#include "macros.h"

namespace script
{
	class AbstractSyntaxTree;
	// ���ʽ
	class Expression
	{
	public:
		Expression();
		~Expression();
	public:
		// ����
		Token::const_iterator read(Token::const_iterator begin, Token::const_iterator end);
	};
}