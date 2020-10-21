#pragma once

#include "Algebra/import.h"

namespace math
{
	struct Plane;
	/**
	*	ֱ�߷���
	*	(x - x0) / vx = (y - y0) / vy = (z - z0)/ vz
	*/
	struct Line3d
	{
	public:
		/**
		*	����ȷ��һ��ֱ��
		*/
		Line3d(const Vector3& src, const Vector3& dest);
		/**
		*	��ƽ���ཻ��ȷ��һ��ֱ��
		*/
		Line3d(const Plane& plane0, const Plane& plane1);
		Line3d(const Line3d& line);
		virtual ~Line3d();
	public:
		/**
		*	��
		*/
		const Vector3& getPoint() const;
		/**
		*	����
		*/
		const Vector3& getDirection() const;
	public:
		/**
		*	�㵽ֱ�ߵľ���
		*/
		float getDistanceWithPoint(const Vector3& point);
		/**
		*	�Ƿ������
		*/
		bool contains(const Vector3& point);
		/**
		*	�Ƿ�ƽ��
		*/
		bool isParallel(const Line3d& line);
		/**
		*	�Ƿ��ཻ
		*/
		bool isIntersect(const Line3d& line);
	private:
		/**
		* ��
		*/
		Vector3 _point;
		/**
		*	����
		*/
		Vector3 _direction;
	};

}