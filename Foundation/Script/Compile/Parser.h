#pragma once

#include "macros.h"

#include <vector>

namespace script
{
	class ASTNode;
	/**
	*	�﷨����
	*	a * (1 + a) / (c[3] - 2)
	*	*(+/[-
	*/
	class Parser
	{
	private:
		typedef std::vector<Token> TokenAry;
	public:
		Parser();
		~Parser();
	public:
		// ���к�Ƕ��
		bool parse(Token::const_iterator begin, Token::const_iterator end, std::vector<ASTNode*>& nodeAry);
	protected:
		/**
		*	������һ�ڵ�
		*/
		ASTNode* parseSingleNode(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset);
		/**
		*	���������ɵ�һ�ڵ���﷨��
		*	ʹ��vector�洢��������
		*	vectorÿһ�����ݴ洢AST�ṹ������ڵ㣬���ţ��ҽڵ��˳��洢
		*	�������Ƕ�׵Ļ���Ƕ�״��ҽڵ���չ
		*/
		bool parseSingleASTNode(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset, TokenAry& tokenStack);
		/**
		*	�����﷨��������AST�ڵ�
		*/
		bool makeSingleAstNode(TokenAry::const_reverse_iterator tokenAryBegin, TokenAry::const_reverse_iterator tokenAryEnd, ASTNode* pNode);
	};
}
