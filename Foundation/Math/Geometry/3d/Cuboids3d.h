#pragma once

#include "Algebra/import.h"
#include "Volume.h"

namespace math
{
	/**
	*	长方体
	*/
	struct Cuboids3d
	{
	protected:
		/**
		*	起点坐标
		*/
		Vector3 _origin;
		/**
		*	大小
		*/
		Volume _size;
	public:
		Cuboids3d();
		Cuboids3d(const Vector3& origin, const Volume& size);
		Cuboids3d(const Cuboids3d& cuboids);
		virtual ~Cuboids3d();
	public:
		float getX() const;
		float getY() const;
		float getZ() const;
		float getWidth() const;
		float getHeight() const;
		float getDepth() const;
		float getMinX() const;
		float getMaxX() const;
		float getMinY() const;
		float getMaxY() const;
		float getMinZ() const;
		float getMaxZ() const;

		const Vector3& getOrigin() const;
		const Volume& getSize() const;
	public:
		/**
		*	设置参数
		*/
		void set(const Vector3& orgin, const Volume& size);
		/**
		*	包含点
		*/
		bool contains(float x, float y, float z);
		/**
		*	包含点
		*/
		bool contains(const Vector3& point);
		/**
		*	相交
		*/
		bool intersect(const Cuboids3d& cuboids);
	public:
		Cuboids3d& operator=(const Cuboids3d& cuboids);
	};
}