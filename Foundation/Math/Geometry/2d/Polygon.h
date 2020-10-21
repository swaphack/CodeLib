#pragma once

#include "Algebra/import.h"
#include "LineSegment2d.h"
#include "Line2d.h"
#include "Geometry/base/Points.h"
#include <cstdint>
#include "Basic/base.h"

namespace math
{
	/**
	*	平面几何的多边形
	*/ 
	template<const int Length>
	struct Polygon : public Points<math::Vector2, Length>
	{
	public:
		Polygon() {}
		Polygon(const Polygon& polygon)
		{
			this->assign(polygon.getValue());
		}
		Polygon(const math::Vector2* vpoints)
		{
			this->assign(vpoints);
		}

		virtual ~Polygon() {}
	public:
		/**
		*	是否包含点
		*/
		bool contains(const Vector2& point)
		{
			int32_t sum = 0;
			Vector2 p0;
			Vector2 p1;

			for (int32_t i = 0; i < Length; i++)
			{
				p0 = (*this)[i];
				p1 = (*this)[(i + 1) % Length];

				// 水平
				if (p0.getY() == p1.getY()) continue;

				// 在其延长线上
				if (point.getY() < MIN(p0.getY(), p1.getY())) continue;
				if (point.getY() >= MAX(p0.getY(), p1.getY())) continue;

				// 求解 y=point.getY() 与 p0p1 的交点
				float x = (point.getY() - p0.getY()) * (p1.getX() - p0.getX()) / (p1.getY() - p0.getY()) + p0.getX();
				if (x > point.getX()) sum++;
			}

			return sum % 2 == 1;
		}
		/**
		*	是否包含线段
		*/
		bool contains(const LineSegment2d& line)
		{
			bool one = contains(line.getSrc());
			bool two = contains(line.getDest());
			return one && two;
		}
		/**
		*	是否与线段相交
		*/
		bool intersects(const LineSegment2d& line)
		{
			bool one = contains(line.getSrc());
			bool two = contains(line.getDest());
			return (one && ! two) || (!one && two);
		}
		/**
		*	是否与多边形相交
		*/
		bool intersects(const Polygon& polygon)
		{
			for (int32_t i = 0; i < Length; i++)
			{
				LineSegment2d line(polygon[i], polygon[(i + 1) % polygon.getLength()]);
				if (this->intersects(line))
				{
					return true;
				}
			}

			return false;
		}
		/**
		*	重载=
		*/
		Polygon& operator=(const Polygon& polygon)
		{
			this->assign(polygon.getValue());
		}
	public:
		/**
		*	是否是标准的多边形，顶点数大于等于3,并且相邻不存在共线的情况
		*/
		static bool isStandard(const Polygon& polygon)
		{
			if (Length < 3)
			{
				return false;
			}

			int32_t lineCount = Length;
			PointAndLinePosition2DType lastDirection = PointAndLinePosition2DType::NONE;
			for (int32_t i = 0; i < lineCount; i++)
			{
				Vector2 v0 = polygon[i % lineCount];
				Vector2 v1 = polygon[(i + 1) % lineCount];
				Vector2 v2 = polygon[(i + 1) % lineCount];
				Line2d line(v0, v1);
				PointAndLinePosition2DType eType = line.getPointPositionType(v2);
				if (eType == PointAndLinePosition2DType::INCLUDE)
				{
					return false;
				}

				if (lastDirection != PointAndLinePosition2DType::NONE)
				{
					if (lastDirection != eType)
					{
						return false;
					}
				}
				else
				{
					lastDirection = eType;
				}
			}

			return true;
		}
		/**
		*	是否是凸多边形
		*/
		static bool isConvex(const Polygon& polygon)
		{
			if (!isStandard(polygon))
			{
				return false;
			}

			int32_t lineCount = Length;
			PointAndLinePosition2DType lastDirection = PointAndLinePosition2DType::NONE;
			for (int32_t i = 0; i < lineCount; i++)
			{
				Vector2 v0 = polygon[i % lineCount];
				Vector2 v1 = polygon[(i + 1) % lineCount];
				Vector2 v2 = polygon[(i + 1) % lineCount];
				Line2d line(v0, v1);
				PointAndLinePosition2DType eType = line.getPointPositionType(v2);
				if (eType == PointAndLinePosition2DType::INCLUDE)
				{
					return false;
				}

				if (lastDirection != PointAndLinePosition2DType::NONE)
				{
					if (lastDirection != eType)
					{
						return false;
					}
				}
				else
				{
					lastDirection = eType;
				}
			}

			return true;
		}
	};
}