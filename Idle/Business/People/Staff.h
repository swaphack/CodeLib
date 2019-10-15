#pragma once

#include "Human.h"

#include <string>

namespace business
{
	class Corporation;
	// 员工
	class Staff : public Human
	{
	public:
		Staff();
		virtual ~Staff();
	public:
		// 所属公司
		void setCorporation(Corporation* corp);
		Corporation* getCorporation();


	protected:
	private:
		// 所属公司
		Corporation* m_Corporation = nullptr;
	};

	
}

