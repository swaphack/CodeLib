#include "CoordinateSystem.h"
#include "Common/Tool/Tool.h"
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
	CubePoints cube;
	Tool::calCube(getPosition(), getVolume(), getAnchorPoint(), cube);

	this->removeAllPoints();
	this->appendPoint(cube.back.leftDown, phy::Color4B(255, 255, 255));
	this->appendPoint(cube.back.rightDown, phy::Color4B(255, 255, 255));

	this->appendPoint(cube.back.leftDown, phy::Color4B(255, 255, 255));
	this->appendPoint(cube.back.leftUp, phy::Color4B(255, 255, 255));

	this->appendPoint(cube.back.leftDown, phy::Color4B(255, 255, 255));
	this->appendPoint(cube.front.rightDown, phy::Color4B(255, 255, 255));
}

