#pragma once

#include "Algebra/import.h"

namespace math
{
	/**
	*	极坐标
	*	三维球面坐标
	*/
	struct Polar3 : public Vector<float, 3>
	{
	public:
		Polar3();
		Polar3(float r, float radianX, float radianZ);
		Polar3(const Vector3& vector);
		Polar3(const Polar3& polar);
		virtual ~Polar3();
	public:
		CREATE_INDEX_VALUE(Radius, 0, float);
		CREATE_INDEX_VALUE(RadianX, 1, float);
		CREATE_INDEX_VALUE(RadianZ, 2, float);
	public:
		void set(float r, float radianX, float radianZ);
	public:
		virtual Polar3& operator=(const Polar3& polar);
		virtual Polar3& operator=(const Vector3& vector);
		virtual Polar3& operator*=(float ratio);
		virtual Polar3& operator/=(float ratio);
		virtual Polar3 operator*(float ratio);
		virtual Polar3 operator/(float ratio);

		virtual bool operator==(const Polar3& polar);
		virtual bool operator!=(const Polar3& polar);
	public:
		operator Vector3();
	};
}