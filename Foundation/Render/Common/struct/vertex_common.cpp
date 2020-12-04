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

void RectVertex::setLeftDownColor(const phy::Color4F& color)
{
	int index = 0;
	colors[index + 0] = color[0];
	colors[index + 1] = color[1];
	colors[index + 2] = color[2];
	colors[index + 3] = color[3];
}

void RectVertex::setRightDownColor(const phy::Color4F& color)
{
	int index = 4;
	colors[index + 0] = color[0];
	colors[index + 1] = color[1];
	colors[index + 2] = color[2];
	colors[index + 3] = color[3];
}

void RectVertex::setRightUpColor(const phy::Color4F& color)
{
	int index = 8;
	colors[index + 0] = color[0];
	colors[index + 1] = color[1];
	colors[index + 2] = color[2];
	colors[index + 3] = color[3];
}

void RectVertex::setLeftUpColor(const phy::Color4F& color)
{
	int index = 12;
	colors[index + 0] = color[0];
	colors[index + 1] = color[1];
	colors[index + 2] = color[2];
	colors[index + 3] = color[3];
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

//////////////////////////////////////////////////////////////////////////
render::SimpleScale9Vertex::SimpleScale9Vertex()
{
	memset(vertices, 0, 48 * sizeof(float));
	memset(uvs, 0, 32 * sizeof(float));
	memset(indices, 0, 54 * sizeof(uint32_t));

	for (int i = 0; i < 64; i++)
	{
		colors[i] = 1;
	}

	uint32_t index[54] = {
		0,1,5,
		0,5,4,
		1,2,6,
		1,6,5,
		2,3,7,
		2,7,6,
		4,5,9,
		4,9,8,
		5,6,10,
		5,10,9,
		6,7,11,
		6,11,10,
		8,9,13,
		8,13,12,
		9,10,14,
		9,14,13,
		10,11,15,
		10,15,14
	};
	
	memcpy(indices, index, 54 * sizeof(uint32_t));
}

void render::SimpleScale9Vertex::setLayerPoints0(const math::Vector3& p0, const math::Vector3& p1, const math::Vector3& p2, const math::Vector3& p3)
{
	int index = 0;
	memcpy(vertices + index, p0.getValue(), p0.getSize());

	index = 3;
	memcpy(vertices + index, p1.getValue(), p1.getSize());

	index = 6;
	memcpy(vertices + index, p2.getValue(), p2.getSize());

	index = 9;
	memcpy(vertices + index, p3.getValue(), p3.getSize());
}

void render::SimpleScale9Vertex::setLayerPoints1(const math::Vector3& p0, const math::Vector3& p1, const math::Vector3& p2, const math::Vector3& p3)
{
	int index = 12;
	memcpy(vertices + index, p0.getValue(), p0.getSize());

	index = 15;
	memcpy(vertices + index, p1.getValue(), p1.getSize());

	index = 18;
	memcpy(vertices + index, p2.getValue(), p2.getSize());

	index = 21;
	memcpy(vertices + index, p3.getValue(), p3.getSize());
}

void render::SimpleScale9Vertex::setLayerPoints2(const math::Vector3& p0, const math::Vector3& p1, const math::Vector3& p2, const math::Vector3& p3)
{
	int index = 24;
	memcpy(vertices + index, p0.getValue(), p0.getSize());

	index = 27;
	memcpy(vertices + index, p1.getValue(), p1.getSize());

	index = 30;
	memcpy(vertices + index, p2.getValue(), p2.getSize());

	index = 33;
	memcpy(vertices + index, p3.getValue(), p3.getSize());
}

void render::SimpleScale9Vertex::setLayerPoints3(const math::Vector3& p0, const math::Vector3& p1, const math::Vector3& p2, const math::Vector3& p3)
{
	int index = 36;
	memcpy(vertices + index, p0.getValue(), p0.getSize());

	index = 39;
	memcpy(vertices + index, p1.getValue(), p1.getSize());

	index = 42;
	memcpy(vertices + index, p2.getValue(), p2.getSize());

	index = 45;
	memcpy(vertices + index, p3.getValue(), p3.getSize());
}

void render::SimpleScale9Vertex::setLayerUVs0(const math::Vector2& p0, const math::Vector2& p1, const math::Vector2& p2, const math::Vector2& p3)
{
	int index = 0;
	memcpy(uvs + index, p0.getValue(), p0.getSize());

	index = 2;
	memcpy(uvs + index, p1.getValue(), p1.getSize());

	index = 4;
	memcpy(uvs + index, p2.getValue(), p2.getSize());

	index = 6;
	memcpy(uvs + index, p3.getValue(), p3.getSize());
}

void render::SimpleScale9Vertex::setLayerUVs1(const math::Vector2& p0, const math::Vector2& p1, const math::Vector2& p2, const math::Vector2& p3)
{
	int index = 8;
	memcpy(uvs + index, p0.getValue(), p0.getSize());

	index = 10;
	memcpy(uvs + index, p1.getValue(), p1.getSize());

	index = 12;
	memcpy(uvs + index, p2.getValue(), p2.getSize());

	index = 14;
	memcpy(uvs + index, p3.getValue(), p3.getSize());
}

void render::SimpleScale9Vertex::setLayerUVs2(const math::Vector2& p0, const math::Vector2& p1, const math::Vector2& p2, const math::Vector2& p3)
{
	int index = 16;
	memcpy(uvs + index, p0.getValue(), p0.getSize());

	index = 18;
	memcpy(uvs + index, p1.getValue(), p1.getSize());

	index = 20;
	memcpy(uvs + index, p2.getValue(), p2.getSize());

	index = 22;
	memcpy(uvs + index, p3.getValue(), p3.getSize());
}

void render::SimpleScale9Vertex::setLayerUVs3(const math::Vector2& p0, const math::Vector2& p1, const math::Vector2& p2, const math::Vector2& p3)
{
	int index = 24;
	memcpy(uvs + index, p0.getValue(), p0.getSize());

	index = 26;
	memcpy(uvs + index, p1.getValue(), p1.getSize());

	index = 28;
	memcpy(uvs + index, p2.getValue(), p2.getSize());

	index = 30;
	memcpy(uvs + index, p3.getValue(), p3.getSize());
}


