#pragma once

#include "macros.h"
#include <vector>

namespace acg
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
		static bool isConvex(const sys::Vector2* points, int count);
		/**
		*	创建慢速凸包
		*	时间复杂度 n^3
		*/
		static bool makeSlowConvexHull(const sys::Vector2* points, int count, VertexSet& vertexes);
		/**
		*	创建快捷凸包
		*/
		static bool makeConvexHull(const sys::Vector2* points, int count, VertexSet& vertexes);
		/**
		*	按x轴排序
		*/
		static sys::Vector2* sortByAxisX(const sys::Vector2* points, int count);
		/**
		*	按y轴排序
		*/
		static sys::Vector2* sortByAxisY(const sys::Vector2* points, int count);
	};
}