#pragma once
#include "macros.h"

namespace render
{
	/**
	*	º∆À„
	*/
	class GLEvaluator
	{
	public:
		static void evalCoord1(float u);
		static void evalCoord2(float u, float v);
	public:
		static void evalMesh1(MeshMode mode, int i1, int i2);
		static void evalMesh2(MeshMode mode, int i1, int j1, int i2, int j2);
	public:
		static void evalPoint1(int i);
		static void evalPoint2(int i, int j);
	public:
		static void setMap1(MapTarget1 target, float u1, float u2, int stride, int order, const float* points);
		static void setMap2(MapTarget2 target, float u1, float u2, int ustride, int uorder, float v1, float v2, int vstride, int vorder, const float* points);
	public:
		static void setMapGrid1(int un, float u1, float u2);
		static void setMapGrid2(int un, float u1, float u2, int vn, float v1, float v2);
	};
}