#pragma once

#include <string>
#include <vector>
#include <stack>
#include <functional>

namespace chem
{
	// 原子节点
	struct AtomNode
	{
		// 符号
		std::string symbol;
		// 数量
		std::string count;
	};

	// 分子节点
	struct MoleculeNode
	{
		// 组合的元素
		std::vector<AtomNode*> elements;
		// 数量
		std::string count;
	};

	// 离子节点
	struct IonNode : public MoleculeNode
	{
		// 电子数
		std::string electron;
	};

	// 组合体节点
	struct CombineNode
	{
		// 串行节点
		std::vector<MoleculeNode*> SequenceNodeAry;
		// 并行节点
		std::stack<MoleculeNode*> SpawnNodeAry;
	};

	// 化学式节点
	class ChemNode
	{
	public:
		// 各个节点
		std::vector<CombineNode*> CombineNodes;
	public:
		// 在尾部添加一个元素
		void appendNode(const std::string& symbol, const std::string& count);
		// 在尾部添加一个元素
		void appendNode(const AtomNode* node);
		// 在尾部添加一个元素
		void appendNode(const MoleculeNode* node);
		// 在尾部添加一个元素
		void appendNode(const IonNode* node);
		// 在尾部添加一个组合体
		void appendNode(const CombineNode* node);
		// 在尾部添加化学式节点
		void appendNode(const ChemNode* node);
		// 销毁
		void disponse();
	};
}