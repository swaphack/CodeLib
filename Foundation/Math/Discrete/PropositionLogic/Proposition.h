#pragma once

#include "Basic/base.h"
#include "Basic/Collection/TreeNode.h"
#include "PropositionCache.h"
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
		*	命题编号 基础连接词或者基础命题
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(uint64_t, LogicID, 0);
		/**
		*	实例编号
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(uint64_t, InstanceID, 0);
	public:
		/**
		*	是否为真
		*/
		virtual bool isTrue();
		/**
		*	逻辑是否相同
		*/
		virtual bool hasSameLogic(Proposition* proposition);
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
	public:
		/**
		*	创建节点
		*/
		template<typename T, typename = typename std::enable_if<std::is_base_of<Proposition, T>::value, T>::type>
		static T* createProposition()
		{
			return _propositionCache.createProposition<T>();
		}
		static void cleanCache();
	private:
		/**
		*	节点缓存池
		*/
		static PropositionCache _propositionCache;
	};
}