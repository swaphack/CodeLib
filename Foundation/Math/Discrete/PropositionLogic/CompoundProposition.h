#pragma once

#include "Proposition.h"
#include "Basic/base.h"

#include <vector>

namespace math
{
	/**
	*	复合命题
	*	叶子节点是基础命题，其他节点为逻辑符号
	*/
	class CompoundProposition : public Proposition
	{
	public:
		// 与
		static const uint64_t COMPOUND_PROPOSITION_SIGNAL_AND = 1000001;
		// 或
		static const uint64_t COMPOUND_PROPOSITION_SIGNAL_OR = 1000001;
		// 非
		static const uint64_t COMPOUND_PROPOSITION_SIGNAL_NOT = 1000001;
		// 异或
		static const uint64_t COMPOUND_PROPOSITION_SIGNAL_XOR = 1000001;
		// 蕴含
		static const uint64_t COMPOUND_PROPOSITION_SIGNAL_IMPLICATE = 1000001;
		// 双重蕴含
		static const uint64_t COMPOUND_PROPOSITION_SIGNAL_DOUBLEIMPLICATE = 1000001;
	public:
		CompoundProposition();
		CompoundProposition(const CompoundProposition& value);
		virtual ~CompoundProposition();
	public:
		/**
		*	是否相同
		*/
		virtual bool hasSameLogic(Proposition* proposition);
		/**
		*	获取所有唯一id节点
		*/
		std::set<TreeNode*> getAllUniqueIdentifyChildren();
		/**
		*	子节点是否都是基础命题
		*/
		bool isPrimaryPropositionOfAllChildren();
		/**
		*	克隆节点，不包含子节点
		*/
		virtual Proposition* clone();
		/**
		*	克隆节点，包含子节点
		*/
		virtual Proposition* deepClone();
	protected:
		/**
		*	变量匹配
		*/
		bool matchChildren(const std::vector<TreeNode*>& children);
		/**
		*	深度复制子节点
		*/
		std::vector<TreeNode*> deepCloneChildren();
	public:
		/**
		*	赋值
		*/
		CompoundProposition& operator=(const CompoundProposition& value);
	};

	
}