#pragma once

#include "Proposition.h"

namespace math
{
	class Inference;
	/**
	*	推理规则
	*/
	class InferenceRule
	{
	public:
		InferenceRule();
		virtual ~InferenceRule();
	public:
		/**
		*	规则
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(Inference*, Inference, nullptr);
	public:
		virtual bool check(Proposition* a, Proposition* b);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	永真式
	*/
	class TautologyRule : public InferenceRule
	{
	public:
		virtual bool check(Proposition* a, Proposition* b);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	逻辑等价
	*/
	class EqualRule : public InferenceRule
	{
	public:
		virtual bool check(Proposition* a, Proposition* b);
	};
	//////////////////////////////////////////////////////////////////////////

}