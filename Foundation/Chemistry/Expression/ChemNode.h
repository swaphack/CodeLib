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

		AtomNode() :count("1"){}
	};

	// �����ڵ�
	struct CombineNode
	{
		// ��ǰ�ڵ��ֵ
		AtomNode* value;
		// ��һ�����ڽڵ�
		CombineNode* next;
		// ��һ���ӽڵ�
		CombineNode* firstChild;
		// ����
		std::string childCount;

		CombineNode() :value(nullptr), next(nullptr), firstChild(nullptr), childCount("1")
		{}
	};

	typedef std::function<void(const AtomNode* value)> LookNodeHandler;

	// ��ѧʽ�ڵ�
	class ChemNode
	{
	public: 
		ChemNode();
		~ChemNode();
	public:
		/**
		*	���ø��ڵ�
		*/
		void setRoot(CombineNode* node);
		/**
		*	�������ڵ�
		*/
		CombineNode* createRoot(const std::string& symbol, const std::string& count);
		/**
		*	����һ���ڵ�
		*/
		CombineNode* createNode(const std::string& symbol, const std::string& count);
		/**
		*	����һ���ڵ�
		*/
		bool disponseNode(CombineNode* node);
		/**
		*	׷��һ���ڵ�
		*/
		bool addNode(CombineNode* previous, CombineNode* next);
		/**
		*	���һ���ӽڵ�
		*/
		bool addChild(CombineNode* parent, CombineNode* child);
		/**
		*	���ٵ�ǰ�ڵ�
		*/
		void disponse();
		/**
		*	�����ڵ�
		*/
		void foreach(const LookNodeHandler& handler);
	private:
		/**
		*	��������һ���ڵ�
		*/
		bool disponseTree(CombineNode* node);
		/**
		*	�����ڵ�
		*/
		void foreachTree(CombineNode* node, const LookNodeHandler& handler);
	private:
		// ���ڵ�
		CombineNode* _root;
	};
}