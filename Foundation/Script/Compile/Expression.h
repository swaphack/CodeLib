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
		// �����﷨��
		AbstractSyntaxTree* getAST();
		// ����
		bool read(Token::const_iterator begin, Token::const_iterator end);
	protected:
	private:
		// �����﷨��
		AbstractSyntaxTree* m_pAST;
	};
}