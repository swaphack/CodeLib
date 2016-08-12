#pragma once

#include <string>
#include <vector>
#include <functional>

namespace nature
{
	// ��ѧʽ�ڵ�
	class ChemNode
	{
	public:
		// ����
		std::string symbol;
		// ����
		std::string count;

		// ��һ���ڵ�
		std::vector<ChemNode*> next;

		// �ڲ��ڵ�
		ChemNode* inner;
		// �ڲ��ڵ�����
		std::string innerCount;
	public:
		ChemNode();
		~ChemNode();
	public:
		void foreach(std::function<void(const std::string& symbol, const std::string& number)> func);
		// ����
		void disponse();
	};

	// ��ѧʽ�ĵ�
	class ChemDocument
	{
	public:
		ChemDocument();
		virtual ~ChemDocument();
	public:
		// ��ȡ����ʽʽ�Ľڵ���ʽ
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