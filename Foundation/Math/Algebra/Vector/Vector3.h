#pragma once

#include <cmath>
#include <cstdint>

#include "Vector.h"

namespace math
{
	struct Vector2;
	// 3d
	struct Vector3 : public Vector<float, 3>
	{
	public:
		Vector3();
		Vector3(float x, float y, float z = 0);
		Vector3(const Vector& vector);
		Vector3(const Vector2& vector);
		Vector3(const Vector3& vector);
		Vector3(const Array<float, 3>& vector);
		virtual ~Vector3();
	public:
		CREATE_INDEX_VALUE(X, 0, float);
		CREATE_INDEX_VALUE(Y, 1, float);
		CREATE_INDEX_VALUE(Z, 2, float);

		void set(float x, float y, float z);
		void set(float x, float y);
	public:
		/**
		*	平移
		*/
		Vector3 tranlate(const Vector3& vector) const;
		/**
		*	缩放
		*/
		Vector3 scale(const Vector3& vector) const;
		/**
		*	绕轴旋转
		*/
		Vector3 rotationByAxis(const Vector3& vector, float radian) const;
		/**
		*	绕轴线段旋转度数
		*/
		Vector3 rotationByLine(const Vector3& src, const Vector3& dest, float radian) const;
	public:
		/**
		*	单位化
		*/
		void normalize();
		/**
		*	复制元素
		*/
		Vector3& operator=(const Vector3& vec);
		/**
		*	复制元素
		*/
		Vector3 operator=(const Vector3& vec) const;
	public:
		/**
		*	相加
		*/
		Vector3 operator+(const Vector3& vec) const;
		/**
		*	相减
		*/
		Vector3 operator-(const Vector3& vec) const;
		/**
		*	相乘
		*/
		Vector3 operator*(const Vector3& vec) const;
		/**
		*	相除
		*/
		Vector3 operator/(const Vector3& vec) const;
		/**
		*	相乘
		*/
		Vector3 operator*(float k) const;
		/**
		*	相除
		*/
		Vector3 operator/(float k) const;
		/**
		*	相加
		*/
		Vector3& operator+=(const Vector3& vec);
		/**
		*	相减
		*/
		Vector3& operator-=(const Vector3& vec);
		/**
		*	相乘
		*/
		Vector3& operator*=(const Vector3& vec);
		/**
		*	相除
		*/
		Vector3& operator/=(const Vector3& vec);
		/**
		*	相乘
		*/
		Vector3& operator*=(float k);
		/**
		*	相除
		*/
		Vector3& operator/=(float k);
	public:
		/**
		*	相等
		*/
		bool operator==(const Vector3& vec) const;
		/**
		*	不相等
		*/
		bool operator!=(const Vector3& vec) const;
		/**
		*	转为2维
		*/
		operator Vector2() const;
	public:
		/**
		*	向量点积
		*	a * b = |a||b|cos<a, b>
		*/
		static float dot(const Vector3& vector0, const Vector3& vector1);
		/**
		*	向量叉积
		*	a x b = n |a||b|sin<a, b>
		*	长度等于围成平行四边形的面积
		*/
		static Vector3 cross(const Vector3& vector0, const Vector3& vector1);
		/**
		*	vector1和vector0的夹角的弧度
		*/
		static float getRadian(const Vector3& vector0, const Vector3& vector1);
		/**
		*	vector1和vector0的夹角余弦值
		*/
		static float cosValue(const Vector3& vector0, const Vector3& vector1);
		/**
		*	vector1和vector0的夹角正弦值(0,PI)
		*/
		static float sinValue(const Vector3& vector0, const Vector3& vector1);
		/**
		*	两点间的距离
		*/
		static float distance(const Vector3& point0, const Vector3& point1);
		/**
		*	获得vector1在vector0的投影长度
		*/
		static float project(const Vector3& vector0, const Vector3& vector1);
		/**
		*	三点共线
		*/
		static bool isThreePointsCollinear(const Vector3& point0, const Vector3& point1, const Vector3& point2);
		/**
		*	三向量共面
		*/
		static bool isThreeVectorInSamePlane(const Vector3& vector0, const Vector3& vector1, const Vector3& vector2);

		/**
		*	二重外积
		*	a x b x r = (a * r) b - (b * r）a
		*/
		static Vector3 calDoubleCross(const Vector3& vector0, const Vector3& vector1, const Vector3& vector2);

		/**
		*	三重积
		*	a x b * c = b x c * a = c x a * b
		*	a x b * c = a * b x c
		*	由a,b,c构成平行六面体体积
		*/
		static float calTripleProduct(const Vector3& vector0, const Vector3& vector1, const Vector3& vector2);
		/**
		*	单位化
		*/
		static Vector3 normalize(const Vector3& vector);
	};

	static inline Vector3 operator*(float k, const Vector3& value)
	{
		return value * k;
	}
}