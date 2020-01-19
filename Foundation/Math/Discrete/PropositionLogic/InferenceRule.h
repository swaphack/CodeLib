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
		virtual bool check(Proposition* a, Proposition* b);
	};
}