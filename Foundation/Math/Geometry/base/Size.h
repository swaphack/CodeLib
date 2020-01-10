#pragma once

#include "Algebra/Vector.h"
#include "Vector2.h"

namespace math
{
	/**
	*	Ãæ»ý
	*/
	struct Size : public Vector
	{
	public:
		Size();
		Size(float w, float h);
		Size(const Size& size);
	public:
		CREATE_AXIS(Width, 0);
		CREATE_AXIS(Height, 1);

		void set(float w, float h);
	};
}