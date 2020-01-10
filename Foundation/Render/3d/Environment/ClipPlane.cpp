#include "ClipPlane.h"

using namespace render;


ClipPlane::ClipPlane()
{
	memset(_clipNormal, 0, 4 * sizeof(double));
}

ClipPlane::~ClipPlane()
{

}

void ClipPlane::draw()
{
	Node::draw();

	glClipPlane(getClipPlaneIndex(), _clipNormal);
	glEnable(getClipPlaneIndex());
}

void ClipPlane::setClipNormal(float x, float y, float z)
{
	_clipNormal[0] = x;
	_clipNormal[1] = y;
	_clipNormal[2] = z;
}

math::Vector3 ClipPlane::getClipNormal()
{
	return math::Vector3(static_cast<float>(_clipNormal[0]), static_cast<float>(_clipNormal[1]), static_cast<float>(_clipNormal[2]));
}
