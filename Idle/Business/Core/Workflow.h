#pragma once

#include "Object.h"

#include <vector>

namespace business
{
	class Department;

	// ��������
	class Workflow : public Object
	{
	public:
		Workflow();
		virtual ~Workflow();
	public:
		void pushDepartment(Department* department);
	protected:
	private:
		std::vector<Department*> m_vecDepartment;
	};
}