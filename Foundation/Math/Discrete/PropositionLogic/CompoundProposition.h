#pragma once

#include "Proposition.h"
#include "Basic/base.h"

#include <vector>

namespace math
{
	/**
	*	��������
	*	Ҷ�ӽڵ��ǻ������⣬�����ڵ�Ϊ�߼�����
	*/
	class CompoundProposition : public Proposition
	{
	public:
		// ��
		static const uint64_t COMPOUND_PROPOSITION_SIGNAL_AND = 1000001;
		// ��
		static const uint64_t COMPOUND_PROPOSITION_SIGNAL_OR = 1000001;
		// ��
		static const uint64_t COMPOUND_PROPOSITION_SIGNAL_NOT = 1000001;
		// ���
		static const uint64_t COMPOUND_PROPOSITION_SIGNAL_XOR = 1000001;
		// �̺�
		static const uint64_t COMPOUND_PROPOSITION_SIGNAL_IMPLICATE = 1000001;
		// ˫���̺�
		static const uint64_t COMPOUND_PROPOSITION_SIGNAL_DOUBLEIMPLICATE = 1000001;
	public:
		CompoundProposition();
		CompoundProposition(const CompoundProposition& value);
		virtual ~CompoundProposition();
	public:
		/**
		*	�Ƿ���ͬ
		*/
		virtual bool hasSameLogic(Proposition* proposition);
		/**
		*	��ȡ����Ψһid�ڵ�
		*/
		std::set<TreeNode*> getAllUniqueIdentifyChildren();
		/**
		*	�ӽڵ��Ƿ��ǻ�������
		*/
		bool isPrimaryPropositionOfAllChildren();
		/**
		*	��¡�ڵ㣬�������ӽڵ�
		*/
		virtual Proposition* clone();
		/**
		*	��¡�ڵ㣬�����ӽڵ�
		*/
		virtual Proposition* deepClone();
	protected:
		/**
		*	����ƥ��
		*/
		bool matchChildren(const std::vector<TreeNode*>& children);
		/**
		*	��ȸ����ӽڵ�
		*/
		std::vector<TreeNode*> deepCloneChildren();
	public:
		/**
		*	��ֵ
		*/
		CompoundProposition& operator=(const CompoundProposition& value);
	};

	
}