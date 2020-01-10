#pragma once

#include "Proposition.h"
#include "Basic/base.h"

#include <vector>

namespace math
{
	/**
	*	��������
	*/
	enum class CompoundPropositionType
	{
		NONE,
		AND,
		OR,
		NOT,
		// �̺�
		Implicate,
		// ˫���̺�
		DoubleImplicate,
	};
	/**
	*	��������
	*	Ҷ�ӽڵ��ǻ������⣬�����ڵ�Ϊ�߼�����
	*/
	class CompoundProposition : public Proposition
	{
	public:
		CompoundProposition();
		CompoundProposition(const CompoundProposition& value);
		virtual ~CompoundProposition();
	public:
		/**
		*	��������
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(CompoundPropositionType, CompoundType, CompoundPropositionType::NONE);
	public:
		/**
		*	�Ƿ���ͬ
		*/
		virtual bool isSameTo(Proposition* proposition);
		/**
		*	��ȡ����Ψһid�ڵ�
		*/
		std::set<TreeNode*> getAllUniqueIdentifyChildren();
	protected:
		/**
		*	����ƥ��
		*/
		bool matchChildren(const std::vector<TreeNode*>& children);
	public:
		/**
		*	��ֵ
		*/
		CompoundProposition& operator=(const CompoundProposition& value);
	};

	
}