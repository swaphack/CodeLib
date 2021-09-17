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
		*	��Χ��
		*/
		static bool raycast(const Ray& ray, const BoundingBox& box);
		/**
		*	ƽ��
		*/
		static bool raycast(const Ray& ray, const Plane& plane);
		/**
		*	������
		*/
		static bool raycast(const Ray& ray, const math::TrianglePoints& points, math::Vector3& point);
		/**
		*	���㷴���
		*/
		static math::Vector3 reflect(const math::Vector3& light, const math::Vector3& normal);

	private:
		/**
		*	��ȡ������ƽ���λ�ù�ϵ -1 ����, 0ƽ��,1�ཻ
		*/
		static int getRayPosition(const Ray& ray, const Plane& plane, float& a, float& b, float& c);
	};
}