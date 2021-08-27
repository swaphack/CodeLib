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

	public:
		/**
		*	是否是标准的多边形，顶点数大于等于3,并且相邻不存在共线的情况
		*/
		static bool isStandardPolygon(const std::vector<math::Vector3>& polygon);
		/**
		*	是否是凸多边形
		*/
		static bool isConvexPolygon(const std::vector<math::Vector3>& polygon);

		/**
		*	获取凸多边形
		*/
		static bool createConvexPolygon(const std::vector<math::Vector3>& inPoints, std::vector<math::Vector3>& outPoints);
	public:
		/**
		*	是否是标准的多边形，顶点数大于等于3,并且相邻不存在共线的情况
		*	且共面
		*/
		static bool isStandardSurface(const std::vector<math::Vector3>& surface);
		/**
		*	是否是凸多边形
		*/
		static bool isConvexSurface(const std::vector<math::Vector3>& surface);
		/**
		*	点与平面是否共面
		*/
		static bool isCoplanarSurface(const std::vector<math::Vector3>& surface, const Vector3& point);
		/**
		*	四点是否共面
		*/
		static bool canSurfaceMakeCoplanar(const Vector3& point0, const Vector3& point1, const Vector3& point2,
			const Vector3& point3);
		/**
		*	投影到xoy面
		*/
		static std::vector<math::Vector3> projectSurfaceOnXOY(const std::vector<math::Vector3>& surface);
		/**
		*	投影到yoz面
		*/
		static std::vector<math::Vector3> projectSurfaceOnYOZ(const std::vector<math::Vector3>& surface);
		/**
		*	投影到xoz面
		*/
		static std::vector<math::Vector3> projectSurfaceOnXOZ(const std::vector<math::Vector3>& surface);
	public:
		/**
		*	是否顺时针方向
		*	point2 相对于point0-point1
		*/
		static bool isClockWise(const Vector2& point0, const Vector2& point1, const Vector2& point2);
		/**
		*	是否逆时针方向
		*	point2 相对于point0-point1
		*/
		static bool isCounterClockWise(const Vector2& point0, const Vector2& point1, const Vector2& point2);
	};
}
