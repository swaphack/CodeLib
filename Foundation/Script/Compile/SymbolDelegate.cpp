#include "SymbolDelegate.h"

using namespace script;

#ifndef IS_NUMBER
#define IS_NUMBER(X) (X >= '0' && X <= '9')
#endif

int getNumber(char symbol)
{
	switch (symbol)
	{
	case '0':return 0;
	case '1':return 1;
	case '2':return 2;
	case '3':return 3;
	case '4':return 4;
	case '5':return 5;
	case '6':return 6;
	case '7':return 7;
	case '8':return 8;
	case '9':return 9;
	default:
		break;
	}

	return -1;
}



SymbolDelegate::SymbolDelegate()
{
}

SymbolDelegate::~SymbolDelegate()
{
	m_rASTTemplate.clear();
}

bool SymbolDelegate::makeASTNode()
{
	const char* pExpression = m_rSymbolInformation.expression.c_str();
	int nSize = m_rSymbolInformation.expression.size();

	std::string symbol;
	m_rASTTemplate.clear();
	ASTNode* pNode = &m_rASTTemplate;

	for (int i = 0; i < nSize; i++)
	{
		if (IS_NUMBER(pExpression[i]))
		{// 是否是数字
			if (!symbol.empty())
			{// 符号
				pNode = setValue(pNode, symbol.c_str());
				if (pNode == nullptr)
				{
					return false;
				}
				symbol.clear();
			}
			pNode = setValue(pNode, pExpression[i]);
			if (pNode == nullptr)
			{
				return false;
			}
		}
		else
		{
			symbol.append(1, pExpression[i]);
		}
	}

	if (!symbol.empty())
	{
		pNode = setValue(pNode, symbol.c_str());
		if (pNode == nullptr)
		{
			return false;
		}
		symbol.clear();
	}

	return true;
}

bool SymbolDelegate::match(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset)
{
	offset = begin;

	ASTNode* pTemplateNode = &m_rASTTemplate;

	while (offset != end)
	{
		

		offset++;
	}

	return true;
}

ASTNode* SymbolDelegate::createASTNode(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset)
{
	ASTNode* pLastNode = &m_rASTTemplate;

	offset = begin;

	ASTNode* pNewNode = new ASTNode();
	ASTNode* pNewLastNode = pNewNode;

	int flag = 0;

	while (offset != end)
	{
		if (pLastNode == nullptr)
		{// 遍历完毕
			break;
		}

		if (pLastNode->left && pLastNode->left->flag == 0)
		{// left
			ASTNode* pLeftNode = ergodicNode(pLastNode->left, offset);
			if (pLeftNode == nullptr)
			{
				flag = 1;
				break;
			}
			pNewLastNode->left = pLeftNode;
		}
		else if (pLastNode->flag == 0)
		{// middle
			ASTNode* pMiddleNode = ergodicNode(pLastNode, offset);
			if (pMiddleNode == nullptr)
			{
				flag = 1;
				break;
			}
			pNewLastNode->value = pMiddleNode->value;

			delete pMiddleNode;
		}
		else if (pLastNode->right && pLastNode->right->flag == 0)
		{// right
			ASTNode* pRightNode = ergodicNode(pLastNode->right, offset);
			if (pRightNode == nullptr)
			{
				flag = 1;
				break;
			}
			pNewLastNode->right = pRightNode;

			pNewLastNode = pRightNode;
			pLastNode = pLastNode->right;
		}
		else
		{
			break;
		}
		offset++;
	}

	if (flag == 1)
	{
		delete pNewNode;
		return nullptr;
	}
	else
	{
		offset++;
	}

	return pNewNode;
}

ASTNode* SymbolDelegate::setValue(ASTNode* pNode, char value)
{
	if (pNode == nullptr)
	{
		return nullptr;
	}

	if (pNode->value.empty())
	{
		if (pNode->left == nullptr) 
			pNode->left = new ASTNode();

		pNode->left->value = value;
		pNode->left->isSymbol = false;
	}	
	else 
	{
		if (pNode->right == nullptr) 
			pNode->right = new ASTNode();

		pNode->right->value = value;
		pNode->right->isSymbol = false;
	}

	return pNode;
}

ASTNode* SymbolDelegate::setValue(ASTNode* pNode, const char* value)
{
	if (pNode == nullptr)
	{
		return nullptr;
	}

	if (value == nullptr)
	{
		return pNode;
	}

	if (pNode->value.empty())
	{
		pNode->value = value;
		pNode->isSymbol = true;
		pNode->builtin = true;
	}
	else
	{
		ASTNode* pMiddle = new ASTNode();
		pMiddle->value = value;
		pMiddle->isSymbol = true;
		pMiddle->builtin = true;

		pMiddle->left = pNode->right;
		pNode->right = pMiddle;

		pNode = pMiddle;
	}

	return pNode;
}

ASTNode* SymbolDelegate::ergodicNode(ASTNode* pNode, Token::const_iterator iter)
{
	if (pNode == nullptr)
	{
		return nullptr;
	}

	std::string value = *iter;

	if (pNode->flag == 1)
	{
		return nullptr;
	}

	ASTNode* pCopyNode = nullptr;

	if (pNode->isSymbol)
	{
		if (value.compare(pNode->value) == 0)
		{
			pCopyNode = new ASTNode();
			pCopyNode->value = value;
			pCopyNode->isSymbol = true;
		}
		else
		{
			return nullptr;
		}
	}
	else
	{
		pCopyNode = new ASTNode();
		pCopyNode->value = value;
		pCopyNode->isSymbol = false;
	}

	pNode->flag = 0;

	return pCopyNode;
}
