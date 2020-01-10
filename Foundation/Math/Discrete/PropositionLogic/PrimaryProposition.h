#pragma once

#include "Proposition.h"
#include "Basic/base.h"

namespace math
{
	/**
	*	结果
	*/
	enum class PropositionResult
	{
		/**
		*	假
		*/
		FALSE,
		/**
		*	真
		*/
		TRUE,
	};

	/**
	*	初级命题
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
		*	命题结果
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(PropositionResult, Result, PropositionResult::TRUE);
	public:
		/**
		*	是否为真
		*/
		virtual bool isTrue();
		/**
		*	是否相同
		*/
		virtual bool isSameTo(Proposition* proposition);
	public:
		/**
		*	复制
		*/
		PrimaryProposition& operator=(const PrimaryProposition& value);
	};
}