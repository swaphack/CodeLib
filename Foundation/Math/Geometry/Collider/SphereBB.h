#pragma once

#include "BoundingBox.h"
#include "Geometry/2d/LineSegment2d.h"
#include "Geometry/3d/LineSegment3d.h"

namespace math
{
	/**
	*	���Χ��
	*/
	struct SphereBB : public BoundingBox
	{
	public:
		/**
		*	����
		*/
		SphereBB(const Vector2& center, float radius);
		/**
		*	����
		*/
		SphereBB(const Vector3& center, float radius);
	public:
		/**
		*	�뾶
		*/
		const float& getRadius() const;
		/**
		*	���ò���
		*/
		void set(const Vector2& center, float radius);
		/**
		*	���ò���
		*/
		void set(const Vector3& center, float radius);
	public:
		/**
		*	�Ƿ������
		*/
		virtual bool contains(const Vector2& point);
		/**
		*	�Ƿ������
		*/
		virtual bool contains(const Vector3& point);
	protected:
		// �뾶
		float _radius = 0;
	};
}
