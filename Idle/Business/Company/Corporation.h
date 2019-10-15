#pragma once

#include "../Core/import.h"

namespace business
{
	class Project;
	class Department;

	// ¹«Ë¾
	class Corporation : public Object
	{
	public:
		Corporation();
		virtual ~Corporation();
	public:
		void addDepartment(Department* pDept);
		void removeDepartment(uint64_t nDeptID);

	protected:
	private:
	};
}