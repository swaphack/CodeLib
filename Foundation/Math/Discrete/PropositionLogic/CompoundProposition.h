#pragma once

#include "Proposition.h"
#include "Basic/base.h"

#include <vector>

namespace math
{
	/**
	*	复合类型
	*/
	enum class CompoundPropositionType
	{
		NONE,
		AND,
		OR,
		NOT,
		// 蕴含
		Implicate,
		// 双重蕴含
		DoubleImplicate,
	};
	/**
	*	复合命题
	*	叶子节点是基础命题，其他节点为逻辑符号
	*/
	class CompoundProposition : public Proposition
	{
	public:
		CompoundProposition();
		CompoundProposition(const CompoundProposition& value);
		virtual ~CompoundProposition();
	public:
		/**
		*	复合类型
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(CompoundPropositionType, CompoundType, CompoundPropositionType::NONE);
	public:
		/**
		*	是否相同
		*/
		virtual bool isSameTo(Proposition* proposition);
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