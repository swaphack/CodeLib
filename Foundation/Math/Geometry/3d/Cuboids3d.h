#pragma once

#include "Algebra/import.h"
#include "Volume.h"

namespace math
{
	/**
	*	������
	*/
	struct Cuboids3d
	{
	protected:
		/**
		*	�������
		*/
		Vector3 _origin;
		/**
		*	��С
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
		*	���ò���
		*/
		void set(const Vector3& orgin, const Volume& size);
		/**
		*	������
		*/
		bool contains(float x, float y, float z);
		/**
		*	������
		*/
		bool contains(const Vector3& point);
		/**
		*	�ཻ
		*/
		bool intersect(const Cuboids3d& cuboids);
	public:
		Cuboids3d& operator=(const Cuboids3d& cuboids);
	};
}