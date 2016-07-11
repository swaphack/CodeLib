#pragma once

#include "macros.h"

namespace idea
{
	// —ßœ∞≤Ω÷Ë
	class StudyStep : public Step
	{
	public:
		StudyStep();
		virtual ~StudyStep();
	public:
		virtual Result* run(Event* e);
	};
}