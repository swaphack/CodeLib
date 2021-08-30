#pragma once

#include "Algebra/import.h"
#include "Geometry/base/Points.h"
#include "Geometry/3d/LineSegment3d.h"

namespace math
{
	/**
	*	������
	*/
	struct TrianglePoints : public Points<Vector3, 3>
	{
	public:
		TrianglePoints();
		TrianglePoints(const Vector3& p0, const Vector3& p1, const Vector3& p2);
		TrianglePoints(const std::vector<Vector3>& points);
		TrianglePoints(const Vector3* points);
		virtual ~TrianglePoints();
	public:
		CREATE_INDEX_VALUE(Point0, 0, Vector3);
		CREATE_INDEX_VALUE(Point1, 1, Vector3);
		CREATE_INDEX_VALUE(Point2, 2, Vector3);
	public:
		/*
		*	�Ƿ��й���
		*/
		bool hasSameEdge(const TrianglePoints& target, LineSegment3d& side);
	public:
		/*
		*	���� ���߽���
		*/
		static Vector3 getCentreOfGravity(const Vector3& p0, const Vector3& p1, const Vector3& p2);
		/*
		*	����
		*/
		static Vector3 getInCenter(const Vector3& p0, const Vector3& p1, const Vector3& p2);
		/*
		*	����3d
		*/
		static Vector3 getCircumcenter(const Vector3& p0, const Vector3& p1, const Vector3& p2);
		/*
		*	����2d
		*/
		static Vector3 getCircumcenter2d(const Vector3& p0, const Vector3& p1, const Vector3& p2);
		/**
		*	��ȡ����
		*/
		static Vector3 getNormal(const Vector3& p0, const Vector3& p1, const Vector3& p2);
	};
}
