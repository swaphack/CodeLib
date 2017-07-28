#pragma once

#include "macros.h"
#include <vector>

namespace acg
{
	class VertexSet;
	/**
	*	͹��
	*/
	struct Convex
	{
	public:
		/**
		*	�Ƿ���͹��
		*/
		static bool isConvex(const sys::Vector2* points, int count);
		/**
		*	��������͹��
		*	ʱ�临�Ӷ� n^3
		*/
		static bool makeSlowConvexHull(const sys::Vector2* points, int count, VertexSet& vertexes);
		/**
		*	�������͹��
		*/
		static bool makeConvexHull(const sys::Vector2* points, int count, VertexSet& vertexes);
		/**
		*	��x������
		*/
		static sys::Vector2* sortByAxisX(const sys::Vector2* points, int count);
		/**
		*	��y������
		*/
		static sys::Vector2* sortByAxisY(const sys::Vector2* points, int count);
	};
}