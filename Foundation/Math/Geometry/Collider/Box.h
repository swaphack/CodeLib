#pragma once

#include "Algebra/import.h"

#include <cstdint>

namespace math
{
	/**
	*	盒子
	*
	*
	*		   z
	*		   |
	*		   |_ _ _ x
	*		  /
	*		 /
	*		y
	*
    *   	2 - - - - 6  
	*		/       /|
	*	   / 	   / |
	*	 3 - - - - 7 |
	*	  |  0    |  / 4
	*	  |       | / 
	*	  |       |/
	*	 1 - - - - 5          
	*		
	*	v0(x0, y0, z0)	  
	*	v1(x0, y1, z0)
	*	v2(x0, y0, z1)
	*	v3(x0, y1, z1)
	*	v4(x1, y0, z0)
	*	v5(x1, y1, z0)
	*	v6(x1, y0, z1)
	*	v7(x1, y1, z1)
	*/
	struct Box
	{
	public:
		/**
		*	顶点数
		*/
		static const int32_t VERTICE_COUNT;
		/**
		*	面数
		*/
		static const int32_t SURFACE_COUNT;
		/**
		*	边数
		*/
		static const int32_t EDGE_COUNT;
		/**
		*	顶点索引
		*/
		static const int32_t VERTICE_INDEX[8];
	public:
		Vector3 Vertices[8];
	public:
		Box();
		~Box();
	public:
	};
}