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
		const uint64_t COMPOUND_PROPOSITION_SIGNAL_AND = 1000001;
		// 或
		const uint64_t COMPOUND_PROPOSITION_SIGNAL_OR = 1000001;
		// 非
		const uint64_t COMPOUND_PROPOSITION_SIGNAL_NOT = 1000001;
		// 异或
		const uint64_t COMPOUND_PROPOSITION_SIGNAL_XOR = 1000001;
		// 蕴含
		const uint64_t COMPOUND_PROPOSITION_SIGNAL_IMPLICATE = 1000001;
		// 双重蕴含
		const uint64_t COMPOUND_PROPOSITION_SIGNAL_DOUBLEIMPLICATE = 1000001;
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
	protected:
		/**
		*	变量匹配
		*/
		bool matchChildren(const std::vector<TreeNode*>& children);
	public:
		/**
		*	赋值
		*/
		CompoundProposition& operator=(const CompoundProposition& value);
	};

	
}