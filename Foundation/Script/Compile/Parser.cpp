#include "Parser.h"
#include "ASTNode.h"
#include "SymbolHandler.h"
#include "../Core/Console.h"
#include <stack>

using namespace script;


#define AUTO_INCREASE(x, end) { if ((x) != (end))  (x)++; }

Parser::Parser()
{
}

Parser::~Parser()
{
}

bool Parser::parse(Token::const_iterator begin, Token::const_iterator end)
{
	m_pASTNodeList.clear();

	Token::const_iterator iter = begin;
	Token::const_iterator offset;
	while (iter != end)
	{
		ASTNode* pNode = parseSingleNode(iter, end, offset);
		if (pNode == nullptr)
		{
			return false;
		}
		m_pASTNodeList.push_back(pNode);
		iter = offset;
	}
	return true;
}

ASTNode* Parser::parseSingleNode(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset)
{
	ASTNode* pNode = parseSingleASTNode(begin, end, offset);
	if (pNode == nullptr)
	{
		return nullptr;
	}

	return pNode;
}

/**
* 分析采用左优先原则
* 1: a = b * ( c + d )
*	a = 
*	  b *
*		(c + d)
* 2: (a + 1) * (c + 2) == b * ( c + d )
*	a + 1 
*		*
*		c + 2
*			==
*/
ASTNode* Parser::parseSingleASTNode(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset)
{
	Token::const_iterator iter = begin;

	SymbolDelegate* pDelegate = nullptr;
	const ASTNode* pTempNode = nullptr;
	const SymbolInformation* pInfo = nullptr;

	ASTNode* pCurrentNode = nullptr;
	ASTNode* pLeftNode = nullptr;
	ASTNode* pRightNode = nullptr;

	while (iter != end)
	{
		pDelegate = SymbolHandler::getInstance()->getSymbolDelegate(iter->c_str());
		if (pDelegate)
		{ // 是符号
			pTempNode = pDelegate->getASTTemplate();
			pInfo = pDelegate->getSymbolInformation();
			if (pInfo->embed)
			{ // 内联
				if (pInfo->isBegin(iter->c_str()))
				{ // 开始标识
					pCurrentNode = parseSingleASTNode(++iter, end, offset);
					if (pCurrentNode != nullptr)
					{
						iter = offset;
						AUTO_INCREASE(iter, end);
						return pCurrentNode;
					}
					break;
				}
				else if (pInfo->isEnd(iter->c_str()))
				{// 结束标识
					AUTO_INCREASE(iter, end);
					break;
				}
			}

			if (pCurrentNode == nullptr)
			{
				if ((pTempNode->left == nullptr && pLeftNode != nullptr)
					|| (pTempNode->left != nullptr && pLeftNode == nullptr))
				{
					Console::getInstance()->error("null left node");
					break;
				}
				pCurrentNode = new ASTNode();
				pCurrentNode->value = *iter;
				pCurrentNode->left = pLeftNode;
				pCurrentNode->isSymbol = true;

				if (pTempNode->right == nullptr)
				{// 解析完毕
					AUTO_INCREASE(iter, end);
					return pCurrentNode;
				}

				pRightNode = parseSingleASTNode(++iter, end, offset);
				if (pRightNode == nullptr)
				{
					delete pCurrentNode;
					pCurrentNode = nullptr;
					break;
				}

				pCurrentNode->right = pRightNode;
				iter = offset;
				// 解析完毕
				return pCurrentNode;
			}
			else
			{
				delete pCurrentNode;
				pCurrentNode = nullptr;
				break;
			}
		}
		else
		{ // 常量
			if (pLeftNode == nullptr)  
			{ // 左边为空
				pLeftNode = new ASTNode();
				pLeftNode->value = *iter;
				AUTO_INCREASE(iter, end);
			}
			else
			{
				break;
			}
		}
	}

	if (pCurrentNode == nullptr)
	{
		pCurrentNode = pLeftNode;
	}

	if (pCurrentNode != nullptr) {
		offset = iter;
	}

	return pCurrentNode;
}
