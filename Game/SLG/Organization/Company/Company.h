#pragma once

#include "../macros.h"
#include "Site.h"
#include "Worker.h"

namespace slg
{
	class Worker;

	// ��˾
	class Company : public Target
	{
	public:
		Company();
		virtual ~Company();
	public:
		// �칫���ڵ�
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