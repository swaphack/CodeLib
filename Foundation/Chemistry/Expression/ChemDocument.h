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
		// ��ȡ����ʽ�Ľڵ���ʽ
		ChemNode* loadMolecular(const char* expression);
		// ��ȡ��ѧ��ʽ�ı��ʽ
	protected:
		ChemNode* readExpression();
		/**
		*	��ȡ������
		*	��"("��ʼ����")"����
		*/
		ChemNode* readBlock(bool& endBlock);
		// ��ȡ����
		bool readSymbol(std::string& symbol);
		// ��ȡ����
		bool readNumber(std::string& number);
	private:
		char* _cursor;
	};
}