#pragma once

#include "macros.h"
#include "ASTNode.h"

#include <stack>

namespace script
{
	// �����﷨��
	class AbstractSyntaxTree
	{
	public:
		AbstractSyntaxTree();
		~AbstractSyntaxTree();
	public:
		bool load(Token::const_iterator begin, Token::const_iterator end);
	protected:
		// �������ʽ
		bool createExpression(ASTNode* node, Token::const_iterator& iter, Token::const_iterator& end);
		// ���������
		bool createBlock(ASTNode* node, Token::const_iterator& iter, Token::const_iterator& end);
	private:
		// ���ڵ�
		ASTNode* m_pRoot;
	};
}