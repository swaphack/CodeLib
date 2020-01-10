#pragma once

#include "Basic/base.h"
#include "Basic/Collection/TreeNode.h"
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
		*	������
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(uint64_t, Identify, 0);
	public:
		/**
		*	���������Ƿ����
		*/
		bool hasSameIdentify(Proposition* proposition);
		/**
		*	�Ƿ���ͬ
		*/
		virtual bool isSameTo(Proposition* proposition);
	public:
		/**
		*	�Ƿ�Ϊ��
		*/
		virtual bool isTrue();
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
	};
}