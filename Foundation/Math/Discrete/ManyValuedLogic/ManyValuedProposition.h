#pragma once

#include "../PropositionLogic/PrimaryProposition.h"

namespace math
{
	/**
	*	��ֵ����
	*/
	class ManyValuedProposition : public PrimaryProposition
	{
	public:
		CREATE_CLASS_MEMBER_WITH_DEFAULT(float, Percent, 0);
	public:
		/**
		*	�Ƿ�Ϊ��
		*/
		virtual bool isTrue() const;
		/**
		*	��ȡ�����ֵ
		*/
		virtual float getValue() const;
		/**
		*	�Ƿ���ͬ
		*/
		virtual bool hasSameLogic(Proposition* proposition);
	};
}