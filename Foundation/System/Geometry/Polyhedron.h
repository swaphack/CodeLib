#pragma once

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
		int count;
		
		Polyhedron();
		Polyhedron(Surface* surfaces, int count);
		~Polyhedron();

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