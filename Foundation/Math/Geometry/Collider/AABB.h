#pragma once

#include "Algebra/import.h"
#include "Geometry/2d/LineSegment2.h"
#include "Geometry/3d/LineSegment.h"

namespace math
{
	/**
	*	AABB��ײ��
	*	axially aligned bounding box(�������α߽��)
	*/
	struct AABB
	{
	private:
		// ���ĵ�
		Vector3 center;
		// ���
		Vector3 size;
		// ��С����
		Vector3 minPos;
		// �������
		Vector3 maxPos;
	public:
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
		bool contains(const Vector2& point32);
		/**
		*	�Ƿ������
		*/
		bool contains(const Vector3& point32);
		/**
		*	�Ƿ�����߶�
		*/
		bool contains(const LineSegment2& line);
		/**
		*	�Ƿ�����߶�
		*/
		bool contains(const LineSegment& line);
		/**
		*	�Ƿ����߶��ཻ
		*/
		bool intersects(const LineSegment2& line);
		/**
		*	�Ƿ����߶��ཻ
		*/
		bool intersects(const LineSegment& line);
		/**
		*	�Ƿ��������
		*/
		bool contains(const AABB& bounds);
		/**
		*	�������Ƿ��ཻ
		*/
		bool intersects(const AABB& bounds);
		/**
		*	��С����
		*/
		inline const Vector3& Min() const { return minPos;  }
		/**
		*	�������
		*/
		inline const Vector3& Max() const { return maxPos; }
		/**
		*	����=
		*/
		void operator=(const AABB& aabb);
	};
}