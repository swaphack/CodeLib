#pragma once

#include <string>
#include <vector>
#include <stack>
#include <functional>

namespace chem
{
	// ԭ�ӽڵ�
	struct AtomNode
	{
		// ����
		std::string symbol;
		// ����
		std::string count;
	};

	// ���ӽڵ�
	struct MoleculeNode
	{
		// ��ϵ�Ԫ��
		std::vector<AtomNode*> elements;
		// ����
		std::string count;
	};

	// ���ӽڵ�
	struct IonNode : public MoleculeNode
	{
		// ������
		std::string electron;
	};

	// �����ڵ�
	struct CombineNode
	{
		// ���нڵ�
		std::vector<MoleculeNode*> SequenceNodeAry;
		// ���нڵ�
		std::stack<MoleculeNode*> SpawnNodeAry;
	};

	// ��ѧʽ�ڵ�
	class ChemNode
	{
	public:
		// �����ڵ�
		std::vector<CombineNode*> CombineNodes;
	public:
		// ��β�����һ��Ԫ��
		void appendNode(const std::string& symbol, const std::string& count);
		// ��β�����һ��Ԫ��
		void appendNode(const AtomNode* node);
		// ��β�����һ��Ԫ��
		void appendNode(const MoleculeNode* node);
		// ��β�����һ��Ԫ��
		void appendNode(const IonNode* node);
		// ��β�����һ�������
		void appendNode(const CombineNode* node);
		// ��β����ӻ�ѧʽ�ڵ�
		void appendNode(const ChemNode* node);
		// ����
		void disponse();
	};
}