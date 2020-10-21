#pragma once

#include "Algebra/import.h"

#include <cstdint>

namespace math
{
	/**
	*	包围盒
	*/
	struct BoundingBox
	{
	public:
		BoundingBox();
		BoundingBox(const Vector3& center);
		virtual ~BoundingBox();
	public:
		/**
		*	中心点
		*/
		void setCenter(const Vector3& center);
		/**
		*	中心点
		*/
		const Vector3& getCenter() const;
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
		// 中心点
		Vector3 _center;
	};
}