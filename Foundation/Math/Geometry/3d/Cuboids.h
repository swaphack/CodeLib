#pragma once

#include "Algebra/import.h"
#include "Volume.h"

namespace math
{
	/**
	*	������
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
		*	���ò���
		*/
		void set(const Vector3& orgin, const Volume& size);
		/**
		*	������
		*/
		bool contains(float x, float y, float z) const;
		/**
		*	������
		*/
		bool contains(const Vector3& point) const;
		/**
		*	�����ص�
		*/
		bool isOverlap(const Cuboids& cuboids) const;
	public:
		Cuboids& operator=(const Cuboids& cuboids);
	private:
		/**
		*	�������
		*/
		Vector3 _origin;
		/**
		*	��С
		*/
		Volume _size;
	};
}