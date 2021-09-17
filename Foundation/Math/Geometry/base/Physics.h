#pragma once
#include "Geometry/base/Ray.h"
#include "Geometry/Collider/BoundingBox.h"
#include "Geometry/3d/Plane.h"
#include "Geometry/shape/TrianglePoints.h"

namespace math
{
	struct HitCastInfo
	{

	};
	class Physics
	{
	public:
		/**
		*	包围盒
		*/
		static bool raycast(const Ray& ray, const BoundingBox& box);
		/**
		*	平面
		*/
		static bool raycast(const Ray& ray, const Plane& plane);
		/**
		*	三角形
		*/
		static bool raycast(const Ray& ray, const math::TrianglePoints& points, math::Vector3& point);
		/**
		*	计算反射角
		*/
		static math::Vector3 reflect(const math::Vector3& light, const math::Vector3& normal);

	private:
		/**
		*	获取射线与平面的位置关系 -1 异面, 0平行,1相交
		*/
		static int getRayPosition(const Ray& ray, const Plane& plane, float& a, float& b, float& c);
	};
}