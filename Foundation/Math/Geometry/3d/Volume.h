#pragma once

#include "Algebra/import.h"

namespace math
{
	/**
	*	���
	*/
	struct Volume : public Vector<float, 3>
	{
	public:
		Volume();
		Volume(float w, float h);
		Volume(float w, float h, float d);
		Volume(const Volume& volumn);
		virtual ~Volume();
	public:
		CREATE_INDEX_VALUE(Width, 0, float);
		CREATE_INDEX_VALUE(Height, 1, float);
		CREATE_INDEX_VALUE(Depth, 2, float);

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