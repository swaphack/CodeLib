#pragma once

#include <cstdint>
#include "Algebra/import.h"

namespace math
{
	struct Surface;
	/**
	*	多面体
	*/
	struct Polyhedron
	{
	protected:
		// 面
		Surface* _surfaces = nullptr;
		// 面数
		int32_t _count = 0;
	public:
		Polyhedron();
		Polyhedron(Surface* surfaces, int32_t count);
		virtual ~Polyhedron();
	public:
		/**
		*	是否包含点
		*	各个坐标面的投影都包含点
		*/
		bool contiains(const Vector3& point);
		/**
		*	两多面体是否相交
		*	
		*/
		bool intersects(const Polyhedron& polyhedron);
	};
}