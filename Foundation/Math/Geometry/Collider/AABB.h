#pragma once

#include "BoundingBox.h"
#include "Geometry/2d/LineSegment2d.h"
#include "Geometry/3d/LineSegment3d.h"

namespace math
{
	/**
	*	AABB��ײ��
	*	axially aligned bounding box(�������α߽��)
	*/
	struct AABB : public BoundingBox
	{
	public:
		/**
		*	����
		*/
		AABB(const Vector2& center, const Vector2& size);
		/**
		*	����
		*/
		AABB(const Vector3& center, const Vector3& volume);
	public:
		/**
		*	��С����
		*/
		const Vector3& getMin() const;
		/**
		*	�������
		*/
		const Vector3& getMax() const;
		/**
		*	���
		*/
		const Vector3& getVolume() const;

		/**
		*	���ò���
		*/
		void set(const Vector2& center, const Vector2& size);
		/**
		*	���ò���
		*/
		void set(const Vector3& center, const Vector3& volume);
	public:
		/**
		*	�Ƿ������
		*/
		virtual bool contains(const Vector2& point32);
		/**
		*	�Ƿ������
		*/
		virtual bool contains(const Vector3& point32);
	public:
		/**
		*	�Ƿ�����߶�
		*/
		bool contains(const LineSegment2d& line);
		/**
		*	�Ƿ�����߶�
		*/
		bool contains(const LineSegment3d& line);
		/**
		*	�Ƿ����߶��ཻ
		*/
		bool intersects(const LineSegment2d& line);
		/**
		*	�Ƿ����߶��ཻ
		*/
		bool intersects(const LineSegment3d& line);
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
	public:
		/**
		*	�Ƿ��������ཻ
		*/
		virtual bool hitRay(const Ray& ray) const;
	private:
		// ���
		Vector3 _volume;
		// ��С����
		Vector3 _minPos;
		// �������
		Vector3 _maxPos;
	};
}