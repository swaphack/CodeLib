#pragma once

#include "Step.h"
#include <vector>

namespace idea
{
	// ·½·¨
	class Method
	{
	public:
		Method();
		virtual ~Method();
	public:
		Step* getCurrentStep();
		Step* nextStep();

		void addStep(Step* step);
		void removeStep(Step* step);
		void removeAllSteps();
	protected:
	private:
		int _cursor;
		std::vector<Step*> _steps;
	};
}