#pragma once

#include "BoundingBox.h"
#include "Geometry/2d/LineSegment2d.h"
#include "Geometry/3d/LineSegment3d.h"
#include "SphereBB.h"

namespace math
{
	/**
	*	OBB碰撞盒
	*	oriented bounding box(方向矩形边界框)
	*	
	*/
	class OBB : public BoundingBox
	{
	public:
		/**
		*	构造
		*/
		OBB(const Vector3& center, const Vector3& volume, const Vector3& rotation);
		/**
		*	构造
		*/
		OBB(const Vector3& center, const Vector3& volume);
	public:
		/**
		*	体积
		*/
		const Vector3& getVolume() const;
		/**
		*	旋转
		*/
		const Vector3& getRotation() const;
		/**
		*	设置参数
		*/
		void set(const Vector3& center, const Vector3& size, const Vector3& rotation);
		/**
		*	设置参数
		*/
		void set(const Vector3& center, const Vector3& size);
	public:
		/**
		*	是否包含点
		*/
		virtual bool contains(const Vector2& point) const;
		/**
		*	是否包含点
		*/
		virtual bool contains(const Vector3& point) const;
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
		*	重载=
		*/
		OBB& operator=(const OBB& obb);
	public:
		/**
		*	是否与射线相交
		*/
		virtual bool hitRay(const Ray& ray) const;
	protected:
		// 体积
		Vector3 _volume;
		// 旋转角度
		Vector3 _rotation;
	};
}