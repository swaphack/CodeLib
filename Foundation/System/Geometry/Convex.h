#pragma once

#include "macros.h"

namespace sys
{
	struct Polygon;
	/**
	*	͹��
	*/
	struct Convex
	{
	public:
		/**
		*	�ж��ɵ㹹�ɵ�͹�����
		*/
		static Polygon* createPolygon(Vector2* points, int count);
	};
}