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

		AtomNode() :count("1"){}
	};

	// 组合体节点
	struct CombineNode
	{
		// 当前节点的值
		AtomNode* value;
		// 下一个相邻节点
		CombineNode* next;
		// 第一个子节点
		CombineNode* firstChild;
		// 数量
		std::string childCount;

		CombineNode() :value(nullptr), next(nullptr), firstChild(nullptr), childCount("1")
		{}
	};

	typedef std::function<void(const AtomNode* value)> LookNodeHandler;

	// 化学式节点
	class ChemNode
	{
	public: 
		ChemNode();
		~ChemNode();
	public:
		/**
		*	设置根节点
		*/
		void setRoot(CombineNode* node);
		/**
		*	创建根节点
		*/
		CombineNode* createRoot(const std::string& symbol, const std::string& count);
		/**
		*	创建一个节点
		*/
		CombineNode* createNode(const std::string& symbol, const std::string& count);
		/**
		*	销毁一个节点
		*/
		bool disponseNode(CombineNode* node);
		/**
		*	追加一个节点
		*/
		bool addNode(CombineNode* previous, CombineNode* next);
		/**
		*	添加一个子节点
		*/
		bool addChild(CombineNode* parent, CombineNode* child);
		/**
		*	销毁当前节点
		*/
		void disponse();
		/**
		*	遍历节点
		*/
		void foreach(const LookNodeHandler& handler);
	private:
		/**
		*	级联销毁一个节点
		*/
		bool disponseTree(CombineNode* node);
		/**
		*	遍历节点
		*/
		void foreachTree(CombineNode* node, const LookNodeHandler& handler);
	private:
		// 根节点
		CombineNode* _root;
	};
}