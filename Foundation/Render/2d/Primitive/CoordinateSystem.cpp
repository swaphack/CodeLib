#include "CoordinateSystem.h"
#include "Common/Tool/VertexTool.h"
#include "physicslib.h"

render::CoordinateSystem::CoordinateSystem()
{

}

render::CoordinateSystem::~CoordinateSystem()
{

}

bool render::CoordinateSystem::init()
{
	if (!PrimitiveNode::init())
	{
		return false;
	}

	this->setDrawMode(DrawMode::LINES);

	return true;
}

void render::CoordinateSystem::onDrawNode2DBodyChange()
{
	render::CubeVertex cube;
	VertexTool::setTexture3DVertices(&cube, math::Vector3(), getVolume(), getAnchorPoint());

	this->removeAllPoints();
	this->appendPoint(cube.back.getRightBottomPosition(), phy::Color4F(1,0,0));
	this->appendPoint(cube.back.getLeftBottomPosition(), phy::Color4F(1, 0, 0));

	this->appendPoint(cube.back.getRightBottomPosition(), phy::Color4F(0, 1, 0));
	this->appendPoint(cube.front.getLeftBottomPosition(), phy::Color4F(0, 1, 0));

	this->appendPoint(cube.back.getRightBottomPosition(), phy::Color4F(0, 0, 1));
	this->appendPoint(cube.back.getRightTopPosition(), phy::Color4F(0, 0, 1));
}

void render::CoordinateSystem::onDrawNode2DColorChange()
{

}

