#pragma once

#include "macros.h"

namespace sys
{
	struct Line2;
	struct Line3;

	/**
	*	AABB��ײ��
	*	axially aligned bounding box(�������α߽��)
	*/
	struct AABB
	{
		// ���ĵ�
		Vector3 center;
		// ���
		Vector3 size;
		/**
		*	����
		*/
		AABB(const Vector2& center, const Vector2& size);
		/**
		*	����
		*/
		AABB(const Vector3& center, const Vector3& size);
		/**
		*	�Ƿ������
		*/
		bool contains(const Vector2& point);
		/**
		*	�Ƿ������
		*/
		bool contains(const Vector3& point);
		/**
		*	�Ƿ�����߶�
		*/
		bool contains(const Line2& line);
		/**
		*	�Ƿ�����߶�
		*/
		bool contains(const Line3& line);
		/**
		*	�Ƿ����߶��ཻ
		*/
		bool intersects(const Line2& line);
		/**
		*	�Ƿ����߶��ཻ
		*/
		bool intersects(const Line3& line);
		/**
		*	�Ƿ��������
		*/
		bool contains(const AABB& bounds);
		/**
		*	�������Ƿ��ཻ
		*/
		bool intersects(const AABB& bounds);

		/**
		*	����=
		*/
		void operator=(const AABB& aabb);

		/**
		*	x�����Сֵ
		*/
		float minX();
		/**
		*	y�����Сֵ
		*/
		float minY();
		/**
		*	z�����Сֵ
		*/
		float minZ();

		/**
		*	x������ֵ
		*/
		float maxX();
		/**
		*	y������ֵ
		*/
		float maxY();
		/**
		*	z������ֵ
		*/
		float maxZ();

		/**
		*	x�����Сֵ
		*/
		float minX() const;
		/**
		*	y�����Сֵ
		*/
		float minY() const;
		/**
		*	z�����Сֵ
		*/
		float minZ() const;

		/**
		*	x������ֵ
		*/
		float maxX() const;
		/**
		*	y������ֵ
		*/
		float maxY() const;
		/**
		*	z������ֵ
		*/
		float maxZ() const;
	};
}