#pragma once

#include "macros.h"

namespace idea
{
	// ѧϰ����
	class StudyStep : public Step
	{
	public:
		StudyStep();
		virtual ~StudyStep();
	public:
		virtual Result* run(Event* e);
	};
}