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
	*	ƽ�漸�εĶ����
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
		*	�Ƿ������
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

				// ˮƽ
				if (p0.getY() == p1.getY()) continue;

				// �����ӳ�����
				if (point.getY() < MIN(p0.getY(), p1.getY())) continue;
				if (point.getY() >= MAX(p0.getY(), p1.getY())) continue;

				// ��� y=point.getY() �� p0p1 �Ľ���
				float x = (point.getY() - p0.getY()) * (p1.getX() - p0.getX()) / (p1.getY() - p0.getY()) + p0.getX();
				if (x > point.getX()) sum++;
			}

			return sum % 2 == 1;
		}
		/**
		*	�Ƿ�����߶�
		*/
		bool contains(const LineSegment2d& line)
		{
			bool one = contains(line.getSrc());
			bool two = contains(line.getDest());
			return one && two;
		}
		/**
		*	�Ƿ����߶��ཻ
		*/
		bool intersects(const LineSegment2d& line)
		{
			bool one = contains(line.getSrc());
			bool two = contains(line.getDest());
			return (one && ! two) || (!one && two);
		}
		/**
		*	�Ƿ��������ཻ
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
		*	����=
		*/
		Polygon& operator=(const Polygon& polygon)
		{
			this->assign(polygon.getValue());
		}
	public:
		/**
		*	�Ƿ��Ǳ�׼�Ķ���Σ����������ڵ���3,�������ڲ����ڹ��ߵ����
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
		*	�Ƿ���͹�����
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