#pragma once

#include "Human.h"

#include <string>

namespace business
{
	class Corporation;
	// Ա��
	class Staff : public Human
	{
	public:
		Staff();
		virtual ~Staff();
	public:
		// ������˾
		void setCorporation(Corporation* corp);
		Corporation* getCorporation();


	protected:
	private:
		// ������˾
		Corporation* m_Corporation = nullptr;
	};

	
}

