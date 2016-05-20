#pragma once

#include "macros.h"

namespace idea
{
	// 学习
	class Study : public IWorker
	{
	public:
		Study();
		~Study();
	public:
		// 学习
		virtual Result* run(Event* e);
	protected:
	private:
	};
}