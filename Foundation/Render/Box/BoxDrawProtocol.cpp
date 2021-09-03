#include "BoxDrawProtocol.h"
#include "Graphic/import.h"
#include "BoxDraw.h"

render::BoxDrawProtocol::BoxDrawProtocol()
{

}

render::BoxDrawProtocol::~BoxDrawProtocol()
{

}

void render::BoxDrawProtocol::setBoxVisible(bool bVisible)
{
	if (_bBoxVisible == bVisible) return;

	_bBoxVisible = bVisible;

	if (BoxDraw::getInstance() == nullptr) 
		return;

	if (bVisible)
	{
		BoxDraw::getInstance()->addBox(this);
	}
	else
	{
		BoxDraw::getInstance()->removeBox(this);
	}
}

bool render::BoxDrawProtocol::isBoxVisible() const
{
	return _bBoxVisible;
}

void render::BoxDrawProtocol::setBoxColor(const phy::Color4B& color)
{
	_boxColor = color;
}

const phy::Color4B& render::BoxDrawProtocol::getBoxColor() const
{
	return _boxColor;
}

float render::BoxDrawProtocol::getBoxLineWidth() const
{
	return _boxLineWidth;
}

void render::BoxDrawProtocol::setBoxLineWidth(float width)
{
	_boxLineWidth = width;
}

void render::BoxDrawProtocol::getBoxPoints(std::vector<math::TrianglePoints>& vecPoints) const
{
	vecPoints = _boxPoints;
}

/////////////////////////////////////////////////////////////////////////
render::Box2DDrawProtocol::Box2DDrawProtocol()
{

}

render::Box2DDrawProtocol::~Box2DDrawProtocol()
{

}
/*
void render::Box2DDrawProtocol::drawBox()
{
	if (!isBoxVisible())
	{
		return;
	}
	GLVertex::setColor(_boxColor);
	GLState::setLineWidth(_boxLineWidth);

	GLVertex::beginMode(ShapeMode::LINE_LOOP);
	GLVertex::setVertex(_boxVertex.getLeftBottom());
	GLVertex::setVertex(_boxVertex.getRightBottom());
	GLVertex::setVertex(_boxVertex.getRightTop());
	GLVertex::setVertex(_boxVertex.getLeftTop());
	GLVertex::endMode();
}
*/
void render::Box2DDrawProtocol::setBoxVertices(const render::RectVertex& rectVertex)
{
	_boxPoints.clear();
	rectVertex.toTriangles(_boxPoints);
}

/////////////////////////////////////////////////////////////////////////
render::Box3DDrawProtocol::Box3DDrawProtocol()
{

}

render::Box3DDrawProtocol::~Box3DDrawProtocol()
{

}
void render::Box3DDrawProtocol::setBoxVertices(const render::CubeVertex& cubeVertex)
{
	math::RectPoints front;
	math::RectPoints back;

	front.setVertices(cubeVertex.front.vertices);
	front.setVertices(cubeVertex.back.vertices);

	_boxVertex.setPoints(front, back);

	_boxPoints.clear();
	cubeVertex.front.toTriangles(_boxPoints);
	cubeVertex.back.toTriangles(_boxPoints);
	cubeVertex.left.toTriangles(_boxPoints);
	cubeVertex.right.toTriangles(_boxPoints);
	cubeVertex.top.toTriangles(_boxPoints);
	cubeVertex.bottom.toTriangles(_boxPoints);
}
/*
void render::Box3DDrawProtocol::drawBox()
{
	if (!isBoxVisible())
	{
		return;
	}
	GLVertex::setColor(_boxColor);
	GLState::setLineWidth(_boxLineWidth);

	GLVertex::beginMode(ShapeMode::LINE_LOOP);
	GLVertex::setVertex(_boxVertex.getFrontLeftBottom());
	GLVertex::setVertex(_boxVertex.getFrontRightBottom());
	GLVertex::setVertex(_boxVertex.getFrontRightTop());
	GLVertex::setVertex(_boxVertex.getFrontLeftTop());
	GLVertex::endMode();

	GLVertex::beginMode(ShapeMode::LINE_LOOP);
	GLVertex::setVertex(_boxVertex.getBackLeftBottom());
	GLVertex::setVertex(_boxVertex.getBackRightBottom());
	GLVertex::setVertex(_boxVertex.getBackRightTop());
	GLVertex::setVertex(_boxVertex.getBackLeftTop());
	GLVertex::endMode();

	GLVertex::beginMode(ShapeMode::LINE_LOOP);
	GLVertex::setVertex(_boxVertex.getBackRightBottom());
	GLVertex::setVertex(_boxVertex.getFrontLeftBottom());
	GLVertex::setVertex(_boxVertex.getFrontLeftTop());
	GLVertex::setVertex(_boxVertex.getBackRightTop());
	GLVertex::endMode();

	GLVertex::beginMode(ShapeMode::LINE_LOOP);
	GLVertex::setVertex(_boxVertex.getFrontRightBottom());
	GLVertex::setVertex(_boxVertex.getBackLeftBottom());
	GLVertex::setVertex(_boxVertex.getBackLeftTop());
	GLVertex::setVertex(_boxVertex.getFrontRightTop());
	GLVertex::endMode();

	GLVertex::beginMode(ShapeMode::LINE_LOOP);
	GLVertex::setVertex(_boxVertex.getFrontLeftTop());
	GLVertex::setVertex(_boxVertex.getFrontRightTop());
	GLVertex::setVertex(_boxVertex.getBackLeftTop());
	GLVertex::setVertex(_boxVertex.getBackRightTop());
	GLVertex::endMode();

	GLVertex::beginMode(ShapeMode::LINE_LOOP);
	GLVertex::setVertex(_boxVertex.getBackRightBottom());
	GLVertex::setVertex(_boxVertex.getBackLeftBottom());
	GLVertex::setVertex(_boxVertex.getFrontRightBottom());
	GLVertex::setVertex(_boxVertex.getFrontLeftBottom());
	GLVertex::endMode();
}
*/

