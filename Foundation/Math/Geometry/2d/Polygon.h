#pragma once

#include "Algebra/import.h"
#include "LineSegment2d.h"
#include "Line2d.h"
#include "Geometry/base/Points.h"
#include "Geometry/base/Ray.h"
#include <cstdint>
#include "Basic/base.h"
#include "Rect.h"

namespace math
{
	/**
	*	ƽ�漸�εĶ����
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
		*	��ȡ��������
		*/
		const std::vector<math::Vector3>& getPoints() const;
		/**
		*	������
		*/
		int getPointCount() const;
		/**
		*	��ȡ����
		*/
		const math::Vector3& getPoint(int index) const;
		/**
		*	��ȡ����
		*/
		math::Vector3& getPoint(int index);
		/**
		*	���ö�������
		*/
		void setPoints(const std::vector<math::Vector3>& points);
		/**
		*	���ö�������
		*/
		void setPoint(int index, const math::Vector3& point);
		/**
		*	�Ƿ������
		*/
		bool contains(const Vector2& point) const;

		/**
		*	���Ƿ����ڲ�
		*/
		bool includes(const Vector2& point) const;
		/**
		*	�Ƿ�����߶�
		*/
		bool contains(const LineSegment2d& line) const;
		/**
		*	�Ƿ����߶��ཻ
		*/
		bool intersects(const LineSegment2d& line) const;
		/**
		*	�Ƿ��������ཻ
		*/
		bool intersects(const Polygon& polygon) const;
		/**
		*	�Ƿ��������ཻ
		*/
		bool rayHit(const Ray& ray, math::Vector3& point) const;
		/**
		*	��Χ��
		*/
		math::Rect getBoundingBox() const;
	public:
		/**
		*	����=
		*/
		Polygon& operator=(const Polygon& polygon);
		/**
		*	����[]
		*/
		math::Vector3& operator[](int index);
		/**
		*	����[]
		*/
		const math::Vector3& operator[](int index) const;
	private:
		std::vector<math::Vector3> _points;
	};
}