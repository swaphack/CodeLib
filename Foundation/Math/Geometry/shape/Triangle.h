#pragma once

#include "Algebra/import.h"
#include "Geometry/base/Points.h"
#include "Geometry/3d/LineSegment3d.h"

namespace math
{
	/**
	*	������
	*/
	struct Triangle : public Points<Vector3, 3>
	{
	public:
		Triangle();
		Triangle(const Vector3& p0, const Vector3& p1, const Vector3& p2);
		Triangle(const Vector3* points);
		virtual ~Triangle();
	public:
		CREATE_INDEX_VALUE(Point0, 0, Vector3);
		CREATE_INDEX_VALUE(Point1, 1, Vector3);
		CREATE_INDEX_VALUE(Point2, 3, Vector3);
	public:
		/*
		*	�Ƿ��й���
		*/
		bool hasSameEdge(const Triangle& target, LineSegment3d& side);

		/*
		*	���� ���߽���
		*/
		Vector3 getCentreOfGravity() const;
		/*
		*	����
		*/
		Vector3 getInCenter() const;
		/*
		*	����
		*/
		Vector3 getCircumcenter() const;
		/*
		*	����
		*/
		Vector3 getCircumcenter2d() const;
	public:
		/**
		*	��ȡ����
		*/
		Vector3 getNormal();
	};
}
