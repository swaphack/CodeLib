#include "Parser.h"
#include "ASTNode.h"
#include "SymbolHandler.h"

#include <stack>

using namespace script;

Parser::Parser()
{
}

Parser::~Parser()
{
}

bool Parser::parse(Token::const_iterator begin, Token::const_iterator end, std::vector<ASTNode*>& nodeAry)
{
	Token::const_iterator iter = begin;
	Token::const_iterator offset;
	while (iter != end)
	{
		ASTNode* pNode = parseSingleNode(iter, end, offset);
		if (pNode == nullptr)
		{
			return false;
		}
		nodeAry.push_back(pNode);
		iter = offset;
	}
	return true;
}

ASTNode* Parser::parseSingleNode(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset)
{

	std::vector<Token> tokenStack;

	if (!parseSingleASTNode(begin, end, offset, tokenStack))
	{
		return nullptr;
	}

	ASTNode* pNode = new ASTNode();
	if (!makeSingleAstNode(tokenStack.rbegin(), tokenStack.rend(), pNode))
	{
		delete pNode;
		return nullptr;
	}

	return pNode;
}

bool Parser::parseSingleASTNode(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset, TokenAry& tokenStack)
{
	Token::const_iterator iter = begin;

	SymbolDelegate* pDelegate = nullptr;
	const ASTNode* pTempNode = nullptr;

	tokenStack.clear();

	while (iter != end)
	{
		pDelegate = SymbolHandler::getInstance()->getSymbolDelegate(iter->c_str());
		if (pDelegate)
		{ // 是符号
			pTempNode = &pDelegate->getASTTemplate();
			if (pTempNode->left == nullptr && tokenStack.back().size() != 0)
			{// 节点读取结束
				break;
			}

			if (pTempNode->left != nullptr && tokenStack.back().size() == 0)
			{// 节点读取结束
				break;
			}

			tokenStack.push_back(Token());
			tokenStack.back().push_back(*iter);

			if (pTempNode->right != nullptr)
			{ // 右节点不为空，继续读取
				tokenStack.push_back(Token());
			}
			else
			{// 右节点为空，读取结束
				iter++;
				break;
			}
		}
		else
		{// 是常量
			if (tokenStack.back().size() != 0)
			{
				pDelegate = SymbolHandler::getInstance()->getSymbolDelegate(tokenStack.back().front().c_str());
				if (pDelegate)
				{// 是符号
					pTempNode = &pDelegate->getASTTemplate();
					if (pTempNode->right != nullptr)
					{

					}
				}
				else
				{

				}
			}
			else
			{ // 添加常量
				tokenStack.push_back(Token());
				tokenStack.back().push_back(*iter);
			}
		}
		iter++;
	}

	bool result = tokenStack.size() > 0;
	if (result)
	{
		offset = iter;
	}

	return result;
}

bool Parser::makeSingleAstNode(TokenAry::const_reverse_iterator tokenAryBegin, TokenAry::const_reverse_iterator tokenAryEnd, ASTNode* pNode)
{
	if (pNode == nullptr)
	{
		return false;
	}

	TokenAry::const_reverse_iterator tokenAryIter = tokenAryBegin;

	while (tokenAryIter != tokenAryEnd)
	{
		Token::const_iterator iter = tokenAryIter->begin();
		while (iter != tokenAryIter->end())
		{
			pNode->right = 

			iter++;
		}

		tokenAryIter++;
	}
}
