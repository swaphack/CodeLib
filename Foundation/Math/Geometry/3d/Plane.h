#pragma once

#include "Algebra/import.h"
#include "Line3d.h"

namespace math
{
	/**
	*	ƽ�淽��
	*	Ax + By + Cz + D = 0;
	*/
	struct Plane
	{
	public:
		/**
		*	����ȷ��һ��ƽ��
		*/
		Plane(const Vector3& point0, const Vector3& point1, const Vector3& point2);
		/**
		*	���㣬��֪��������
		*/
		Plane(const Vector3& point, const Vector3& normal);
		/**
		*	��������
		*/
		Plane(float a, float b, float c, float d);
		/**
		*	����
		*/
		Plane(const Plane& plane);
		virtual ~Plane();
	public:
		float getParamA() const;
		float getParamB() const;
		float getParamC() const;
		float getParamD() const;
		/**
		*	����
		*/
		const Vector3& getNormal() const;
	public:
		/**
		*	�㵽ƽ��ľ���
		*/
		float getDistanceWithPoint(const Vector3& point);
		/**
		*	ֱ���뵽ƽ��Ľ���
		*/
		bool getIntersectPointWithLine(const Line3d& line, Vector3& point);
		/**
		*	��ƽ��Ľ���
		*/
		bool getIntersectLineWithPlane(const Plane& plane, Line3d& line);
		/**
		*	����ƽ��Ľ���
		*/
		bool getIntersectPointWithTwoPlanes(const Plane& plane1, const Plane& plane2, Vector3& point);
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