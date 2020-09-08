#pragma once

#include "Algebra/import.h"

namespace math
{
	/**
	*	极坐标
	*	三维球面坐标
	*/
	struct Polar3d : public Vector<float, 3>
	{
	public:
		Polar3d();
		Polar3d(float r, float radianX, float radianZ);
		Polar3d(const Vector3& vector);
		Polar3d(const Polar3d& polar);
		virtual ~Polar3d();
	public:
		CREATE_INDEX_VALUE(Radius, 0, float);
		CREATE_INDEX_VALUE(RadianX, 1, float);
		CREATE_INDEX_VALUE(RadianZ, 2, float);
	public:
		void set(float r, float radianX, float radianZ);
	public:
		virtual Polar3d& operator=(const Polar3d& polar);
		virtual Polar3d& operator=(const Vector3& vector);
		virtual Polar3d& operator*=(float ratio);
		virtual Polar3d& operator/=(float ratio);
		virtual Polar3d operator*(float ratio);
		virtual Polar3d operator/(float ratio);

		virtual bool operator==(const Polar3d& polar);
		virtual bool operator!=(const Polar3d& polar);
	public:
		operator Vector3();
	};
}