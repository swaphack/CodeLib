#pragma once

#include <string>

namespace script
{
	// �﷨��ڵ�
	struct ASTNode
	{
		std::string vale;
		ASTNode* left;
		ASTNode* right;
	};

	// �����﷨��
	class AbstractSyntaxCode
	{
	public:
		AbstractSyntaxCode();
		~AbstractSyntaxCode();
	public:
		bool load(Token::const_iterator begin, Token::const_iterator end);
	protected:
	private:
	};
}