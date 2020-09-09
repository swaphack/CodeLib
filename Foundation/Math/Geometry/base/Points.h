#pragma once

#include "Basic/Array.h"

namespace math
{
	template<typename T, const int Length>
	struct Points : public Array<T, Length>
	{
	public:
		Points(){}
		Points(const T* value)
		{
			this->assign(value);
		}
		virtual ~Points() {}
	public:

	};
}
