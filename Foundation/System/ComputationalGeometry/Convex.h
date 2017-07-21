#pragma once

#include "macros.h"
#include <vector>

namespace sys
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
		static bool isConvex(Vector2* points, int count);
		/**
		*	��������͹��
		*	ʱ�临�Ӷ� n^3
		*/
		static bool makeSlowConvexHull(Vector2* points, int count, VertexSet& vertexes);
		/**
		*	�������͹��
		*/
		static bool makeConvexHull(Vector2* points, int count, VertexSet& vertexes);
		/**
		*	��x������
		*/
		static Vector2* sortByAxisX(Vector2* points, int count);
		/**
		*	��y������
		*/
		static Vector2* sortByAxisY(Vector2* points, int count);
	};
}