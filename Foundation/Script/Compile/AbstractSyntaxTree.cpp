#include "AbstractSyntaxTree.h"

using namespace script;


AbstractSyntaxTree::AbstractSyntaxTree()
{

}

AbstractSyntaxTree::~AbstractSyntaxTree()
{

}

bool AbstractSyntaxTree::load(Token::const_iterator begin, Token::const_iterator end)
{
	ASTNode* pLastNode = nullptr;

	Token::const_iterator iter = begin;
	while (iter != end)
	{
		if (pLastNode == nullptr)
		{
			pLastNode = new ASTNode();
		}

		if (pLastNode->left == nullptr)
		{
			ASTNode* pNode = new ASTNode();
			pNode->vale = *iter;
			pLastNode->left = pNode;
		}
		else if (pLastNode->vale.empty())
		{
			pLastNode->vale = *iter;
		}
		else if (pLastNode->right == nullptr)
		{
			ASTNode* pNode = new ASTNode();
			pLastNode->right = pNode;
			pLastNode = pNode;
		}
		iter++;
	}

	return true;
}
