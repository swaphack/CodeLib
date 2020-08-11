#include "vertex_common.h"
#include "enum_common.h"

using namespace render;

Vertex::Vertex()
{
	normal = math::Vector3(0, 0, 1);
}
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
RectVertex::RectVertex()
{
	uvs[0] = 0; uvs[1] = 0;
	uvs[2] = 1; uvs[3] = 0;
	uvs[4] = 1; uvs[5] = 1;
	uvs[6] = 0; uvs[7] = 1;

	indices[0] = 0; indices[1] = 1; indices[2] = 2;
	indices[3] = 0; indices[4] = 2; indices[5] = 3;

	for (int i = 0; i < 16; i++)
	{
		colors[i] = 1;
	}

	for (int i = 0; i < 12; i++)
	{
		vertices[i] = 0;
	}
}

void RectVertex::setLeftDownPoint(const math::Vector3& point)
{
	int index = 0;
	memcpy(vertices + index, point.getValue(), point.getSize());
}

void RectVertex::setRightDownPoint(const math::Vector3& point)
{
	int index = 3;
	memcpy(vertices + index, point.getValue(), point.getSize());
}

void RectVertex::setRightUpPoint(const math::Vector3& point)
{
	int index = 6;
	memcpy(vertices + index, point.getValue(), point.getSize());
}

void RectVertex::setLeftUpPoint(const math::Vector3& point)
{
	int index = 9;
	memcpy(vertices + index, point.getValue(), point.getSize());
}

void RectVertex::setLeftDownColor(const sys::Color4F& color)
{
	int index = 0;
	colors[index + 0] = color.red;
	colors[index + 1] = color.green;
	colors[index + 2] = color.blue;
	colors[index + 3] = color.alpha;
}

void RectVertex::setRightDownColor(const sys::Color4F& color)
{
	int index = 4;
	colors[index + 0] = color.red;
	colors[index + 1] = color.green;
	colors[index + 2] = color.blue;
	colors[index + 3] = color.alpha;
}

void RectVertex::setRightUpColor(const sys::Color4F& color)
{
	int index = 8;
	colors[index + 0] = color.red;
	colors[index + 1] = color.green;
	colors[index + 2] = color.blue;
	colors[index + 3] = color.alpha;
}

void RectVertex::setLeftUpColor(const sys::Color4F& color)
{
	int index = 12;
	colors[index + 0] = color.red;
	colors[index + 1] = color.green;
	colors[index + 2] = color.blue;
	colors[index + 3] = color.alpha;
}

void RectVertex::setLeftDownUV(const math::Vector2& point)
{
	int index = 0;
	memcpy(uvs + index, point.getValue(), point.getSize());
}

void RectVertex::setRightDownUV(const math::Vector2& point)
{
	int index = 2;
	memcpy(uvs + index, point.getValue(), point.getSize());
}

void RectVertex::setRightUpUV(const math::Vector2& point)
{
	int index = 4;
	memcpy(uvs + index, point.getValue(), point.getSize());
}

void RectVertex::setLeftUpUV(const math::Vector2& point)
{
	int index = 6;
	memcpy(uvs + index, point.getValue(), point.getSize());
}

//////////////////////////////////////////////////////////////////////////

CubeVertex::CubeVertex()
{
	
}

void CubeVertex::setFrontLeftDownPosition(const math::Vector3& point)
{
	front.setLeftDownPoint(point);
	left.setRightDownPoint(point);
	bottom.setLeftUpPoint(point);
}

void CubeVertex::setFrontRightDownPosition(const math::Vector3& point)
{
	front.setRightDownPoint(point);
	right.setLeftDownPoint(point);
	bottom.setRightUpPoint(point);
}

void CubeVertex::setFrontRightUpPosition(const math::Vector3& point)
{
	front.setRightUpPoint(point);
	right.setLeftUpPoint(point);
	top.setRightDownPoint(point);
}

void CubeVertex::setFrontLeftUpPosition(const math::Vector3& point)
{
	front.setLeftUpPoint(point);
	left.setRightUpPoint(point);
	top.setLeftDownPoint(point);
}

void CubeVertex::setBackLeftDownPosition(const math::Vector3& point)
{
	back.setLeftDownPoint(point);
	right.setRightDownPoint(point);

	bottom.setRightDownPoint(point);
}

void CubeVertex::setBackRightDownPosition(const math::Vector3& point)
{
	back.setRightDownPoint(point);
	left.setLeftDownPoint(point);

	bottom.setLeftDownPoint(point);
}

void CubeVertex::setBackRightUpPosition(const math::Vector3& point)
{
	back.setRightUpPoint(point);
	left.setLeftUpPoint(point);
	top.setLeftUpPoint(point);
}

void CubeVertex::setBackLeftUpPosition(const math::Vector3& point)
{
	back.setLeftUpPoint(point);
	right.setRightUpPoint(point);

	top.setRightUpPoint(point);
}

const RectVertex* render::CubeVertex::getFaceVertex(CubeFace face) const
{
	switch (face)
	{
	case render::CubeFace::RIGHT:
		return &right;
		break;
	case render::CubeFace::LEFT:
		return &left;
		break;
	case render::CubeFace::TOP:
		return &top;
		break;
	case render::CubeFace::BOTTOM:
		return &bottom;
		break;
	case render::CubeFace::FRONT:
		return &front;
		break;
	case render::CubeFace::BACK:
		return &back;
		break;
	default:
		break;
	}
	return nullptr;
}

const render::RectVertex* render::CubeVertex::getCubMapFaceVertex(CubeFace face) const
{
	switch (face)
	{
	case render::CubeFace::RIGHT:
		return &right;
		break;
	case render::CubeFace::LEFT:
		return &left;
		break;
	case render::CubeFace::TOP:
		return &top;
		break;
	case render::CubeFace::BOTTOM:
		return &bottom;
		break;
	case render::CubeFace::FRONT:
		return &back;
		break;
	case render::CubeFace::BACK:
		return &front;
		break;
	default:
		break;
	}
	return nullptr;
}
