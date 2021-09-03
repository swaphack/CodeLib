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

	addNotifyListener(NodeNotifyType::BODY, [this]() {
		this->onCoordianteSystemBodyChange();
	});
	return true;
}

void render::CoordinateSystem::onCoordianteSystemBodyChange()
{
	render::CubeVertex cube;
	VertexTool::setTexture3DVertices(&cube, getPosition(), getVolume(), getAnchorPoint());

	this->removeAllPoints();
	this->appendPoint(cube.front.getLeftBottomPosition());
	this->appendPoint(cube.front.getRightBottomPosition());

	this->appendPoint(cube.front.getLeftBottomPosition());
	this->appendPoint(cube.front.getLeftTopPosition());

	this->appendPoint(cube.front.getLeftBottomPosition());
	this->appendPoint(cube.back.getRightBottomPosition());
}

