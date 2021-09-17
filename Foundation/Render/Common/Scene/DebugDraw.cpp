#include "DebugDraw.h"
#include "2d/Primitive/PrimitiveNode.h"
#include "Cameras.h"

static render::DebugDraw* sIntance = nullptr;

render::DebugDraw::DebugDraw()
{
	sIntance = this;
}

render::DebugDraw::~DebugDraw()
{
	sIntance = nullptr;
}

bool render::DebugDraw::init()
{
	if (!Node::init())
	{
		return false;
	}

	_drawNode = CREATE_NODE(PrimitiveNode);
	_drawNode->setDrawMode(DrawMode::LINES);
	this->addChild(_drawNode);

	return true;
}

void render::DebugDraw::cleanup()
{
	_drawNode->removeAllPoints();
}

void render::DebugDraw::drawW2LLine(const math::Vector3& src, const math::Vector3& dest, const phy::Color4F& color)
{
	math::Vector3 srcPos = _drawNode->convertWorldPostitionToLocal(src);
	math::Vector3 destPos = _drawNode->convertWorldPostitionToLocal(dest);

	this->drawLine(srcPos, destPos, color);
}

void render::DebugDraw::drawL2WLine(const math::Vector3& src, const math::Vector3& dest, const phy::Color4F& color)
{
	math::Vector3 srcPos = _drawNode->convertLocalPostitionToWorld(src);
	math::Vector3 destPos = _drawNode->convertLocalPostitionToWorld(dest);

	this->drawLine(srcPos, destPos, color);
}

void render::DebugDraw::drawLine(const math::Vector3& src, const math::Vector3& dest, const phy::Color4F& color)
{
	_drawNode->appendPoint(src, color);
	_drawNode->appendPoint(dest, color);
}

void render::DebugDraw::drawOrtho(const ViewParameter& paramter, const phy::Color4F& color)
{
	math::Vector3 nearLeftBottom(paramter.xLeft, paramter.yBottom, paramter.zNear);
	math::Vector3 nearRightBottom(paramter.xRight, paramter.yBottom, paramter.zNear);
	math::Vector3 nearRightTop(paramter.xRight, paramter.yTop, paramter.zNear);
	math::Vector3 nearLeftTop(paramter.xLeft, paramter.yTop, paramter.zNear);

	math::Vector3 farLeftBottom(paramter.xLeft, paramter.yBottom, paramter.zFar);
	math::Vector3 farRightBottom(paramter.xRight, paramter.yBottom, paramter.zFar);
	math::Vector3 farRightTop(paramter.xRight, paramter.yTop, paramter.zFar);
	math::Vector3 farLeftTop(paramter.xLeft, paramter.yTop, paramter.zFar);

	this->drawLine(nearLeftBottom, nearRightBottom, color);
	this->drawLine(nearRightBottom, nearRightTop, color);
	this->drawLine(nearRightTop, nearLeftTop, color);
	this->drawLine(nearLeftTop, nearLeftBottom, color);

	this->drawLine(farLeftBottom, farRightBottom, color);
	this->drawLine(farRightBottom, farRightTop, color);
	this->drawLine(farRightTop, farLeftTop, color);
	this->drawLine(farLeftTop, farLeftBottom, color);

	this->drawLine(nearLeftBottom, farLeftBottom, color);
	this->drawLine(nearRightBottom, farRightBottom, color);
	this->drawLine(nearRightTop, farRightTop, color);
	this->drawLine(nearLeftTop, farLeftTop, color);
}

void render::DebugDraw::drawFrustum(const ViewParameter& paramter, const phy::Color4F& color)
{
	float zNear = -paramter.zNear;
	math::Vector3 nearLeftBottom(paramter.xLeft, paramter.yBottom, zNear);
	math::Vector3 nearRightBottom(paramter.xRight, paramter.yBottom, zNear);
	math::Vector3 nearRightTop(paramter.xRight, paramter.yTop, zNear);
	math::Vector3 nearLeftTop(paramter.xLeft, paramter.yTop, zNear);

	float k = paramter.zFar / paramter.zNear;

	math::Vector3 farLeftBottom = k * nearLeftBottom;
	math::Vector3 farRightBottom = k * nearRightBottom;
	math::Vector3 farRightTop = k * nearRightTop;
	math::Vector3 farLeftTop = k * nearLeftTop;

	this->drawLine(nearLeftBottom, nearRightBottom, color);
	this->drawLine(nearRightBottom, nearRightTop, color);
	this->drawLine(nearRightTop, nearLeftTop, color);
	this->drawLine(nearLeftTop, nearLeftBottom, color);

	this->drawLine(farLeftBottom, farRightBottom, color);
	this->drawLine(farRightBottom, farRightTop, color);
	this->drawLine(farRightTop, farLeftTop, color);
	this->drawLine(farLeftTop, farLeftBottom, color);

	this->drawLine(nearLeftBottom, farLeftBottom, color);
	this->drawLine(nearRightBottom, farRightBottom, color);
	this->drawLine(nearRightTop, farRightTop, color);
	this->drawLine(nearLeftTop, farLeftTop, color);
}

render::PrimitiveNode* render::DebugDraw::getRenderNode()
{
	return _drawNode;
}
