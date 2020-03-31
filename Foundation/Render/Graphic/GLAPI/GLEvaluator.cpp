#include "GLEvaluator.h"

using namespace render;

void GLEvaluator::evalCoord1(float u)
{
	glEvalCoord1f(u);
}

void GLEvaluator::evalCoord2(float u, float v)
{
	glEvalCoord2f(u, v);
}

void GLEvaluator::evalMesh1(MeshMode mode, int i1, int i2)
{
	glEvalMesh1((GLenum)mode, i1, i2);
}

void GLEvaluator::evalMesh2(MeshMode mode, int i1, int j1, int i2, int j2)
{
	glEvalMesh2((GLenum)mode, i1, i2, j1, j2);
}

void GLEvaluator::evalPoint1(int i)
{
	glEvalPoint1(i);
}

void GLEvaluator::evalPoint2(int i, int j)
{
	glEvalPoint2(i, j);
}

void GLEvaluator::setMap1(MapTarget1 target, float u1, float u2, int stride, int order, const float* points)
{
	glMap1f((GLenum)target, u1, u2, stride, order, points);
}

void GLEvaluator::setMap2(MapTarget2 target, float u1, float u2, int ustride, int uorder, float v1, float v2, int vstride, int vorder, const float* points)
{
	glMap2f((GLenum)target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}

void GLEvaluator::setMapGrid1(int un, float u1, float u2)
{
	glMapGrid1f(un, u1, u2);
}

void GLEvaluator::setMapGrid2(int un, float u1, float u2, int vn, float v1, float v2)
{
	glMapGrid2f(un, u1, u2, vn, v1, v2);
}

