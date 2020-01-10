#pragma once

#include "Basic/base.h"
#include "Basic/Collection/TreeNode.h"
#include <cstdint>

namespace math
{
	/**
	*	基本命题
	*/
	enum class PropositionType
	{
		/**
		*	不是命题
		*/
		None,
		/**
		*	基本命题
		*/
		Primary,
		/**
		*	复合命题
		*/
		Compound,
	};
	/**
	*	命题
	*/
	class Proposition : public TreeNode
	{		
	public:
		Proposition();
		Proposition(const Proposition& proposition);
		virtual ~Proposition();
	public:
		/**
		*	命题类型
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(PropositionType, Type, PropositionType::None);
		/**
		*	命题编号
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(uint64_t, Identify, 0);
	public:
		/**
		*	基础命题是否相等
		*/
		bool hasSameIdentify(Proposition* proposition);
		/**
		*	是否相同
		*/
		virtual bool isSameTo(Proposition* proposition);
	public:
		/**
		*	是否为真
		*/
		virtual bool isTrue();
	public:
		/**
		*	复制
		*/
		Proposition& operator=(const Proposition& value);
	public:
		bool operator==(const Proposition& value) const;
		bool operator!=(const Proposition& value) const;
		bool operator>=(const Proposition& value) const;
		bool operator>(const Proposition& value) const;
		bool operator<(const Proposition& value) const;
		bool operator<=(const Proposition& value) const;
	};
}