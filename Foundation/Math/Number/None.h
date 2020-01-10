#pragma once

#include "Number.h"

namespace math
{
	/**
	*	不存在的数
	*/
	class None : public Number
	{
	public:
		None();
		virtual ~None();
	};
}