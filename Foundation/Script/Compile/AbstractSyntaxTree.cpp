#include "AbstractSyntaxTree.h"
#include "SymbolHandler.h"

using namespace script;


AbstractSyntaxTree::AbstractSyntaxTree()
{

}

AbstractSyntaxTree::~AbstractSyntaxTree()
{

}

bool AbstractSyntaxTree::load(Token::const_iterator begin, Token::const_iterator end)
{
	ASTNode* pLastNode = new ASTNode();

	Token::const_iterator iter = begin;
	while (iter != end)
	{
		if (createBlock(pLastNode))
		{
		}

		iter++;
	}

	return true;
}

bool AbstractSyntaxTree::createExpression(ASTNode* node, Token::const_iterator& iter, Token::const_iterator& end)
{
	if (node == nullptr)
	{
		return false;
	}
	if (iter == end)
	{
		return true;
	}

	std::string strValue = *iter;
	SymbolDelegate* pDelegate = nullptr;
	if (strValue.compare("[") == 0)
	{
		pDelegate = SymbolHandler::getInstance()->getSymbolDelegate("[]");
	}
	else if (strValue.compare("?") == 0)
	{
		pDelegate = SymbolHandler::getInstance()->getSymbolDelegate("?:");
	}
	else if (strValue.compare("]") == 0 || strValue.compare(":") == 0)
	{

	}
	else
	{
		pDelegate = SymbolHandler::getInstance()->getSymbolDelegate(strValue.c_str());
	}

	if (pDelegate == nullptr)
	{
		return false;
	}


}

bool AbstractSyntaxTree::createBlock(ASTNode* node, Token::const_iterator& iter, Token::const_iterator& end)
{
	if (node == nullptr)
	{
		return false;
	}
	if (iter == end)
	{
		return true;
	}

	std::string strValue = *iter;
	if (strValue.compare("(") == 0)
	{// 代码块开始
		++iter;
		ASTNode* pNewNode = new ASTNode();
		if (createExpression(pNewNode, iter, end))
		{
			if (node->left == nullptr)
			{
				node->left = pNewNode;
			}
			else if (node->right == nullptr)
			{
				node->right = pNewNode;
			}
		}
	}
	else if (strValue.compare(")") == 0)
	{// 代码块结束
		++iter;
		return true;
	}

	return false;
}
