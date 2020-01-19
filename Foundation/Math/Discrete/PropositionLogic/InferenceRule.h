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
		virtual bool check(Proposition* a, Proposition* b);
	};
}