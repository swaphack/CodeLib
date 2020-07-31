#pragma once

#include "Algebra/import.h"
#include "Geometry/base/Line2.h"
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
			this->set(polygon.getValue());
		}
		Polygon(const math::Vector2* vpoints)
		{
			this->set(vpoints);
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
		bool contains(const Line2& line)
		{
			return false;
		}
		/**
		*	是否与线段相交
		*/
		bool intersects(const Line2& line)
		{
			return false;
		}
		/**
		*	是否与多边形相交
		*/
		bool intersects(const Polygon& polygon)
		{
			for (int32_t i = 0; i < polygon.getLength(); i++)
			{
				Line2 line(polygon[i], polygon[(i + 1) % polygon.getLength()]);
				if (this->intersects(line) || this->contains(line))
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
			this->set(polygon.getValue());
		}
	public:
		/**
		*	是否是标准的多边形，顶点数大于等于3,并且相邻不存在共线的情况
		*/
		static bool isStandard(const Polygon& polygon)
		{
			if (polygon.getLength() < 3)
			{
				return false;
			}

			int32_t lineCount = polygon.getLength();
			PointAndLinePositionType lastDirection = PointAndLinePositionType::NONE;
			for (int32_t i = 0; i < lineCount; i++)
			{
				Vector2 v0 = polygon[i % lineCount];
				Vector2 v1 = polygon[(i + 1) % lineCount];
				Vector2 v2 = polygon[(i + 1) % lineCount];
				Line2 line(v0, v1);
				PointAndLinePositionType eType = line.getPointPositionType(v2);
				if (eType == PointAndLinePositionType::INCLUDE)
				{
					return false;
				}

				if (lastDirection != PointAndLinePositionType::NONE)
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

			int32_t lineCount = polygon.getLength();
			PointAndLinePositionType lastDirection = PointAndLinePositionType::NONE;
			for (int32_t i = 0; i < lineCount; i++)
			{
				Vector2 v0 = polygon[i % lineCount];
				Vector2 v1 = polygon[(i + 1) % lineCount];
				Vector2 v2 = polygon[(i + 1) % lineCount];
				Line2 line(v0, v1);
				PointAndLinePositionType eType = line.getPointPositionType(v2);
				if (eType == PointAndLinePositionType::INCLUDE)
				{
					return false;
				}

				if (lastDirection != PointAndLinePositionType::NONE)
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