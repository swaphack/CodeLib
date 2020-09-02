#include "CoordinateSystem.h"
#include "Common/Tool/Tool.h"

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

	_notify->addListen(NodeNotifyType::SPACE, [this]() {
		this->onCoordianteSystemBodyChange();
	});
	return true;
}

void render::CoordinateSystem::onCoordianteSystemBodyChange()
{
	CubeVectices cube;
	Tool::calCube(getPosition(), getVolume(), getAnchorPoint(), cube);

	this->removeAllPoints();
	this->appendPoint(cube.back.leftDown, sys::Color4B(255, 255, 255));
	this->appendPoint(cube.back.rightDown, sys::Color4B(255, 255, 255));

	this->appendPoint(cube.back.leftDown, sys::Color4B(255, 255, 255));
	this->appendPoint(cube.back.leftUp, sys::Color4B(255, 255, 255));

	this->appendPoint(cube.back.leftDown, sys::Color4B(255, 255, 255));
	this->appendPoint(cube.front.rightDown, sys::Color4B(255, 255, 255));
}

