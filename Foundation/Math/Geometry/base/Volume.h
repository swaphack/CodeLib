#pragma once

#include "Algebra/Vector.h"
#include "Vector3.h"

namespace math
{
	/**
	*	体积
	*/
	struct Volume : protected Vector
	{
	public:
		Volume();
		Volume(float w, float h);
		Volume(float w, float h, float d);
		Volume(const Volume& volumn);
	public:
		CREATE_AXIS(Width, 0);
		CREATE_AXIS(Height, 1);
		CREATE_AXIS(Deep, 2);

		void set(float w, float h, float d);
		void set(float w, float h);
	public:
		/**
		*	相乘
		*/
		virtual Volume operator*(const Vector3& vec) const;
		/**
		*	相乘
		*/
		virtual Volume& operator*=(const Vector3& vec);
	};

	
}