#pragma once

#include "macros.h"

namespace idea
{
	// ≤Ω÷Ë
	class Step : public IWorker
	{
	public:
		Step();
		virtual ~Step();
	public:
		virtual Result* run(Event* e);
	protected:
	private:
	};
}