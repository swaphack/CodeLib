#pragma once

#include "Algebra/import.h"

namespace math
{
	/**
	*	ƽ�淽��
	*	Ax + By + Cz + D = 0;
	*/
	struct Plane3d
	{
	public:
		/**
		*	����ȷ��һ��ƽ��
		*/
		Plane3d(const Vector3& point0, const Vector3& point1, const Vector3& point2);
		/**
		*	���㣬��֪��������
		*/
		Plane3d(const Vector3& point, const Vector3& normal);
		/**
		*	��������
		*/
		Plane3d(float a, float b, float c, float d);
		/**
		*	����
		*/
		Plane3d(const Plane3d& plane);
		virtual ~Plane3d();
	public:
		float getParamA() const;
		float getParamB() const;
		float getParamC() const;
		float getParamD() const;
		/**
		*	����
		*/
		const Vector3& normal() const;
	public:
		/**
		*	�㵽ƽ��ľ���
		*/
		float getDistanceWithPoint(const Vector3& point);
	protected:
		float _paramA = 0;
		float _paramB = 0;
		float _paramC = 0;
		float _paramD = 0;
		/**
		*	����
		*/
		Vector3 _normal;
	};
}