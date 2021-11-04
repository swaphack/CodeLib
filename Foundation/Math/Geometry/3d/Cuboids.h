#pragma once

#include "Algebra/import.h"
#include "Volume.h"

namespace math
{
	/**
	*	长方体
	*/
	struct Cuboids
	{
	public:
		Cuboids();
		Cuboids(float x, float y, float z, float width, float height, float depth);
		Cuboids(const Vector3& origin, const Volume& size);
		Cuboids(const Cuboids& cuboids);
		virtual ~Cuboids();
	public:
		float getX() const;
		float getY() const;
		float getZ() const;
		float getWidth() const;
		float getHeight() const;
		float getDepth() const;
		float getHalfWidth() const;
		float getHalfHeight() const;
		float getHalfDepth() const;
		float getMinX() const;
		float getMiddleX() const;
		float getMaxX() const;
		float getMinY() const;
		float getMiddleY() const;
		float getMaxY() const;
		float getMinZ() const;
		float getMiddleZ() const;
		float getMaxZ() const;


		const Vector3& getOrigin() const;
		const Volume& getVolume() const;
	public:
		/**
		*	设置参数
		*/
		void set(const Vector3& orgin, const Volume& size);
		/**
		*	包含点
		*/
		bool contains(float x, float y, float z) const;
		/**
		*	包含点
		*/
		bool contains(const Vector3& point) const;
		/**
		*	部分重叠
		*/
		bool isOverlap(const Cuboids& cuboids) const;
	public:
		Cuboids& operator=(const Cuboids& cuboids);
	private:
		/**
		*	起点坐标
		*/
		Vector3 _origin;
		/**
		*	大小
		*/
		Volume _size;
	};
}