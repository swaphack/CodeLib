#pragma once

#include "Algebra/Vector.h"
#include "Vector3.h"

namespace math
{
	/**
	*	极坐标
	*	三维球面坐标
	*/
	struct Polar3 : Vector
	{
	public:
		Polar3();
		Polar3(float r, float radianX, float radianZ);
		Polar3(const Vector3& vector);
		Polar3(const Polar3& polar);
		virtual ~Polar3();
	public:
		CREATE_AXIS(Radius, 0);
		CREATE_AXIS(RadianX, 1);
		CREATE_AXIS(RadianZ, 2);
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