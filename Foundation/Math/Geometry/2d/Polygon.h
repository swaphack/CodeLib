#pragma once

#include "Algebra/import.h"
#include "Geometry/base/Line2.h"
#include <cstdint>

namespace math
{
	/**
	*	ƽ�漸�εĶ����
	*/ 
	struct Polygon
	{
	public:
		// ����
		Vector2* points;
		// ������
		int32_t count;
	public:
		Polygon();
		Polygon(const Polygon & polygon);
		Polygon(int32_t vcount, const Vector2* vpoints);

		virtual ~Polygon();
	public:
		void init(int32_t vcount, const Vector2* vpoints);
		/**
		*	�Ƿ������
		*/
		bool contains(const Vector2& point);
		/**
		*	�Ƿ�����߶�
		*/
		bool contains(const Line2& line);
		/**
		*	�Ƿ����߶��ཻ
		*/
		bool intersects(const Line2& line);
		/**
		*	�Ƿ��������ཻ
		*/
		bool intersects(const Polygon& polygon);
		/**
		*	����=
		*/
		Polygon& operator=(const Polygon& polygon);
	public:
		/**
		*	�Ƿ��Ǳ�׼�Ķ���Σ����������ڵ���3,�������ڲ����ڹ��ߵ����
		*/
		static bool isStandard(const Polygon& polygon);
		/**
		*	�Ƿ���͹�����
		*/
		static bool isConvex(const Polygon& polygon);
	};
}