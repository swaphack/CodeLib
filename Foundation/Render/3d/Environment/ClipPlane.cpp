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

sys::Vector ClipPlane::getClipNormal()
{
	return sys::Vector(static_cast<float>(_clipNormal[0]), static_cast<float>(_clipNormal[1]), static_cast<float>(_clipNormal[2]));
}
