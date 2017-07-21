#pragma once

#include "macros.h"

#include "ASTNode.h"

#include "SymbolInformation.h"

namespace script
{	
	// ���Ž���
	class SymbolDelegate
	{
	public:
		SymbolDelegate();
		virtual ~SymbolDelegate();
	public:
		// ������Ϣ
		inline const SymbolInformation* getSymbolInformation() { return &m_rSymbolInformation; }
		// �﷨��ڵ�ģ��
		inline const ASTNode* getASTTemplate() { return &m_rASTTemplate; }

		void setSymbolInformation(const SymbolInformation& value);
		/**
		*	�����﷨�ڵ�
		*	@param begin ������ʽ��ʼλ��
		*	@param end ������ʽ����λ��
		*	@param offset �����ɹ����ƫ��ֵ
		*	@return ASTNode �Ƿ�����ɹ�,�����ɹ������﷨�ڵ㣬���򷵻ؿ�
		*/
		ASTNode* createASTNode(Token::const_iterator begin, Token::const_iterator end, Token::const_iterator& offset);
	protected:
		bool isFormat();
		// ��������
		ASTNode* setValue(ASTNode* pNode, char value);
		// ���÷���
		ASTNode* setValue(ASTNode* pNode, const char* value);
		// �����ڵ�
		ASTNode* ergodicNode(ASTNode* pNode, Token::const_iterator iter);
	private:
		// �����﷨�ڵ�
		bool makeASTNode();
	protected:
		// �﷨�ڵ�ģ��
		ASTNode m_rASTTemplate;
		// ������Ϣ
		SymbolInformation m_rSymbolInformation;
	};
}