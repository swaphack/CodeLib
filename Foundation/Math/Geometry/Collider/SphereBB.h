#pragma once

#include "BoundingBox.h"
#include "Geometry/2d/LineSegment2d.h"
#include "Geometry/3d/LineSegment3d.h"

namespace math
{
	/**
	*	球包围盒
	*/
	struct SphereBB : public BoundingBox
	{
	public:
		/**
		*	构造
		*/
		SphereBB(const Vector2& center, float radius);
		/**
		*	构造
		*/
		SphereBB(const Vector3& center, float radius);
	public:
		/**
		*	半径
		*/
		const float& getRadius() const;
		/**
		*	设置参数
		*/
		void set(const Vector2& center, float radius);
		/**
		*	设置参数
		*/
		void set(const Vector3& center, float radius);
	public:
		/**
		*	是否包含点
		*/
		virtual bool contains(const Vector2& point);
		/**
		*	是否包含点
		*/
		virtual bool contains(const Vector3& point);
	protected:
		// 半径
		float _radius = 0;
	};
}
