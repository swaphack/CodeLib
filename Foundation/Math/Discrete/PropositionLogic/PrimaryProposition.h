#pragma once

#include "Proposition.h"
#include "Basic/base.h"

namespace math
{
	/**
	*	���
	*/
	enum class PropositionResult
	{
		/**
		*	��
		*/
		FALSE,
		/**
		*	��
		*/
		TRUE,
	};

	/**
	*	��������
	*/
	class PrimaryProposition : public Proposition
	{
	public:
		PrimaryProposition();
		PrimaryProposition(PropositionResult result);
		PrimaryProposition(const PrimaryProposition& value);
		virtual ~PrimaryProposition();
	public:
		/**
		*	������
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(PropositionResult, Result, PropositionResult::TRUE);
		/**
		*	������
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(uint64_t, Identify, 0);
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
		PrimaryProposition& operator=(const PrimaryProposition& value);
	};
}