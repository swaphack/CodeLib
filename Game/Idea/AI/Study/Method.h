#pragma once

#include "Step.h"

namespace idea
{
	// ����
	class Method
	{
	public:
		Method();
		virtual ~Method();
	public:
		Step* getCurrentStep();
		Step* nextStep();
	protected:
	private:
	};
}