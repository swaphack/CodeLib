#pragma once

#include "Creator.h"
#include "../people/Person.h"

namespace game
{
	// ��Ա��
	class HumanSheet : public Creator<Person>
	{
	public:
		HumanSheet();
		virtual ~HumanSheet();
	protected:
	private:
	};
}