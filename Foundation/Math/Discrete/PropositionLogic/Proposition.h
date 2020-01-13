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

	class TautologyProposition;
	class ContradictoryProposition;

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
		static T* create()
		{
			T* t = _propositionCache.createProposition<T>();
			return t;
		}
		/**
		*	创建节点
		*/
		template<typename T, typename = typename std::enable_if<std::is_base_of<Proposition, T>::value, T>::type>
		static T* create(uint64_t id, PropositionResult result)
		{
			T* t = _propositionCache.createProposition<T>();
			t->setLogicID(id);
			t->setResult(result);
			return t;
		}
		/**
		*	创建节点
		*/
		template<typename T, typename = typename std::enable_if<std::is_base_of<Proposition, T>::value, T>::type>
		static T* create(Proposition* a)
		{
			T* t = _propositionCache.createProposition<T>();
			t->setA(a);
			return t;
		}
		/**
		*	创建节点
		*/
		template<typename T, typename = typename std::enable_if<std::is_base_of<Proposition, T>::value, T>::type>
		static T* create(Proposition* a, Proposition* b)
		{
			T* t = _propositionCache.createProposition<T>();
			t->setA(a);
			t->setB(b);
			return t;
		}
		/**
		*	清空缓存
		*/
		static void cleanCache();
		/**
		*	永真命题
		*/
		static TautologyProposition* getTautologyProposition();
		/**
		*	矛盾命题
		*/
		static ContradictoryProposition* getContradictoryProposition();
	private:
		/**
		*	永真命题
		*/
		static TautologyProposition* _tautologyProposition;
		/**
		*	矛盾命题
		*/
		static ContradictoryProposition* _contradictoryProposition;
		/**
		*	节点缓存池
		*/
		static PropositionCache _propositionCache;
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	永真命题
	*/
	class TautologyProposition : public Proposition
	{
	public:
		TautologyProposition();
		virtual ~TautologyProposition();
	public:
		/**
		*	是否为真
		*/
		virtual bool isTrue();
		/**
		*	逻辑是否相同
		*/
		virtual bool hasSameLogic(Proposition* proposition);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	矛盾命题
	*/
	class ContradictoryProposition : public Proposition
	{
	public:
		ContradictoryProposition();
		virtual ~ContradictoryProposition();
	public:
		/**
		*	是否为真
		*/
		virtual bool isTrue();
		/**
		*	逻辑是否相同
		*/
		virtual bool hasSameLogic(Proposition* proposition);
	};
}