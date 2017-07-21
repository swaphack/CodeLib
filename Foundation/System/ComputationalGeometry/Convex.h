#pragma once

#include "macros.h"
#include <vector>

namespace sys
{
	class VertexSet;
	/**
	*	凸包
	*/
	struct Convex
	{
	public:
		/**
		*	是否是凸包
		*/
		static bool isConvex(Vector2* points, int count);
		/**
		*	创建慢速凸包
		*	时间复杂度 n^3
		*/
		static bool makeSlowConvexHull(Vector2* points, int count, VertexSet& vertexes);
		/**
		*	创建快捷凸包
		*/
		static bool makeConvexHull(Vector2* points, int count, VertexSet& vertexes);
		/**
		*	按x轴排序
		*/
		static Vector2* sortByAxisX(Vector2* points, int count);
		/**
		*	按y轴排序
		*/
		static Vector2* sortByAxisY(Vector2* points, int count);
	};
}