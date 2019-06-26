#pragma once
#include "macros.h"

namespace sys
{
	struct Surface;
	/**
	*	多面体
	*/
	struct Polyhedron
	{
		// 面
		Surface* surfaces;
		// 面数
		int32 count;
		
		Polyhedron();
		Polyhedron(Surface* surfaces, int32 count);
		~Polyhedron();

		/**
		*	是否包含点
		*	各个坐标面的投影都包含点
		*/
		bool contiains(const Vector3& point32);
		/**
		*	两多面体是否相交
		*	
		*/
		bool int32ersects(const Polyhedron& polyhedron);
	};
}