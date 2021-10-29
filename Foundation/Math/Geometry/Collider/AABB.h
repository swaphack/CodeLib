#pragma once

#include "BoundingBox.h"
#include "Geometry/2d/LineSegment2d.h"
#include "Geometry/3d/LineSegment3d.h"

namespace math
{
	/**
	*	AABB碰撞盒
	*	axially aligned bounding box(轴对齐矩形边界框)
	*/
	class AABB : public BoundingBox
	{
	public:
		/**
		*	构造
		*/
		AABB(const Vector2& center, const Vector2& size);
		/**
		*	构造
		*/
		AABB(const Vector3& center, const Vector3& volume);
	public:
		/**
		*	最小坐标
		*/
		const Vector3& getMin() const;
		/**
		*	最大坐标
		*/
		const Vector3& getMax() const;
		/**
		*	体积
		*/
		const Vector3& getVolume() const;

		/**
		*	设置参数
		*/
		void set(const Vector2& center, const Vector2& size);
		/**
		*	设置参数
		*/
		void set(const Vector3& center, const Vector3& volume);
	public:
		/**
		*	是否包含点
		*/
		virtual bool contains(const Vector2& point32) const;
		/**
		*	是否包含点
		*/
		virtual bool contains(const Vector3& point32) const;
	public:
		/**
		*	是否包含线段
		*/
		bool contains(const LineSegment2d& line) const;
		/**
		*	是否包含线段
		*/
		bool contains(const LineSegment3d& line) const;
		/**
		*	是否与线段相交
		*/
		bool intersects(const LineSegment2d& line) const;
		/**
		*	是否与线段相交
		*/
		bool intersects(const LineSegment3d& line) const;
		/**
		*	是否包含盒子
		*/
		bool contains(const AABB& bounds) const;
		/**
		*	两盒子是否相交
		*/
		bool intersects(const AABB& bounds) const;
		/**
		*	重载=
		*/
		AABB& operator=(const AABB& aabb);
	public:
		/**
		*	是否与射线相交
		*/
		virtual bool hitRay(const Ray& ray) const;
	private:
		// 面积
		Vector3 _volume;
		// 最小坐标
		Vector3 _minPos;
		// 最大坐标
		Vector3 _maxPos;
	};
}