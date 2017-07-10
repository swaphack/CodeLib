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
		const std::vector<ASTNode*>& getASTNodeList() { return m_pASTNodeList; }
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
		ASTNode* parseSingleASTNode(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset);
	private:
		// �﷨����
		std::vector<ASTNode*> m_pASTNodeList;
	};
}
