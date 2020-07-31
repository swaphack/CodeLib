#pragma once

#include "Algebra/import.h"

namespace math
{
	/**
	*	极坐标
	*	二维圆坐标
	*/
	struct Polar2 : public Vector<float, 2>
	{
	public:
		Polar2();
		Polar2(float r, float radian);
		Polar2(const Vector2& vector);
		Polar2(const Polar2& polar);
		virtual ~Polar2();
	public:
		CREATE_INDEX_VALUE(Radius, 0, float);
		CREATE_INDEX_VALUE(Radian, 1, float);
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