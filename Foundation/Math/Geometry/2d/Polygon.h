#pragma once

#include "Algebra/import.h"
#include "LineSegment2d.h"
#include "Line2d.h"
#include "Geometry/base/Points.h"
#include "Geometry/base/Ray.h"
#include <cstdint>
#include "Basic/base.h"

namespace math
{
	/**
	*	平面几何的多边形
	*/ 
	struct Polygon
	{
	public:
		Polygon();
		Polygon(const std::vector<math::Vector3>& points);
		Polygon(const std::vector<math::Vector2>& points);
		Polygon(const Polygon& polygon);

		virtual ~Polygon();
	public:
		/**
		*	获取顶点坐标
		*/
		const std::vector<math::Vector3>& getPoints() const;
		/**
		*	顶点数
		*/
		int getPointCount() const;
		/**
		*	获取坐标
		*/
		const math::Vector3& getPoint(int index) const;
		/**
		*	获取坐标
		*/
		math::Vector3& getPoint(int index);
		/**
		*	设置顶点坐标
		*/
		void setPoints(const std::vector<math::Vector3>& points);
		/**
		*	设置顶点坐标
		*/
		void setPoint(int index, const math::Vector3& point);
		/**
		*	是否包含点
		*/
		bool contains(const Vector2& point);

		/**
		*	点是否在内部
		*/
		bool includes(const Vector2& point);
		/**
		*	是否包含线段
		*/
		bool contains(const LineSegment2d& line);
		/**
		*	是否与线段相交
		*/
		bool intersects(const LineSegment2d& line);
		/**
		*	是否与多边形相交
		*/
		bool intersects(const Polygon& polygon);
		/**
		*	是否与射线相交
		*/
		bool rayHit(const Ray& ray, math::Vector3& point);
	public:
		/**
		*	重载=
		*/
		Polygon& operator=(const Polygon& polygon);
		/**
		*	重载[]
		*/
		math::Vector3& operator[](int index);
		/**
		*	重载[]
		*/
		const math::Vector3& operator[](int index) const;
	private:
		std::vector<math::Vector3> _points;
	};
}