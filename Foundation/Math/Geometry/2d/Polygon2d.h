#pragma once

#include "Algebra/import.h"
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
	struct Polygon2d : public Points<math::Vector2, Length>
	{
	public:
		Polygon2d() {}
		Polygon2d(const Polygon2d& polygon)
		{
			this->set(polygon.getValue());
		}
		Polygon2d(const math::Vector2* vpoints)
		{
			this->set(vpoints);
		}

		virtual ~Polygon2d() {}
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
		bool contains(const Line2d& line)
		{
			return false;
		}
		/**
		*	�Ƿ����߶��ཻ
		*/
		bool intersects(const Line2d& line)
		{
			return false;
		}
		/**
		*	�Ƿ��������ཻ
		*/
		bool intersects(const Polygon2d& polygon)
		{
			for (int32_t i = 0; i < polygon.getLength(); i++)
			{
				Line2d line(polygon[i], polygon[(i + 1) % polygon.getLength()]);
				if (this->intersects(line) || this->contains(line))
				{
					return true;
				}
			}

			return false;
		}
		/**
		*	����=
		*/
		Polygon2d& operator=(const Polygon2d& polygon)
		{
			this->set(polygon.getValue());
		}
	public:
		/**
		*	�Ƿ��Ǳ�׼�Ķ���Σ����������ڵ���3,�������ڲ����ڹ��ߵ����
		*/
		static bool isStandard(const Polygon2d& polygon)
		{
			if (polygon.getLength() < 3)
			{
				return false;
			}

			int32_t lineCount = polygon.getLength();
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
		static bool isConvex(const Polygon2d& polygon)
		{
			if (!isStandard(polygon))
			{
				return false;
			}

			int32_t lineCount = polygon.getLength();
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