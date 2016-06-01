#pragma once

#include "../macros.h"
#include "Site.h"
#include "Worker.h"

namespace slg
{
	class Worker;

	// 公司
	class Company : public Target
	{
	public:
		Company();
		virtual ~Company();
	public:
		// 办公所在地
		const Site* getLocation();

		void addWorker(const Worker* worker);
		void removeWorker(const Worker* worker);
		void removeAllWorks();

		std::vector<Worker*> getWorker(JobPosition* posiiton);
		std::vector<Worker*> getWorker(const char* name);
	protected:
	private:
	};
}