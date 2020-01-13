#pragma once

#include "Basic/base.h"
#include "Basic/Collection/TreeNode.h"
#include "PropositionCache.h"
#include <cstdint>

namespace math
{
	/**
	*	��������
	*/
	enum class PropositionType
	{
		/**
		*	��������
		*/
		None,
		/**
		*	��������
		*/
		Primary,
		/**
		*	��������
		*/
		Compound,
	};

	class TautologyProposition;
	class ContradictoryProposition;

	/**
	*	����
	*/
	class Proposition : public TreeNode
	{		
	public:
		Proposition();
		Proposition(const Proposition& proposition);
		virtual ~Proposition();
	public:
		/**
		*	��������
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(PropositionType, Type, PropositionType::None);
		/**
		*	������ �������Ӵʻ��߻�������
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(uint64_t, LogicID, 0);
		/**
		*	ʵ�����
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(uint64_t, InstanceID, 0);
	public:
		/**
		*	�Ƿ�Ϊ��
		*/
		virtual bool isTrue();
		/**
		*	�߼��Ƿ���ͬ
		*/
		virtual bool hasSameLogic(Proposition* proposition);
	public:
		/**
		*	����
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
		*	�����ڵ�
		*/
		template<typename T, typename = typename std::enable_if<std::is_base_of<Proposition, T>::value, T>::type>
		static T* create()
		{
			T* t = _propositionCache.createProposition<T>();
			return t;
		}
		/**
		*	�����ڵ�
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
		*	�����ڵ�
		*/
		template<typename T, typename = typename std::enable_if<std::is_base_of<Proposition, T>::value, T>::type>
		static T* create(Proposition* a)
		{
			T* t = _propositionCache.createProposition<T>();
			t->setA(a);
			return t;
		}
		/**
		*	�����ڵ�
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
		*	��ջ���
		*/
		static void cleanCache();
		/**
		*	��������
		*/
		static TautologyProposition* getTautologyProposition();
		/**
		*	ì������
		*/
		static ContradictoryProposition* getContradictoryProposition();
	private:
		/**
		*	��������
		*/
		static TautologyProposition* _tautologyProposition;
		/**
		*	ì������
		*/
		static ContradictoryProposition* _contradictoryProposition;
		/**
		*	�ڵ㻺���
		*/
		static PropositionCache _propositionCache;
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	��������
	*/
	class TautologyProposition : public Proposition
	{
	public:
		TautologyProposition();
		virtual ~TautologyProposition();
	public:
		/**
		*	�Ƿ�Ϊ��
		*/
		virtual bool isTrue();
		/**
		*	�߼��Ƿ���ͬ
		*/
		virtual bool hasSameLogic(Proposition* proposition);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	ì������
	*/
	class ContradictoryProposition : public Proposition
	{
	public:
		ContradictoryProposition();
		virtual ~ContradictoryProposition();
	public:
		/**
		*	�Ƿ�Ϊ��
		*/
		virtual bool isTrue();
		/**
		*	�߼��Ƿ���ͬ
		*/
		virtual bool hasSameLogic(Proposition* proposition);
	};
}