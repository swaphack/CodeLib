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
	public:
		Parser();
		~Parser();
	public:
		// ���к�Ƕ��
		bool parse(Token::const_iterator begin, Token::const_iterator end);
		// �﷨����
		const ASTNodeVec& getASTNodeList() { return m_pASTNodeList; }
	protected:
		/**
		*	���������ɵ�һ�ڵ���﷨��
		*	ʹ��vector�洢��������
		*	vectorÿһ�����ݴ洢AST�ṹ������ڵ㣬���ţ��ҽڵ��˳��洢
		*	�������Ƕ�׵Ļ���Ƕ�״��ҽڵ���չ
		*/
		ASTNode* parseSingleASTNode(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset);
		/**
		*	����˳��ڵ�
		*/
		ASTNode* parseSequenceASTNode(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset);
		/**
		*	�����ڲ��ڵ�
		*/
		ASTNode* parseEmbedASTNode(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset);
	private:
		// �﷨����
		ASTNodeVec m_pASTNodeList;
	};
}
