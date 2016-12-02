#pragma once

#include "macros.h"

namespace script
{
	// �﷨��ڵ�
	struct ASTNode
	{
		// �ڵ�ֵ
		std::string vale;
		// ��ڵ�
		ASTNode* left;
		// �ҽڵ�
		ASTNode* right;

		ASTNode() :left(nullptr), right(nullptr){}
	};

	// �����﷨��
	class AbstractSyntaxTree
	{
	public:
		AbstractSyntaxTree();
		~AbstractSyntaxTree();
	public:
		bool load(Token::const_iterator begin, Token::const_iterator end);
	private:
		// ���ڵ�
		ASTNode* m_pRoot;
	};
}