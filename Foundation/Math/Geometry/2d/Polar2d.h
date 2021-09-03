#pragma once

#include "Algebra/import.h"

namespace math
{
	/**
	*	极坐标
	*	二维圆坐标
	*/
	struct Polar2d : public Vector<float, 2>
	{
	public:
		Polar2d();
		Polar2d(float r, float radian);
		Polar2d(const Vector2& vector);
		Polar2d(const Polar2d& polar);
		virtual ~Polar2d();
	public:
		CREATE_INDEX_VALUE(Radius, 0, float);
		CREATE_INDEX_VALUE(Radian, 1, float);
	public:
		void set(float r, float radian);
	public:
		virtual Polar2d& operator=(const Polar2d& polar);
		virtual Polar2d& operator=(const Vector2& vector);

		virtual Polar2d& operator+=(float radian);
		virtual Polar2d& operator-=(float radian);
		virtual Polar2d& operator*=(float ratio);
		virtual Polar2d& operator/=(float ratio);

		virtual Polar2d operator+(float radian);
		virtual Polar2d operator-(float radian);
		virtual Polar2d operator*(float ratio);
		virtual Polar2d operator/(float ratio);

		virtual bool operator==(const Polar2d& polar);
		virtual bool operator!=(const Polar2d& polar);
	public:
		operator Vector2() const;
	};
}