#pragma once

#include "../PropositionLogic/Proposition.h"

namespace math
{
	/**
	*	��ֵ����
	*/
	class ManyValuedProposition : public Proposition
	{
	public:
		ManyValuedProposition();
		ManyValuedProposition(float percent);
		ManyValuedProposition(const ManyValuedProposition& proposition);
		virtual ~ManyValuedProposition();
	public:
		/**
		*	�ٷֱ�
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(float, Percent, 0);
	public:
		/**
		*	�Ƿ�Ϊ��
		*/
		virtual bool isTrue();
		/**
		*	�Ƿ�����ͬ���߼�
		*/
		virtual bool hasSameLogic(Proposition* proposition);
		/**
		*	��¡�ڵ㣬�������ӽڵ�
		*/
		virtual Proposition* clone();
		/**
		*	��¡�ڵ㣬�����ӽڵ�
		*/
		virtual Proposition* deepClone();
	public:
		/**
		*	����
		*/
		ManyValuedProposition& operator=(const ManyValuedProposition& value);
	};
}