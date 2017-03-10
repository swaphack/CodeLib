#pragma once

#include "macros.h"

namespace sys
{
	struct AABB;
	struct Line2;
	/**
	*	ƽ�漸�εĶ����
	*/ 
	struct Polygon
	{
		// ����
		Vector2* points;
		// ������
		int count;

		Polygon();
		Polygon(const Polygon & polygon);
		Polygon(Vector2* points, int count);

		~Polygon();
		/**
		*	��ȡ��Χ��
		*/
		AABB getBounds();
		/**
		*	��ȡ��Χ��
		*/
		AABB getBounds() const;
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