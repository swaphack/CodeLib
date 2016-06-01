#pragma once

#include "../Family/Human.h"
#include "Job.h"

namespace slg
{
	// ����
	class Worker : public Human
	{
	public:
		Worker();
		virtual ~Worker();
	public:
		// ����
		const Job* getJob();
		void setJob(const Job* job);
	private:
		// ����
		Job* _job;
	};
}