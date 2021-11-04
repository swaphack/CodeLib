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
		Volume operator*(const Vector3& vec) const;
		/**
		*	���
		*/
		Volume& operator*=(const Vector3& vec);
		/**
		*	���
		*/
		Volume operator*(float k) const;
		/**
		*	���
		*/
		Volume& operator*=(float k);
		/**
		*	���
		*/
		bool operator==(const Volume& vec) const;
		/**
		*	�����
		*/
		bool operator!=(const Volume& vec) const;
	public:
		/**
		*	תΪ3ά
		*/
		operator Vector3() const;
	};

	static inline Volume operator*(float k, const Volume& value)
	{
		return value * k;
	}
	
}