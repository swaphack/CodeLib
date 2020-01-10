#pragma once

#include "Algebra/Vector.h"
#include "Vector2.h"

namespace math
{
	/**
	*	极坐标
	*	二维圆坐标
	*/
	struct Polar2 : Vector
	{
	public:
		Polar2();
		Polar2(float r, float radian);
		Polar2(const Vector2& vector);
		Polar2(const Polar2& polar);
		virtual ~Polar2();
	public:
		CREATE_AXIS(Radius, 0);
		CREATE_AXIS(Radian, 1);
	public:
		void set(float r, float radian);
	public:
		virtual Polar2& operator=(const Polar2& polar);
		virtual Polar2& operator=(const Vector2& vector);

		virtual Polar2& operator+=(float radian);
		virtual Polar2& operator-=(float radian);
		virtual Polar2& operator*=(float ratio);
		virtual Polar2& operator/=(float ratio);

		virtual Polar2 operator+(float radian);
		virtual Polar2 operator-(float radian);
		virtual Polar2 operator*(float ratio);
		virtual Polar2 operator/(float ratio);

		virtual bool operator==(const Polar2& polar);
		virtual bool operator!=(const Polar2& polar);
	public:
		operator Vector2();
	};
}