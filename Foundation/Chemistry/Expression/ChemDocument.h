#pragma once

#include <string>
#include "ChemNode.h"

namespace chem
{
	// ��ѧʽ�ĵ�
	class ChemDocument
	{
	private:
		ChemDocument();
		virtual ~ChemDocument();
	public:
		static ChemDocument* getInstance();
		// ��ȡ����ʽ�Ľڵ���ʽ
		ChemNode* loadMolecular(const char* expression);
		// ��ȡ��ѧ��ʽ�ı��ʽ
	protected:
		bool readExpression(ChemNode* chemNode);
		/**
		*	��ȡ������
		*	��"("��ʼ����")"����
		*/
		bool readBlock(ChemNode* chemNode);
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