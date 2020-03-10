#pragma once

#include "Algebra/import.h"
#include "macros.h"

namespace math
{
	struct Plane;
	/**
	*	ֱ�߷���
	*	(x - x0) / vx = (y - y0) / vy = (z - z0)/ vz
	*/
	struct Line3
	{
	public:
		/**
		*	����ȷ��һ��ֱ��
		*/
		Line3(const Vector3& src, const Vector3& dest);
		/**
		*	��ƽ���ཻ��ȷ��һ��ֱ��
		*/
		Line3(const Plane& plane0, const Plane& plane1);
		Line3(const Line3& line);
		virtual ~Line3();
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
		bool isParallel(const Line3& line);
		/**
		*	�Ƿ��ཻ
		*/
		bool isIntersect(const Line3& line);
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