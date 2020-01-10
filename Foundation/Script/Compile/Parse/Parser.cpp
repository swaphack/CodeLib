#include "Parser.h"
#include "ASTNode.h"
#include "SymbolHandler.h"
#include <stack>

using namespace script;

#define SAFE_DELETE(x) {if ((x) != nullptr) { delete (x); (x) = nullptr; }}
#define SAFE_INCREASE(x, end) { if ((x) != (end))  (x)++; }
#define SAFE_BREAK(x) { if(!(x)) break; }

#define SET_FALSE_BREAK(x) { (x) = false; break; }
#define SET_TRUE_BREAK(x) { (x) = true; break; }

Parser::Parser()
{
	m_pSymbolHandler = new SymbolHandler();
}

Parser::~Parser()
{
	delete m_pSymbolHandler;
}

bool Parser::parse(Token::const_iterator begin, Token::const_iterator end)
{
	m_pASTNodeList.clear();

	Token::const_iterator iter = begin;
	Token::const_iterator offset;
	while (iter != end)
	{
		ASTNode* pNode = parseSingleASTNode(iter, end, offset);
		if (pNode == nullptr)
		{
			return false;
		}
		m_pASTNodeList.push_back(pNode);
		iter = offset;
	}
	return true;
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
	Token::const_iterator iter2;

	SymbolDelegate* pDelegate = nullptr;
	const ASTNode* pTempNode = nullptr;

	ASTNode* pCurrentNode = nullptr;
	ASTNode* pLeftNode = nullptr;
	ASTNode* pRightNode = nullptr;

	bool ret = false;

	while (iter != end)
	{
		pLeftNode = parseSequenceASTNode(iter, end, iter2);
		SAFE_BREAK(pLeftNode);
		if (pLeftNode->isSymbol)
		{// 左节点是符号，设为当前节点
			pCurrentNode = pLeftNode;
			pLeftNode = nullptr;
		}
		iter = iter2;
		if (pCurrentNode == nullptr)
		{// 解析当前节点
			pCurrentNode = parseSequenceASTNode(iter, end, iter2);
			SAFE_BREAK(pCurrentNode);
			iter = iter2;
		}
		if (!pCurrentNode->isSymbol)
		{// 当前节点不是符号，返回错误
			SAFE_DELETE(pLeftNode);
			SAFE_DELETE(pCurrentNode);
			SAFE_BREAK(pCurrentNode);
		}

		pDelegate = m_pSymbolHandler->getSymbolDelegate(pCurrentNode->value);
		SAFE_BREAK(pDelegate);

		pTempNode = pDelegate->getASTTemplate();
		if ((pTempNode->left == nullptr && pLeftNode != nullptr) || (pTempNode->left != nullptr && pLeftNode == nullptr))
		{// 左节点异常
			SET_FALSE_BREAK(ret);
		}

		if (pTempNode->right == nullptr)
		{
			SET_TRUE_BREAK(ret);
		}
		else
		{
			pRightNode = parseSequenceASTNode(iter, end, iter2);
			SAFE_BREAK(pRightNode);
			iter = iter2;
			SET_TRUE_BREAK(ret);
		}
	}

	if (!ret)
	{
		SAFE_DELETE(pLeftNode);
		SAFE_DELETE(pCurrentNode);
		SAFE_DELETE(pRightNode);
		return nullptr;
	}

	pCurrentNode->left = pLeftNode;
	pCurrentNode->right = pRightNode;
	offset = iter;

	return pCurrentNode;
}

ASTNode* Parser::parseSequenceASTNode(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset)
{
	Token::const_iterator iter = begin;
	Token::const_iterator iter2;
	SymbolDelegate* pDelegate = nullptr;
	const SymbolInformation* pInfo = nullptr;
	ASTNode* pCurrentNode = nullptr;

	pDelegate = m_pSymbolHandler->getSymbolDelegate(iter->c_str());
	if (pDelegate)
	{ // 是符号
		pInfo = pDelegate->getSymbolInformation();
		if (pInfo->embed)
		{ // 内联
			pCurrentNode = parseEmbedASTNode(iter, end, iter2);
			iter = iter2;
		}
		else
		{
			pCurrentNode = new ASTNode();
			pCurrentNode->value = *iter;
			pCurrentNode->isSymbol = true;
			SAFE_INCREASE(iter, end);
		}
	}
	else
	{ // 常量
		pCurrentNode = new ASTNode();
		pCurrentNode->value = *iter;
		pCurrentNode->isSymbol = false;
		SAFE_INCREASE(iter, end);

		/*
		// 扩展, 回溯
		ASTNode* pNextNode = parseSequenceASTNode(iter, end, iter2);
		if (pNextNode != nullptr)
		{
			if (pNextNode->isSymbol)
			{
				SAFE_DELETE(pCurrentNode);
				pCurrentNode = parseSingleASTNode(--iter, end, iter2);
				if (pCurrentNode != nullptr)
				{
					iter = iter2;
				}
			}
			SAFE_DELETE(pNextNode);
		}
		*/
	}

	offset = iter;

	// 解析完毕
	return pCurrentNode;
}

ASTNode* Parser::parseEmbedASTNode(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset)
{
	Token::const_iterator iter = begin;
	Token::const_iterator iter2;
	SymbolDelegate* pDelegate = nullptr;
	const SymbolInformation* pInfo = nullptr;
	ASTNode* pCurrentNode = nullptr;

	pDelegate = m_pSymbolHandler->getSymbolDelegate(iter->c_str());
	pInfo = pDelegate->getSymbolInformation();

	while (iter != end)
	{
		if (pInfo->isBegin(iter->c_str()))
		{ // 开始标识
			pCurrentNode = parseSingleASTNode(++iter, end, iter2);
			SAFE_BREAK(pCurrentNode);
			pCurrentNode->isSymbol = false;
			iter = iter2;
			if (pInfo->isEnd(iter->c_str()))
			{
				SAFE_INCREASE(iter, end);
				break;
			}
			else
			{
				SAFE_DELETE(pCurrentNode);
				SAFE_BREAK(pCurrentNode);
			}
		}
	}

	offset = iter;

	return pCurrentNode;
}

bool Parser::init(const std::string& filepath)
{
	return m_pSymbolHandler->loadFromFile(filepath);
}
