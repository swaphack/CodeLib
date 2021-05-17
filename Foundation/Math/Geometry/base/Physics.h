#pragma once
#include "Geometry/base/Ray.h"
#include "Geometry/Collider/BoundingBox.h"
#include "Geometry/3d/Plane.h"

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
		*	ƽ������
		*/
		static bool raycast(const Ray& ray, const std::vector<math::Vector3>& planePoints);
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