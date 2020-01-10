#pragma once

#include "Proposition.h"

namespace math
{
	class Inference;
	/**
	*	�������
	*/
	class InferenceRule
	{
	public:
		InferenceRule();
		virtual ~InferenceRule();
	public:
		/**
		*	����
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(Inference*, Inference, nullptr);
	public:
		virtual bool check(Proposition* a, Proposition* b);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	����ʽ
	*/
	class TautologyRule : public InferenceRule
	{
	public:
		virtual bool check(Proposition* a, Proposition* b);
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	�߼��ȼ�
	*/
	class EqualRule : public InferenceRule
	{
	public:
		virtual bool check(Proposition* a, Proposition* b);
	};
	//////////////////////////////////////////////////////////////////////////

}