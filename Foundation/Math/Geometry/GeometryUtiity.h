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
	};
}
