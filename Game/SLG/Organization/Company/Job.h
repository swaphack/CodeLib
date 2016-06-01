#pragma once

#include "Company.h"
#include "JobPosition.h"
#include "Wages.h"

namespace slg
{
	// ����
	class Job
	{
	public:
		Job();
		virtual ~Job();
	public:
		// ��˾
		Company* getCompany();
		void setCompany(Company* company);

		// ְλ
		JobPosition* getJobPosition();
		void setJobPosition(JobPosition* position);

		// ����ʱ��
		int getWorkTime();
		void setWorkTime(int workTime);

		// н��
		Wages* getWages();
		void setWages(Wages* wages);
	private:
		// ��˾
		Company* _company;
		// ְλ
		Job* _job;
		// ����ʱ��
		int _workTime;
		// н��
		Wages* _wages;
	};
}