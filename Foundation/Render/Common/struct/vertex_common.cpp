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

void RectVertex::setLeftBottomPosition(const math::Vector3& point)
{
	int index = 0;
	memcpy(vertices + index, point.getValue(), point.getSize());
}

math::Vector3 render::RectVertex::getLeftBottomPosition() const
{ 
	return math::Vector3(vertices); 
}

void RectVertex::setRightBottomPosition(const math::Vector3& point)
{
	int index = 3;
	memcpy(vertices + index, point.getValue(), point.getSize());
}

math::Vector3 render::RectVertex::getRightBottomPosition() const
{ 
	return math::Vector3(vertices + 3); 
}

void RectVertex::setRightTopPosition(const math::Vector3& point)
{
	int index = 6;
	memcpy(vertices + index, point.getValue(), point.getSize());
}

math::Vector3 render::RectVertex::getRightTopPosition() const
{ 
	return math::Vector3(vertices + 6);
}

void RectVertex::setLeftTopPosition(const math::Vector3& point)
{
	int index = 9;
	memcpy(vertices + index, point.getValue(), point.getSize());
}

math::Vector3 render::RectVertex::getLeftTopPosition() const
{ 
	return math::Vector3(vertices + 9); 
}

void RectVertex::setLeftDownColor(const phy::Color4F& color)
{
	int index = 0;
	memcpy(colors + index, color.getValue(), color.getSize());
}

void RectVertex::setRightDownColor(const phy::Color4F& color)
{
	int index = 4;
	memcpy(colors + index, color.getValue(), color.getSize());
}

void RectVertex::setRightUpColor(const phy::Color4F& color)
{
	int index = 8;
	memcpy(colors + index, color.getValue(), color.getSize());
}

void RectVertex::setLeftUpColor(const phy::Color4F& color)
{
	int index = 12;
	memcpy(colors + index, color.getValue(), color.getSize());
}

void render::RectVertex::setColor(const phy::Color4F& color)
{
	memcpy(colors + 0, color.getValue(), color.getSize());
	memcpy(colors + 4, color.getValue(), color.getSize());
	memcpy(colors + 8, color.getValue(), color.getSize());
	memcpy(colors + 12, color.getValue(), color.getSize());
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

void render::RectVertex::toTriangles(std::vector<math::TrianglePoints>& trianglePoints) const
{
	trianglePoints.push_back(math::TrianglePoints(getLeftBottomPosition(), getRightBottomPosition(), getRightTopPosition()));
	trianglePoints.push_back(math::TrianglePoints(getLeftBottomPosition(), getRightTopPosition(), getLeftTopPosition()));
}

render::RectVertex::operator math::Polygon() const
{
	std::vector<math::Vector3> points;
	points.push_back(getLeftBottomPosition());
	points.push_back(getRightBottomPosition());
	points.push_back(getRightTopPosition());
	points.push_back(getLeftTopPosition());

	math::Polygon polygon(points);
	return polygon;
}

//////////////////////////////////////////////////////////////////////////

CubeVertex::CubeVertex()
{
	
}

void CubeVertex::setFrontLeftBottomPosition(const math::Vector3& point)
{
	front.setLeftBottomPosition(point);
	left.setRightBottomPosition(point);
	bottom.setLeftTopPosition(point);
}

void CubeVertex::setFrontRightButtomPosition(const math::Vector3& point)
{
	front.setRightBottomPosition(point);
	right.setLeftBottomPosition(point);
	bottom.setRightTopPosition(point);
}

void CubeVertex::setFrontRightTopPosition(const math::Vector3& point)
{
	front.setRightTopPosition(point);
	right.setLeftTopPosition(point);
	top.setRightBottomPosition(point);
}

void CubeVertex::setFrontLeftTopPosition(const math::Vector3& point)
{
	front.setLeftTopPosition(point);
	left.setRightTopPosition(point);
	top.setLeftBottomPosition(point);
}

void CubeVertex::setBackLeftBottomPosition(const math::Vector3& point)
{
	back.setLeftBottomPosition(point);
	right.setRightBottomPosition(point);
	bottom.setRightBottomPosition(point);
}

void CubeVertex::setBackRightBottomPosition(const math::Vector3& point)
{
	back.setRightBottomPosition(point);
	left.setLeftBottomPosition(point);
	bottom.setLeftBottomPosition(point);
}

void CubeVertex::setBackRightTopPosition(const math::Vector3& point)
{
	back.setRightTopPosition(point);
	left.setLeftTopPosition(point);
	top.setLeftTopPosition(point);
}

void CubeVertex::setBackLeftTopPosition(const math::Vector3& point)
{
	back.setLeftTopPosition(point);
	right.setRightTopPosition(point);
	top.setRightTopPosition(point);
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


