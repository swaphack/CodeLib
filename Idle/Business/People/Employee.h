#pragma once

#include "Staff.h"

namespace business
{
	// Ա������
	enum EmployeeLevel
	{
		Level0,
		Level1,
		Level2,
		Level3,
		Level4,
		Level5,
	};

	class Employee : public Staff
	{
	public:
		Employee();
		virtual ~Employee();
	public:
		// ����
		void setLevel(EmployeeLevel eLevel);
		EmployeeLevel getLevel();
	protected:
	private:
	};
}