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

		/**
		*	获取凸多边形
		*/
		static bool createConvexPolygon(const std::vector<math::Vector2>& inPoints, std::vector<math::Vector2>& outPoints)
		{
			if (inPoints.size() < 3)
			{
				return false;
			}

			std::vector<math::Vector2> points = inPoints;

			std::sort(points.begin(), points.end(), [](const math::Vector2& a, const math::Vector2& b) {
				if (a.getX() == b.getX())
				{
					return a.getY() > b.getY();
				}
				else
				{
					return a.getX() < b.getX();
				}

			});

			auto upList = std::vector<math::Vector2>();
			upList.push_back(points[0]);
			upList.push_back(points[1]);

			for (int i = 2; i < points.size(); i++)
			{
				upList.push_back(points[i]);
				while (upList.size() >= 3)
				{
					auto a = upList[upList.size() - 3];
					auto b = upList[upList.size() - 2];
					auto c = upList[upList.size() - 1];

					if (Vector2::getPointPosition(c, a, b) != 1)
					{
						upList.erase(upList.begin() + upList.size() - 2);
					}
					else
					{
						break;
					}
				}
			}

			auto lowerList = std::vector<math::Vector2>();
			lowerList.push_back(points[points.size() - 1]);
			lowerList.push_back(points[points.size() - 2]);

			for (int i = points.size() - 3; i >= 0; i--)
			{
				lowerList.push_back(points[i]);
				while (lowerList.size() >= 3)
				{
					auto a = lowerList[lowerList.size() - 3];
					auto b = lowerList[lowerList.size() - 2];
					auto c = lowerList[lowerList.size() - 1];
					if (Vector2::getPointPosition(c, a, b) != 1)
					{
						lowerList.erase(lowerList.begin() + lowerList.size() - 2);
					}
					else
					{
						break;
					}
				}
			}

			lowerList.erase(lowerList.begin());
			lowerList.erase(lowerList.begin() + lowerList.size() - 1);

			outPoints.insert(outPoints.end(), upList.begin(), upList.end());
			outPoints.insert(outPoints.end(), lowerList.begin(), lowerList.end());

			return outPoints.size() > 3;
		}
	};
}