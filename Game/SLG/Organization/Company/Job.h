#pragma once

#include "Company.h"
#include "JobPosition.h"
#include "Wages.h"

namespace slg
{
	// 工作
	class Job
	{
	public:
		Job();
		virtual ~Job();
	public:
		// 公司
		Company* getCompany();
		void setCompany(Company* company);

		// 职位
		JobPosition* getJobPosition();
		void setJobPosition(JobPosition* position);

		// 工作时长
		int getWorkTime();
		void setWorkTime(int workTime);

		// 薪资
		Wages* getWages();
		void setWages(Wages* wages);
	private:
		// 公司
		Company* _company;
		// 职位
		Job* _job;
		// 工作时长
		int _workTime;
		// 薪资
		Wages* _wages;
	};
}