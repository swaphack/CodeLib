#pragma once

#include <string>
#include "ChemNode.h"

namespace chem
{
	// ��ѧʽ�ĵ�
	class ChemDocument
	{
	public:
		ChemDocument();
		virtual ~ChemDocument();
	public:
		static ChemDocument* getInstance();
		/**
		*	��ȡ����ʽ�Ľڵ���ʽ
		*	���ֶ��ͷŷ��ؽ��
		*/ 
		ChemNode* loadMolecular(const char* expression);
		// ��ȡ��ѧ��ʽ�ı��ʽ
		/**
		*	�ͷŽڵ�
		*/
		void releaseNode();
	protected:
		/**
		*	�������ʽ
		*/
		bool readExpression();
		/**
		*	��ȡ������
		*	��"("��ʼ����")"����
		*/
		CombineNode* readBlock();
		/**
		*	��ȡ������
		*	��"("��ʼ����")"����
		*/
		CombineNode* readNode();
	private:
		// ��ȡ����
		bool readSymbol(std::string& symbol);
		// ��ȡ����
		bool readNumber(std::string& number);
	private:
		// �α�
		char* _cursor;
		// ��ѧʽ
		ChemNode* _chemNode;
	};
}