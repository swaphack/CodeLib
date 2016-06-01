#pragma once

#include "../Family/Human.h"
#include "Job.h"

namespace slg
{
	// 工人
	class Worker : public Human
	{
	public:
		Worker();
		virtual ~Worker();
	public:
		// 工作
		const Job* getJob();
		void setJob(const Job* job);
	private:
		// 工作
		Job* _job;
	};
}