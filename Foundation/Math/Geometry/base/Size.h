#pragma once

#include "Algebra/import.h"

namespace math
{
	/**
	*	Ãæ»ý
	*/
	struct Size : public Vector<float, 2>
	{
	public:
		Size();
		Size(float w, float h);
		Size(const Size& size);
		virtual ~Size();
	public:
		CREATE_INDEX_VALUE(Width, 0, float);
		CREATE_INDEX_VALUE(Height, 1, float);

		void set(float w, float h);
	};
}