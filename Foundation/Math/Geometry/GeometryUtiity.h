#pragma once

#include "Algebra/Vector/import.h"
#include "2d/Size.h"

namespace math
{
	/**
	*	几何工具
	*/
	class GeometryUtiity
	{
	public:
		/**
		*	目标点是否在三角形视角内
		*/
		static bool isInsideOfTriangle(const Vector2& center, const Vector2& direction, float angle, const Vector2& target);
		/**
		*	目标点是否在三角形视角内
		*/
		static bool isInsideOfTriangle(const Vector2& center, const Vector2& direction, float angle, float radius, const Vector2& target);
		/**
		*	目标点是否在三角形视角内
		*/
		static bool isInsideOfTriangle(const Vector2& center, const Vector2& direction, float angle, float znear, float zfar, const Vector2& target);
		/**
		*	目标点是否在圆锥视角内
		*/
		static bool isInsideOfCone(const Vector3& center, const Vector3& direction, float angle, const Vector3& target);
		/**
		*	目标点是否在圆锥视角内
		*/
		static bool isInsideOfCone(const Vector3& center, const Vector3& direction, float angle, float radius, const Vector3& target);
		/**
		*	目标点是否在圆锥视角内
		*/
		static bool isInsideOfCone(const Vector3& center, const Vector3& direction, float angle, float znear, float zfar, const Vector3& target);

		/**
		*	目标点是否在四棱锥视角内
		*/
		static bool isInsideOfPyramid(const Vector3& center, const Vector3& direction, const Size& size, const Vector3& target);
		/**
		*	目标点是否在四棱锥视角内
		*/
		static bool isInsideOfPyramid(const Vector3& center, const Vector3& direction, const Size& size, float radius, const Vector3& target);
		/**
		*	目标点是否在圆锥视角内
		*/
		static bool isInsideOfPyramid(const Vector3& center, const Vector3& direction, const Size& size, float znear, float zfar, const Vector3& target);
	};
}
