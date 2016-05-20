#pragma once

#include "macros.h"

namespace idea
{
	// 经验
	class Experience : public IWorker
	{
	public:
		Experience();
		virtual ~Experience();
	public:
		// 解决问题
		virtual Result* run(Event* e);
	protected:
	private:
	};
}