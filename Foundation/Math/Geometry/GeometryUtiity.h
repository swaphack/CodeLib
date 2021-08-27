#pragma once

#include "Algebra/Vector/import.h"
#include "2d/Size.h"

namespace math
{
	/**
	*	���ι���
	*/
	class GeometryUtiity
	{
	public:
		/**
		*	Ŀ����Ƿ����������ӽ���
		*/
		static bool isInsideOfTriangle(const Vector2& center, const Vector2& direction, float angle, const Vector2& target);
		/**
		*	Ŀ����Ƿ����������ӽ���
		*/
		static bool isInsideOfTriangle(const Vector2& center, const Vector2& direction, float angle, float radius, const Vector2& target);
		/**
		*	Ŀ����Ƿ����������ӽ���
		*/
		static bool isInsideOfTriangle(const Vector2& center, const Vector2& direction, float angle, float znear, float zfar, const Vector2& target);
		/**
		*	Ŀ����Ƿ���Բ׶�ӽ���
		*/
		static bool isInsideOfCone(const Vector3& center, const Vector3& direction, float angle, const Vector3& target);
		/**
		*	Ŀ����Ƿ���Բ׶�ӽ���
		*/
		static bool isInsideOfCone(const Vector3& center, const Vector3& direction, float angle, float radius, const Vector3& target);
		/**
		*	Ŀ����Ƿ���Բ׶�ӽ���
		*/
		static bool isInsideOfCone(const Vector3& center, const Vector3& direction, float angle, float znear, float zfar, const Vector3& target);

		/**
		*	Ŀ����Ƿ�������׶�ӽ���
		*/
		static bool isInsideOfPyramid(const Vector3& center, const Vector3& direction, const Size& size, const Vector3& target);
		/**
		*	Ŀ����Ƿ�������׶�ӽ���
		*/
		static bool isInsideOfPyramid(const Vector3& center, const Vector3& direction, const Size& size, float radius, const Vector3& target);
		/**
		*	Ŀ����Ƿ���Բ׶�ӽ���
		*/
		static bool isInsideOfPyramid(const Vector3& center, const Vector3& direction, const Size& size, float znear, float zfar, const Vector3& target);

	public:
		/**
		*	�Ƿ��Ǳ�׼�Ķ���Σ����������ڵ���3,�������ڲ����ڹ��ߵ����
		*/
		static bool isStandardPolygon(const std::vector<math::Vector3>& polygon);
		/**
		*	�Ƿ���͹�����
		*/
		static bool isConvexPolygon(const std::vector<math::Vector3>& polygon);

		/**
		*	��ȡ͹�����
		*/
		static bool createConvexPolygon(const std::vector<math::Vector3>& inPoints, std::vector<math::Vector3>& outPoints);
	public:
		/**
		*	�Ƿ��Ǳ�׼�Ķ���Σ����������ڵ���3,�������ڲ����ڹ��ߵ����
		*	�ҹ���
		*/
		static bool isStandardSurface(const std::vector<math::Vector3>& surface);
		/**
		*	�Ƿ���͹�����
		*/
		static bool isConvexSurface(const std::vector<math::Vector3>& surface);
		/**
		*	����ƽ���Ƿ���
		*/
		static bool isCoplanarSurface(const std::vector<math::Vector3>& surface, const Vector3& point);
		/**
		*	�ĵ��Ƿ���
		*/
		static bool canSurfaceMakeCoplanar(const Vector3& point0, const Vector3& point1, const Vector3& point2,
			const Vector3& point3);
		/**
		*	ͶӰ��xoy��
		*/
		static std::vector<math::Vector3> projectSurfaceOnXOY(const std::vector<math::Vector3>& surface);
		/**
		*	ͶӰ��yoz��
		*/
		static std::vector<math::Vector3> projectSurfaceOnYOZ(const std::vector<math::Vector3>& surface);
		/**
		*	ͶӰ��xoz��
		*/
		static std::vector<math::Vector3> projectSurfaceOnXOZ(const std::vector<math::Vector3>& surface);
	public:
		/**
		*	�Ƿ�˳ʱ�뷽��
		*	point2 �����point0-point1
		*/
		static bool isClockWise(const Vector2& point0, const Vector2& point1, const Vector2& point2);
		/**
		*	�Ƿ���ʱ�뷽��
		*	point2 �����point0-point1
		*/
		static bool isCounterClockWise(const Vector2& point0, const Vector2& point1, const Vector2& point2);
	};
}
