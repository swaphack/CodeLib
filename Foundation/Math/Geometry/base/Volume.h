#pragma once

#include "Algebra/import.h"

namespace math
{
	/**
	*	���
	*/
	struct Volume : public Vector
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
		*	���
		*/
		virtual Volume operator*(const Vector3& vec) const;
		/**
		*	���
		*/
		virtual Volume& operator*=(const Vector3& vec);
	};

	
}